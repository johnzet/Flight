#include <embUnit/embUnit.h>
#include <Vector.h>
#include <Quaternion.h>
#include <Kinematics.h>
#include <math.h>

#define ERROR_MARGIN 0.000001f
#define LARGE_ERROR_MARGIN 0.001f
const float g = 9.81f;

static void setUp(void) {
}

static void tearDown(void) {
}

static void test_ctor(void) {
    Kinematics k = Kinematics();
    Quaternion* a = k.getNewAttitude();
    Vector* v = k.getNewVelocity();
    Vector* p = k.getNewPosition();
    TEST_ASSERT(fabsf(a->r-1.0f) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->x) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->y) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->z) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->x) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->y) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->z) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->x) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->y) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->z) < ERROR_MARGIN);
    delete a;
    delete v;
    delete p;
}

static void test_testing_ctor(void) {
    float expAr = 1.0f;
    float expAx = 2.0f;
    float expAy = 3.0f;
    float expAz = 4.0f;
    float expVx = 5.0f;
    float expVy = 6.0f;
    float expVz = 7.0f;
    float expPx = 8.0f;
    float expPy = 9.0f;
    float expPz = 10.0f;
    Quaternion expA = Quaternion(expAr, expAx, expAy, expAz);
    Vector expV = Vector(expVx, expVy, expVz);
    Vector expP = Vector(expPx, expPy, expPz);
    Kinematics k = Kinematics(&expA, &expV, &expP);
    Quaternion* a = k.getNewAttitude();
    Vector* v = k.getNewVelocity();
    Vector* p = k.getNewPosition();
    TEST_ASSERT(fabsf(a->r-expAr) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->x-expAx) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->y-expAy) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->z-expAz) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->x-expVx) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->y-expVy) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->z-expVz) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->x-expPx) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->y-expPy) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->z-expPz) < ERROR_MARGIN);
    delete a;
    delete v;
    delete p;
}

static void test_static() {
    Kinematics k = Kinematics();
    k.setDtSample(0.1f);
    Vector* lv = new Vector(0.0f,0.0f,g);
    Vector* av = new Vector(0.0f,0.0f,0.0f);
    k.setLinearAccelerationSample(lv);
    k.setAngularVelocitySample(av);
    k.setAltimeterSample(0.0f);
    k.processSample(); 
    Quaternion* a = k.getNewAttitude();
    Vector* v = k.getNewVelocity();
    Vector* p = k.getNewPosition();
    TEST_ASSERT(fabsf(a->r-1.0f) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->x) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->y) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->z) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->x) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->y) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->z) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->x) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->y) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->z) < ERROR_MARGIN);
    delete av;
    delete lv;
    delete a;
    delete v;
    delete p;
}

static void test_simple_straight() {
    float expAr = 1.0f;
    float expAx = 0.0f;
    float expAy = 0.0f;
    float expAz = 0.0f;
    float expVx = 5.0f;
    float expVy = 6.0f;
    float expVz = 7.0f;
    float expPx = 8.0f;
    float expPy = 9.0f;
    float expPz = 10.0f; // 
    Quaternion *expAptr = new Quaternion(expAr, expAx, expAy, expAz);
    Quaternion &expA = *expAptr;
    Vector expV = Vector(expVx, expVy, expVz);
    Vector expP = Vector(expPx, expPy, expPz);
    Kinematics k = Kinematics(&expA, &expV, &expP);
    float dt = 0.1f;
    k.setDtSample(dt);
    Vector* lv = new Vector(0.0f,0.0f,g);
    Vector* av = new Vector(0.0f,0.0f,0.0f);
    k.setLinearAccelerationSample(lv);
    k.setAngularVelocitySample(av);
    k.setAltimeterSample(expPz);
    k.processSample(); 
    Quaternion* a = k.getNewAttitude();
    Vector* v = k.getNewVelocity();
    Vector* p = k.getNewPosition();
    TEST_ASSERT(fabsf(a->r-expAr) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->x-expAx) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->y-expAy) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->z-expAz) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->x-expVx) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->y-expVy) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->z-expVz) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->x-expPx-expVx*dt) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->y-expPy-expVy*dt) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->z-expPz-expVz*dt) < 0.1f);  // altimeter lags by 1 sample

    delete av;
    delete lv;
    delete expAptr;
    delete a;
    delete v;
    delete p;
}

