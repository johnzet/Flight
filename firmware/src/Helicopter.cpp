#include <Helicopter.h>

Helicopter::Helicopter(SensorTask* sensorTask, PwmCapture* pwmCapture, PwmGen* pwmGen) : Aircraft(sensorTask, pwmCapture, pwmGen) {
    // center servos - Do this as soon as possible since we may have just been reset by the watchdog timer in flight.
    pwmGen->setChannelValueZeroToOne(ServoChannel::CCPM_30, 0.5f);
    pwmGen->setChannelValueZeroToOne(ServoChannel::CCPM_150, 0.5f);
    pwmGen->setChannelValueZeroToOne(ServoChannel::CCPM_270, 0.5f);
    pwmGen->setChannelValueZeroToOne(ServoChannel::TAIL_ROTOR, 0.5f);
    pwmGen->setChannelValueZeroToOne(ServoChannel::THROTTLE, 0.0f);
}

/*   Helicopter physics 
*
*    See "Smarter Every Day" playlist https://www.youtube.com/watch?v=Cg1CPmtZL4c&list=PL6CECC2E56B68A2C3
*       especially episode 4 https://www.youtube.com/watch?v=eTjGTxSevHE&list=PL6CECC2E56B68A2C3&index=8
*       Also "Veritasium": https://www.youtube.com/watch?v=ty9QSiVC2g0&index=9&list=PL6CECC2E56B68A2C3
*
*   CCPM: Collective-Cyclic Pitch Mixing - Rotor pitch is set as a constant pitch 
*       plus a cyclic pitch.  Cyclic pitch changes during the once-around rotation 
*       of the blade.
*
*   Gyroscopic Precession: To pitch or bank, the expected rotor pitch changes 
*       are made 90° BEFORE where you'd expect.
*
*   Dissymmetry of Lift:  When the helicopter is moving horizontally, the 
*       advancing blade sees more airspeed and lift than the retreating blade.
*       The retreating blade can stall - Because of gyroscopic precession, 
*       this results in a pitch up which reduces speed and corrects the stall.
*
*   Anti-Rotation: The motor's torque on the rotor disc causes the helicopter 
*       to yaw in the opposite direction.  The tail rotor counteracts this, 
*       however, the tail rotor produces a force to the side of the helicopter.
*       This force is counteracted with a slight constant bank angle.
*
*   Notes:
*       - The blade ball joint may be on the leading or trailing edge depending 
*           on the helicopter
*       - The servos may connect to the swash plate in many configurations 
*           depending on the helicopter.  Typically, they are located every 
*           120° around the swash plate.
*/

void Helicopter::init() {
    Config& config = Config::getInstance();
    this->pitchPid = new Pid(&config.pitchPid);
    this->rollPid = new Pid(&config.rollPid);
    this->yawPid = new Pid(&config.yawPid);
}

Helicopter::~Helicopter() {
    if (this->pitchPid != NULL) delete this->pitchPid;
    if (this->rollPid != NULL) delete this->rollPid;
    if (this->yawPid != NULL) delete this->yawPid;
}

void Helicopter::updatePassThroughOpenLoopControl() {
    pwmGen->setChannelValueZeroToOne(ServoChannel::THROTTLE, pwmCapture->getChannelValueZeroToOne(ReceiverChannel::THROTTLE));
    pwmGen->setChannelValueZeroToOne(ServoChannel::TAIL_ROTOR, pwmCapture->getChannelValueZeroToOne(ReceiverChannel::YAW));

    float collectiveN1to1 = (pwmCapture->getChannelValueZeroToOne(ReceiverChannel::COLLECTIVE)*2.0f)-1.0f;
    float pitchN1to1 = (pwmCapture->getChannelValueZeroToOne(ReceiverChannel::PITCH)*2.0f)-1.0f;
    float rollN1to1 = (pwmCapture->getChannelValueZeroToOne(ReceiverChannel::ROLL)*2.0f)-1.0f;
    ccpmPwmGenerate(pwmGen, collectiveN1to1, pitchN1to1, rollN1to1);
}

