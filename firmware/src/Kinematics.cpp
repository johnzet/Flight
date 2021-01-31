#include <Kinematics.h>

Kinematics::Kinematics() {
    sampleMutex = xSemaphoreCreateMutex();
    attitudePtr = new Quaternion();
    velocityPtr = new Vector();
    positionPtr = new Vector();
}

Kinematics::Kinematics(const Quaternion* attitudeArg, const Vector* velocityArg, const Vector* positionArg) {
    sampleMutex = xSemaphoreCreateMutex();
    if (attitudePtr != NULL) delete attitudePtr;
    if (velocityPtr != NULL) delete velocityPtr;
    if (positionPtr != NULL) delete positionPtr;
    attitudePtr = new Quaternion(*attitudeArg);
    velocityPtr = new Vector(*velocityArg);
    positionPtr = new Vector(*positionArg);
}

Kinematics::~Kinematics() {
    delete attitudePtr;
    delete velocityPtr;
    delete positionPtr;
    vSemaphoreDelete(sampleMutex);
}

void Kinematics::takeMutex() {
    if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED) {
        xSemaphoreTake(sampleMutex, portMAX_DELAY);
    }
    // probably in unit tests
}

void Kinematics::giveMutex() {
    if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED) {
        xSemaphoreGive(sampleMutex);
    }
    // probably in unit tests
}

float Kinematics::getAccelerationDueToGravity() {
    return g;
}

void Kinematics::setDtSample(const float dtSample) {
    this->dtSample = dtSample;
}

float Kinematics::getDtSample() {
    return this->dtSample;
}

void Kinematics::setLinearAccelerationSample(const Vector* aSampleArg) {
    takeMutex();
    if (aSamplePtr != NULL) delete this->aSamplePtr;
    aSamplePtr = new Vector(*aSampleArg);
    giveMutex();
}

Vector* Kinematics::getNewLinearAccelerationSample() {
    takeMutex();
    Vector* v = new Vector(*this->aSamplePtr);  // ****** Caller must delete the returned object
    giveMutex();
    return v;
}

void Kinematics::setAngularVelocitySample(const Vector* gSampleArg) {
    takeMutex();
    if (gSamplePtr != NULL) delete this->gSamplePtr;
    gSamplePtr = new Vector(*gSampleArg);
    giveMutex();
}

Vector* Kinematics::getNewAngularVelocitySample() {
    takeMutex();
    Vector* v = new Vector(*this->gSamplePtr);  // ****** Caller must delete the returned object
    giveMutex();
    return v;
}

void Kinematics::processSample() {
    // Meter-Kilogram-Second-Radian measure
    // Right-Hand rules
    // NWU - North-West-Up
    // x axis = forward
    // y axis = left
    // z axis = up
    // roll = x axis
    // pitch = y axis
    // yaw = z axis
    // vectors are all column vectors (1 columnm, n rows)

    
//    // ****** Matlab ****************************************************
//    // angular position delta samples
//    aP_sample_q = ZQ_euler2quat(aV_sample*dt);
//
//    // attitude 
//    A_q_w = A_q_w_0 * aP_sample_q;
//    A_q_w = A_q_w/norm(A_q_w);
//    
//    // velocity
//    A_sample_w = ZQ_sandwich(A_q_w, A_sample)
//    V_w = V_w_0 + (A_sample_w - [0;0;g])*dt;
//    
//    //  position
//    P_w = P_w_0 + V_w*dt; 
//    
//   
//    // sensor fusion
//    P_w(3) = P_w(3)*0.9 + altim_sample*0.1;
//    // ****** Matlab ****************************************************

    takeMutex();


    float dt = dtSample;
    Vector& gyroSampleRpsV = *gSamplePtr;
    Vector& accelSampleMpsV = *aSamplePtr;
    Vector& velocity = *velocityPtr;
    Vector& position = *positionPtr;
    Quaternion& attitude = *attitudePtr;

    // angular position delta samples
    Vector v = gyroSampleRpsV*dt;
    Quaternion aP_sample = Quaternion(v.x, v.y, v.z);

    // attitude 
    attitude = attitude * aP_sample;
    attitude.normalize();
    
    // velocity
    Vector* a_samplePtr = attitude.getNewSandwich(&accelSampleMpsV);
    Vector& a_sample = *a_samplePtr;
    velocity = velocity + (a_sample - Vector(0.0,0.0,g)) * dt;
    
    //  position
    position = position + velocity*dt; 

    delete a_samplePtr;
    
    giveMutex();
}