static void test_symetric_tilt() {
    // Tilt one axis, pause, then tilt back.  Should remain at the origin.
    Kinematics k = Kinematics();
    const float dt = 1.0f;
    const float theta = 0.1f;  // angle increment 

    for (int i=1; i<=5; i++) {
        k.setDtSample(dt);
        Vector* lv = new Vector(0.0f,g*sinf(theta*(i)),g*cosf(theta*(i)));
        Vector* av = new Vector(theta,0.0f,0.0f);
        k.setLinearAccelerationSample(lv);
        k.setAngularVelocitySample(av);
        k.setAltimeterSample(0);
        k.processSample(); 
        delete av;
        delete lv;
    }

    for (int i=0; i<5; i++) {
        k.setDtSample(dt);
        Vector* lv = new Vector(0.0f,g*sinf(theta*5),g*cosf(theta*5));
        Vector* av = new Vector(0.0f,0.0f,0.0f);
        k.setLinearAccelerationSample(lv);
        k.setAngularVelocitySample(av);
        k.setAltimeterSample(0);
        k.processSample(); 
        delete av;
        delete lv;
    }

    Quaternion* a = k.getNewAttitude();
    Vector* v = k.getNewVelocity();
    Vector* p = k.getNewPosition();
    TEST_ASSERT(fabsf(v->x) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->y) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->z) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->x) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->y) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->z) < LARGE_ERROR_MARGIN);
    delete a;
    delete v;
    delete p;

    for (int i=4; i>=0; i--) {
        k.setDtSample(dt);
        Vector* lv = new Vector(0.0f,g*sinf(theta*(i)),g*cosf(theta*(i)));
        Vector* av = new Vector(-theta,0.0f,0.0f);
        k.setLinearAccelerationSample(lv);
        k.setAngularVelocitySample(av);
        k.setAltimeterSample(0);
        k.processSample(); 
        delete av;
        delete lv;
    }

    a = k.getNewAttitude();
    v = k.getNewVelocity();
    p = k.getNewPosition();
    TEST_ASSERT(fabsf(a->r-1) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->x) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->y) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->z) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->x) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->y) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->z) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->x) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->y) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->z) < LARGE_ERROR_MARGIN);
    delete a;
    delete v;
    delete p;
}

//static void test_gentle_bank() {
//    TEST_FAIL("not impl");
//}

//static void test_inverted_bank() {
//    TEST_FAIL("not impl");
//}

static void test_alimeterFeedback() {
//    Kinematics k = Kinematics();
//    const float dt = 0.1;
//    const float altitude = 1500;
//
//    k.setAltitude(altitude);
//
//    for(int index=0; index<100; index++) {
//        k.setDtSample(dt);
//        Vector* la = new Vector(0,0,g*1.2f);
//        Vector* av = new Vector(0,0,0);
//        k.setLinearAccelerationSample(la);
//        k.setAngularVelocitySample(av);
//        k.setAltimeterSample(altitude);
//        k.processSample(); 
//        delete av;
//        delete la;
//    }
//
//    Vector* p = k.getNewPosition();
//    TEST_ASSERT(fabsf(p->z - altitude) < 100.0f);
//    delete p;
//
//    for(int index=0; index<100; index++) {
//        k.setDtSample(dt);
//        Vector* la = new Vector(0,0,g*1.0f);
//        Vector* av = new Vector(0,0,0);
//        k.setLinearAccelerationSample(la);
//        k.setAngularVelocitySample(av);
//        k.setAltimeterSample(altitude);
//        k.processSample(); 
//        delete av;
//        delete la;
//    }
//
//    p = k.getNewPosition();
//    TEST_ASSERT(fabsf(p->z - altitude) < 100.0f);
//    delete p;
}