void Helicopter::updateGyroOnlyClosedLoopControl() {
    float throttleRequested = pwmCapture->getChannelValueZeroToOne(ReceiverChannel::THROTTLE);
    float pitchRequested = pwmCapture->getChannelValueZeroToOne(ReceiverChannel::PITCH)*2.0f - 1.0f; // range -1 to 1
    float rollRequested = pwmCapture->getChannelValueZeroToOne(ReceiverChannel::ROLL)*2.0f - 1.0f; // range -1 to 1
    float yawRequested = pwmCapture->getChannelValueZeroToOne(ReceiverChannel::YAW)*2.0f - 1.0f; // range -1 to 1
    float collN1to1 = pwmCapture->getChannelValueZeroToOne(ReceiverChannel::COLLECTIVE)*2.0f - 1.0f;

    Config& config = Config::getInstance();
    Vector* gyroSample = sensorTask->getKinematics()->getNewAngularVelocitySample();

    pwmGen->setChannelValueZeroToOne(ServoChannel::THROTTLE, throttleRequested);

    float sensorYawRate = gyroSample->z;
    float yawRateMax = PI;
    if (yawRequested > -0.02f && yawRequested < 0.02f) yawRequested = 0.0f;  // center stick dead band
    float yawRateTarget = yawRateMax * yawRequested;
    float yawError = (yawRateTarget - sensorYawRate) / yawRateMax;
    float yawCommand = yawPid->calculate(yawError);
    float yawServoValue = (yawCommand + 1.0f) / 2.0f;  // range 0 to 1
    yawServoValue = fmaxf(config.tailMin, yawServoValue);
    yawServoValue = fminf(config.tailMax, yawServoValue);
    pwmGen->setChannelValueZeroToOne(ServoChannel::TAIL_ROTOR, yawServoValue);

    float sensorPitchRate = gyroSample->y;
    float pitchRateMax = PI/4.0f;
//    if (pitchRequested > -0.1f && pitchRequested < 0.1f) pitchRequested = 0.0f;  // center stick dead band
    float pitchRateTarget = pitchRateMax * pitchRequested;
    float pitchError = (pitchRateTarget - sensorPitchRate) / pitchRateMax;
    float pitchCommandN1to1 = pitchPid->calculate(pitchError);

    float sensorRollRate = gyroSample->x;
    float rollRateMax = PI/4.0f;
//    if (rollRequested > -0.1f && rollRequested < 0.1f) rollRequested = 0.0f;  // center stick dead band
    float rollRateTarget = rollRateMax * rollRequested;
    float rollError = (rollRateTarget - sensorRollRate) / rollRateMax;
    float rollCommandN1to1 = rollPid->calculate(rollError);

    ccpmPwmGenerate(pwmGen, collN1to1, pitchCommandN1to1, rollCommandN1to1);

    delete gyroSample;
}

void Helicopter::ccpmPwmGenerate(PwmGen* pwmGen, float collectiveN1to1, float pitchN1to1, float rollN1to1) {
    float pitch = -pitchN1to1;
    float roll = -rollN1to1;
    float coll = collectiveN1to1;
	float cyc270 = coll - pitch;
	float cyc30 = coll + 0.5f*pitch + 0.866f*roll;
	float cyc150 = coll + 0.5f*pitch - 0.866f*roll;
    pwmGen->setChannelValueZeroToOne(ServoChannel::CCPM_30, 1-(cyc30+1.0f)/2.0f);
    pwmGen->setChannelValueZeroToOne(ServoChannel::CCPM_150, (cyc150+1.0f)/2.0f);
    pwmGen->setChannelValueZeroToOne(ServoChannel::CCPM_270, (cyc270+1.0f)/2.0f);
}

void Helicopter::updateFullClosedLoopControl() {
    // TODO impl
    updateGyroOnlyClosedLoopControl();
}

void Helicopter::updateSemiAutonomousClosedLoopControl() {
    // TODO impl
    updateGyroOnlyClosedLoopControl();
}

// may return null
Quaternion* Helicopter::getNewAttitudeForGyroFeedback() {
        // TODO add other flight modes
    if (isHovering()) {
        Kinematics* k = this->sensorTask->getKinematics();
        Quaternion* q = k->getNewAttitude();
        Vector* euler = q->getNewEuler();
        float z = euler->z;
        delete euler;
        delete q;
        return new Quaternion(0, 0, z);
    }
    return NULL;
}

bool Helicopter::isHovering() {
    Kinematics* k = sensorTask->getKinematics();
    Vector* v = k->getNewVelocity();
    bool retVal = (v->x < 1.0f && v->y < 1.0f);
    delete v;
    return retVal;
}

bool Helicopter::isInCoordinatedFlight() {
    // TODO impl
    return false;
}

bool Helicopter::isLoggingEnabled() {
    return pwmCapture->getChannelValueZeroToOne(ReceiverChannel::LOG_DATA) > 0.2f;
}
