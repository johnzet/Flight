#include <embUnit/embUnit.h>
#include <Helicopter.h>


static void setUp(void) {
}

static void tearDown(void) {
}

static void test_initialServoPositions() {
    SensorTask sensorTask = SensorTask(NULL, NULL, NULL);
    PwmCapture pwmCapture = PwmCapture();
    PwmGen pwmGen = PwmGen();
    Helicopter helicopter = Helicopter(&sensorTask, &pwmCapture, &pwmGen);
    helicopter.init();

    TEST_ASSERT(fabsf(pwmGen.getChannelValueZeroToOne(ServoChannel::CCPM_30) - 0.5f) < 0.001f);
    TEST_ASSERT(fabsf(pwmGen.getChannelValueZeroToOne(ServoChannel::CCPM_150) - 0.5f) < 0.001f);
    TEST_ASSERT(fabsf(pwmGen.getChannelValueZeroToOne(ServoChannel::CCPM_270) - 0.5f) < 0.001f);
    TEST_ASSERT(fabsf(pwmGen.getChannelValueZeroToOne(ServoChannel::TAIL_ROTOR) - 0.5f) < 0.001f);
    TEST_ASSERT(fabsf(pwmGen.getChannelValueZeroToOne(ServoChannel::THROTTLE) - 0.0f) < 0.001f);
}

void test_tailServoReactionToYaw() {
    Config& config = Config::getInstance();
    config.tailMin = 0.1f;

    SensorTask sensorTask = SensorTask(NULL, NULL, NULL);
    PwmCapture pwmCapture = PwmCapture();
    pwmCapture.TEST_ONLY_setChannelValueZeroToOne(ReceiverChannel::YAW, 0.5f);
    PwmGen pwmGen = PwmGen();
    Helicopter helicopter = Helicopter(&sensorTask, &pwmCapture, &pwmGen);
    helicopter.init();
    Kinematics* k = sensorTask.getKinematics();

    k->setDtSample(0.1f);
    Vector* v = new Vector(0.0f, 0.0f, 1.0f);
    k->setAngularVelocitySample(v);
    k->processSample();
    Quaternion* yawedAttitude = k->getNewAttitude();
    TEST_ASSERT(yawedAttitude->z > 0.04f);
    delete v;
    delete yawedAttitude;

    float tailServo = pwmGen.getChannelValueZeroToOne(ServoChannel::TAIL_ROTOR);
    TEST_ASSERT((0.4f < tailServo) && (tailServo < 0.6f));
    for (int count=0; count<100; count++) {
        helicopter.updateGyroOnlyClosedLoopControl();
    }
    tailServo = pwmGen.getChannelValueZeroToOne(ServoChannel::TAIL_ROTOR);
    TEST_ASSERT(fabsf(tailServo - config.tailMin) < 0.01f);
}

void test_tailServoReactionToYaw2() {
    Config& config = Config::getInstance();
    config.tailMax = 0.9f;

    SensorTask sensorTask = SensorTask(NULL, NULL, NULL);
    PwmCapture pwmCapture = PwmCapture();
    pwmCapture.TEST_ONLY_setChannelValueZeroToOne(ReceiverChannel::YAW, 0.5f);
    PwmGen pwmGen = PwmGen();
    Helicopter helicopter = Helicopter(&sensorTask, &pwmCapture, &pwmGen);
    helicopter.init();
    Kinematics* k = sensorTask.getKinematics();

    k->setDtSample(0.1f);
    Vector* v = new Vector(0.0f, 0.0f, -1.0f);
    k->setAngularVelocitySample(v);
    k->processSample();
    Quaternion* yawedAttitude = k->getNewAttitude();
    TEST_ASSERT(yawedAttitude->z < -0.04f);
    delete v;
    delete yawedAttitude;

    float tailServo = pwmGen.getChannelValueZeroToOne(ServoChannel::TAIL_ROTOR);
    TEST_ASSERT((0.4f < tailServo) && (tailServo < 0.6f));
    for (int count=0; count<100; count++) {
        helicopter.updateGyroOnlyClosedLoopControl();
    }
    tailServo = pwmGen.getChannelValueZeroToOne(ServoChannel::TAIL_ROTOR);
    TEST_ASSERT(fabsf(tailServo - config.tailMax) < 0.01f);
}

static void test_GyroFeedback_hover() {
    SensorTask sensorTask = SensorTask(NULL, NULL, NULL);
    PwmCapture pwmCapture = PwmCapture();
    PwmGen pwmGen = PwmGen();
    Helicopter helicopter = Helicopter(&sensorTask, &pwmCapture, &pwmGen);
    helicopter.init();
    Kinematics* k = sensorTask.getKinematics();

    k->setDtSample(0.1f);
    Vector* v = new Vector(1.0f, 1.0f, 0.0f);
    k->setAngularVelocitySample(v);
    k->processSample();
    Quaternion* driftedAttitude = k->getNewAttitude();
    TEST_ASSERT(driftedAttitude->x > 0.04f);
    delete v;

    k->setDtSample(0.02f);
    Config::getInstance().accel2gyroFeedback = 0.5;
    for (int count=0; count<100; count++) {
        Quaternion* feedbackAttitude = helicopter.getNewAttitudeForGyroFeedback();
        if (feedbackAttitude != NULL) {
            k->updateAttitudeFromFeedback(feedbackAttitude);
            delete (feedbackAttitude);
        }
    }

    Quaternion* correctedAttitude = k->getNewAttitude();
    TEST_ASSERT(fabsf(correctedAttitude->x) < 0.01f);
    TEST_ASSERT(fabsf(correctedAttitude->y) < 0.01f);
    TEST_ASSERT(fabsf(correctedAttitude->z - driftedAttitude->z) < 0.01f);
    delete correctedAttitude;
    delete driftedAttitude;
}

TestRef Helicopter_tests(void) {
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture("test_tailServoReactionToYaw", test_tailServoReactionToYaw),
        new_TestFixture("test_GyroFeedback_hover", test_GyroFeedback_hover),
        new_TestFixture("test_tailServoReactionToYaw2", test_tailServoReactionToYaw2),
        new_TestFixture("test_initialServoPositions", test_initialServoPositions)
    };

    EMB_UNIT_TESTCALLER(Helicopter_tests, "Helicopter_tests", setUp, tearDown, fixtures);
    return (TestRef)&Helicopter_tests;
}