static void test_compassFeedback() {
    Kinematics k = Kinematics();
    const float dt = 0.1f;
    const float altitude = 1500;
    const float angle = PI/2.0f;

    Config::getInstance().compassFeedback = 0.1;

    k.setAltitude(altitude);
    k.initialSetBearingRadiansCCwN(angle);
    Quaternion* a = k.getNewAttitude();
    Vector* v1 = a->getNewEuler();
    TEST_ASSERT(fabsf(v1->z - angle) < 0.01f);
    delete v1;
    delete a;

    for(int index=0; index<10; index++) {
        k.setDtSample(dt);
        Vector* lv = new Vector(0,0,g*1.0f);
        Vector* av = new Vector(0,0,0.05f);
        k.setLinearAccelerationSample(lv);
        k.setAngularVelocitySample(av);
        k.setAltimeterSample(altitude);
        k.processSample(); 
        k.updateBearingRadiansCCwN(angle);
        delete av;
        delete lv;
    }

    a = k.getNewAttitude();
    v1 = a->getNewEuler();
    TEST_ASSERT(fabsf(v1->z - angle) < 0.06f);
    delete v1;
    delete a;

    for(int index=0; index<1000; index++) {
        k.setDtSample(dt);
        Vector* lv = new Vector(0,0,g*1.0f);
        Vector* av = new Vector(0,0,0);
        k.setLinearAccelerationSample(lv);
        k.setAngularVelocitySample(av);
        k.setAltimeterSample(altitude);
        k.processSample(); 
        k.updateBearingRadiansCCwN(angle);
        delete av;
        delete lv;
    }

    a = k.getNewAttitude();
    v1 = a->getNewEuler();
    TEST_ASSERT(fabsf(v1->z - angle) < 0.02f);
    delete v1;
    delete a;
}

static void test_gpsFeedback() {
    const float dt = 0.1f;
    const float altitude = 1500;
    Config::getInstance().gps2posFeedback = 0.1;
    Config::getInstance().gps2velFeedback = 0.1;
    Kinematics k = Kinematics();
    k.setAltitude(altitude);
    GpsTask gps = GpsTask();
    gps.parsePacket("$GPRMC,231645.010,A,3945.0545,N,10457.7586,W,0.32,357.56,010115,,,A*79\r\n");
    gps.markOrigin();
    k.setDtSample(dt);
    Vector* lv = new Vector(0,0,g*1.0f);
    Vector* av = new Vector(0,0,0);
    k.setLinearAccelerationSample(lv);
    k.setAngularVelocitySample(av);
    k.setAltimeterSample(altitude);
    k.processSample(); 

    Quaternion* a = k.getNewAttitude();
    Vector* v = k.getNewVelocity();
    Vector* p = k.getNewPosition();
    TEST_ASSERT(fabsf(a->r-1) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->x) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->y) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->z) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->x) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->y) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->z) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->x) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->y) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->z-altitude) < LARGE_ERROR_MARGIN);
    //GpsSample* gpsSample = gps.getNewSample();
    //TEST_ASSERT(gpsSample == NULL);

    delete av;
    delete lv;
    delete a;
    delete v;
    delete p;
    //delete gpsSample;

    gps.parsePacket("$GPRMC,231645.010,A,3945.0546,N,10457.7587,W,0.32,57.56,010115,,,A*79\r\n");
    GpsSample* s = gps.getNewSample();
    p = s->getNewPosition();
    TEST_ASSERT((p->y-0.0185f) < LARGE_ERROR_MARGIN);
    TEST_ASSERT((p->x-0.0185f) < LARGE_ERROR_MARGIN);
    TEST_ASSERT((p->z) < LARGE_ERROR_MARGIN);
    delete p;

    for (int index=0; index<1000; index++) {
        k.setGpsSample(s);
    }

    a = k.getNewAttitude();
    v = k.getNewVelocity();
    p = k.getNewPosition();
    float speedMps = 0.32f * 0.51444444444f;
    float bearing = (360.0f-57.56f) * PI/180.0f;
    TEST_ASSERT(fabsf(a->r-1) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->x) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->y) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(a->z) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->x - speedMps*cosf(bearing)) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->y - speedMps*sinf(bearing)) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->z) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->x - 0.0185f) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->y - 0.0185f) < LARGE_ERROR_MARGIN);
    TEST_ASSERT(fabsf(p->z-altitude) < LARGE_ERROR_MARGIN);
    delete a;
    delete v;
    delete p;
    delete s;
}

TestRef Kinematics_tests(void) {
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture("test_ctor", test_ctor),
        new_TestFixture("test_testing_ctor", test_testing_ctor),
        new_TestFixture("test_static", test_static),
        new_TestFixture("test_simple_straight", test_simple_straight),
        new_TestFixture("test_symetric_tilt", test_symetric_tilt),
        //new_TestFixture("test_gentle_bank", test_gentle_bank),
        //new_TestFixture("test_inverted_bank", test_inverted_bank)
        new_TestFixture("test_alimeterFeedback", test_alimeterFeedback),
        new_TestFixture("test_compassFeedback", test_compassFeedback),
        new_TestFixture("test_gpsFeedback", test_gpsFeedback)
    };

    EMB_UNIT_TESTCALLER(Kinematics_test, "Kinematics_test", setUp, tearDown, fixtures);
    return (TestRef)&Kinematics_test;
}
