#include <SensorTask.h>

#define BOARD_ROTATION -PI/2.0f

SensorTask::SensorTask(AltimeterTask* altimeter, xSemaphoreHandle altimeterSemaphore, GpsTask* gpsTask) {
    this->loggingEnabled = false;
    this->boardRotationReferenceFrame = new Quaternion(0, 0, BOARD_ROTATION);
    this->imuReferenceFrame = new Quaternion(0, 0, 0);
    this->altimeter = altimeter;
    this->altimeterSemaphore = altimeterSemaphore;
    this->gpsTask = gpsTask;

    kinematics = new Kinematics();

    imuSampleQueue = xQueueCreate(1, sizeof(ImuSample));
    imu = new IMU(imuSampleQueue);
}

SensorTask::~SensorTask() {
    delete this->imuReferenceFrame;
    delete this->kinematics;
    delete this->imu;
    vQueueDelete(this->imuSampleQueue);
}

void SensorTask::init() {
}

Quaternion* SensorTask::getNewReferenceFrame() {
    return new Quaternion(*this->imuReferenceFrame);
}

void SensorTask::task() {
//    printf(NEWLINE "Sensor loop started." NEWLINE);
    ImuSample imuSample = ImuSample();
    portBASE_TYPE imuStatus;
    portBASE_TYPE altStatus;

    this->imu->init();

    TickType_t ticks = xTaskGetTickCount();
    int logSkipCount = 0;
    int consoleSkipCount = 0;

    while(true) {
        imuStatus = xQueueReceive(imuSampleQueue, &imuSample, 1000/portTICK_PERIOD_MS);

        float altimeterSample = -0.1f;
        altStatus = altimeter->getAltimeterSample(&altimeterSample);

        if (imuStatus == pdPASS) {
            TickType_t ticksNow = xTaskGetTickCount();
            float dt = (ticksNow-ticks)/1000.0f;
            ticks = ticksNow;
            convertImuSampleToAircraftReferenceFrame(&imuSample);
            Vector* position = kinematics->getNewPosition();
            if (position->z < 1 && altStatus == pdPASS) {
                kinematics->setAltitude(altimeterSample);
                kinematics->initialSetBearingRadiansCCwN(imuSample.getCompassAngleRadiansCCwN());
            }
            delete position;

            if (altStatus == pdPASS && altimeterSample>0) imuSample.altAmsl = altimeterSample;
            Vector* linearAcceleration = imuSample.getNewLinearAccelerationMps();
            Vector* angularVelocity = imuSample.getNewAngularVelocityRps();
            kinematics->setDtSample(dt);
            kinematics->setLinearAccelerationSample(linearAcceleration);
            kinematics->setAngularVelocitySample(angularVelocity);
            kinematics->setAltimeterSample(altimeterSample);



            kinematics->processSample();

            GpsSample* gpsSample = gpsTask->getNewSample();
            kinematics->setGpsSample(gpsSample);
            delete gpsSample;
            float compassAngle = imuSample.getCompassAngleRadiansCCwN();
            kinematics->updateBearingRadiansCCwN(compassAngle);

            Quaternion* a = kinematics->getNewAttitude();
            Vector* v = kinematics->getNewVelocity();
            Vector* p = kinematics->getNewPosition();

            if (this->loggingEnabled) {
                if (logSkipCount++ == 5) {
                    ImuMessage imuMessage = ImuMessage(&imuSample);
                    KinematicsEstimateMessage kinematicsEstimateMessage =
                        KinematicsEstimateMessage(dt, *a, *v, *p);
                    Logger::getInstance().logMessage(&imuMessage);
                    Logger::getInstance().logMessage(&kinematicsEstimateMessage);
                    logSkipCount = 0;
                }
            }
            if (Config::getInstance().isConsoleEnabled() && consoleSkipCount++ == 20) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdouble-promotion"
                if (altimeterSample < 0.01f) consoleSkipCount--;
                else {
                    Vector* aV = a->getNewEuler();
                    printf("attd %4.0f, %4.0f, %4.0f   vel %6.1f, %6.1f, %6.1f   pos %7.1f, %7.1f, %7.1f   altimeter %7.1f" NEWLINE, 
                        aV->x*180.0f/PI, aV->y*180.0f/PI, aV->z*180.0f/PI,
                        v->x, v->y, v->z,
                        p->x, p->y, p->z, altimeterSample);
                    delete aV;
                    consoleSkipCount = 0;
                }
#pragma GCC diagnostic pop
            }
            delete a;
            delete v;
            delete p;

            delete linearAcceleration;
            delete angularVelocity;
            xSemaphoreGive(altimeterSemaphore);  // start sample
        }
        this->isAlive = true;

        taskYIELD();
    }
}

bool SensorTask::isGpsLocked() {
    return gpsTask->isLocked();
}

void SensorTask::markOrigin() {
    kinematics->markOrigin();
}

Kinematics* SensorTask::getKinematics() {
    return kinematics;
}

void SensorTask::convertImuSampleToAircraftReferenceFrame(ImuSample* imuSample) {
    imuSample->convertToReferenceFrame(this->boardRotationReferenceFrame);
    imuSample->convertToReferenceFrame(this->imuReferenceFrame);
}

// Note: The argument is a rotation - Don't just convert the gravity vector to a Quaternion!
void SensorTask::updateReferenceFrameFromFeedback(Quaternion* referenceFrameAdjustment) {
    Vector* adjustmentV = referenceFrameAdjustment->getNewEuler();
    Vector* refFrameV = this->imuReferenceFrame->getNewEuler();

    // once per control loop
    float weight = Config::getInstance().accel2frameFeedback * 0.1f;
    Quaternion* newRefFrame = new Quaternion(
            refFrameV->x + (-adjustmentV->x-refFrameV->x)*weight,
            refFrameV->y + (-adjustmentV->y-refFrameV->y)*weight,
            0
    );
    newRefFrame->normalize();
    delete adjustmentV;
    delete refFrameV;
    delete this->imuReferenceFrame;
    this->imuReferenceFrame = newRefFrame;
}

void SensorTask::setLoggingEnabled(bool enabled) {
    this->loggingEnabled = enabled;
}

void SensorTask::calibrateSensors() {
    this->imu->calibrate();
}