void Kinematics::setAltimeterSample(const float altimeterSample) {
    // altimeter feedback
    if (altimeterSample < 0.01f) {
        return;
    }
    takeMutex();
    float dt = 0.055;  // Altimeter sample rate is a little slower than 20Hz
    float weight = Config::getInstance().altimeterFeedback;
    if (altimeterSample > 0.1f) {
        float zError = altimeterSample - positionPtr->z;
        positionPtr->z += zError * weight;
    }
    if (altimeterSample > 0.1f && previousAltimeterSample > 0.1f) {
        float zError = (altimeterSample - previousAltimeterSample) / dt - velocityPtr->z;
        velocityPtr->z += zError * weight * 0.1f;
    }
    previousAltimeterSample = altimeterSample;
    giveMutex();

}

void Kinematics::setGpsSample(GpsSample* gpsSample) {
    if (gpsSample == NULL) return;
    // once per second (GPS sample rate)
    takeMutex();
    float weight2pos = Config::getInstance().gps2posFeedback;
    float weight2vel = Config::getInstance().gps2velFeedback;
    Vector* p = gpsSample->getNewPosition();
    Vector* v = gpsSample->getNewVelocity();
    this->positionPtr->x = this->positionPtr->x * (1.0f - weight2pos) + p->x*weight2pos;
    this->positionPtr->y = this->positionPtr->y * (1.0f - weight2pos) + p->y*weight2pos;

    this->velocityPtr->x = this->velocityPtr->x * (1.0f - weight2vel) + v->x*weight2vel;
    this->velocityPtr->y = this->velocityPtr->y * (1.0f - weight2vel) + v->y*weight2vel;

    delete v;
    delete p;
    giveMutex();
}

Quaternion* Kinematics::getNewAttitude() {
    return new Quaternion(*attitudePtr);
}

Vector* Kinematics::getNewVelocity() {
    return new Vector(*velocityPtr);
}

Vector* Kinematics::getNewPosition() {
    return new Vector(*positionPtr);
}

void Kinematics::setAltitude(float altitudeAmsl) {
    positionPtr->z = altitudeAmsl;
}
    
void Kinematics::initialSetBearingRadiansCCwN(const float angle) {
    takeMutex();
    Quaternion angleQ = Quaternion(0,0,angle);
    Quaternion* q = attitudePtr->getNewSlerp(&angleQ, 1.0);
    if (this->attitudePtr != NULL) delete this->attitudePtr;
    this->attitudePtr = q;
    giveMutex();
}

void Kinematics::updateBearingRadiansCCwN(const float angle) {
    takeMutex();
    // once per dt
    Config& config = Config::getInstance();
    float weight = config.compassFeedback *  config.dt;
    Quaternion angleQ = Quaternion(0,0,angle);
    Quaternion* q = this->attitudePtr->getNewSlerp(&angleQ, weight);
    if (this->attitudePtr != NULL) delete this->attitudePtr;
    this->attitudePtr = q;
    giveMutex();
}

void Kinematics::updateAttitudeFromFeedback(Quaternion* estimatedAttitude) {
    takeMutex();
    // once per control loop
    float weight = Config::getInstance().accel2gyroFeedback * 0.1f;
    Quaternion* q = this->attitudePtr->getNewSlerp(estimatedAttitude, weight);
    if (this->attitudePtr != NULL) delete this->attitudePtr;
    this->attitudePtr = q;
    giveMutex();
}

void Kinematics::markOrigin() {
    takeMutex();
    float altitude = this->positionPtr->z;

    if (velocityPtr != NULL) delete velocityPtr;
    if (positionPtr != NULL) delete positionPtr;
    velocityPtr = new Vector();
    positionPtr = new Vector();
    this->positionPtr->z = altitude;
    giveMutex();
}





KinematicsEstimateMessage::KinematicsEstimateMessage(float dt, Quaternion attitude, Vector velocity, Vector position) {
    this->dt = dt;
    this->attitude = Quaternion(attitude);
    this->velocity = Vector(velocity);
    this->position = Vector(position);
}

char* KinematicsEstimateMessage::toString(char* buffer, uint16_t length) {
    return _toString(buffer, length, "Ticks: %i  Dt:  %+4.2f  Att: %+1.3f %+1.3f %+1.3f  Vel: %+6.1f %+6.1f %+6.1f  Pos: %+6.1f %+6.1f %+6.1f");
}

char* KinematicsEstimateMessage::toDataString(char* buffer, uint16_t length) {
    return _toString(buffer, length, "%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f");
}

char* KinematicsEstimateMessage::_toString(char* buffer, uint16_t length, const char* formatStr) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdouble-promotion"

    if (length < 200) {
        sprintf(buffer, "buffer too small");
    } else {
        Vector* attitude = this->attitude.getNewEuler();
        sprintf(buffer, formatStr,
            this->time,
            this->dt,
            attitude->x, attitude->y, attitude->z,
            this->velocity.x, this->velocity.y, this->velocity.z,
            this->position.x, this->position.y, this->position.z
        );
        delete attitude;
    }
    return buffer;

#pragma GCC diagnostic pop
}

uint16_t KinematicsEstimateMessage::getSize() {
    return sizeof(*this);
}

char* KinematicsEstimateMessage::getShortType() {
    return "kin";
}

