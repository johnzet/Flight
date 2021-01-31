#include <embUnit/embUnit.h>
#include <Vector.h>
#include <Quaternion.h>
#include <math.h>

const float ERROR_MARGIN = 0.0001;
const float WIDER_ERROR_MARGIN = 0.001;
const float PI = 3.1415926535; 

static void setUp() {
}

static void tearDown() {
}

static void test_default_ctor(void) {
    Quaternion q = Quaternion();
    TEST_ASSERT(fabsf(q.r-1.0f) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.x) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.y) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.z) < ERROR_MARGIN);
}

static void test_vector_ctor() {
    float expR = 9.9;
    float expX = 1.1;
    float expY = 2.2;
    float expZ = 3.3;
    Vector v = Vector(expX, expY, expZ);
    Quaternion qOrig = Quaternion(expR, v);
    Quaternion q = Quaternion(qOrig);
    TEST_ASSERT(fabsf(q.r-expR) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.x-expX) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.y-expY) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.z-expZ) < ERROR_MARGIN);
}

static void test_copy_ctor() {
    float expR = 9.9;
    float expX = 1.1;
    float expY = 2.2;
    float expZ = 3.3;
    Vector v = Vector(expX, expY, expZ);
    Quaternion q = Quaternion(expR, v);
    TEST_ASSERT(fabsf(q.r-expR) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.x-expX) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.y-expY) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.z-expZ) < ERROR_MARGIN);
}

static void test_discrete_ctor() {
    float expR = 9.9;
    float expX = 1.1;
    float expY = 2.2;
    float expZ = 3.3;
    Quaternion q = Quaternion(expR, expX, expY, expZ);
    TEST_ASSERT(fabsf(q.r-expR) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.x-expX) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.y-expY) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.z-expZ) < ERROR_MARGIN);
}

static void test_euler_ctor() {
    float ex = 0.1;
    float ey = 0.2;
    float ez = 0.3;
    Quaternion q = Quaternion(ex, ey, ez);
    q.normalize();
    // values from Matlab
    TEST_ASSERT(fabsf(q.r-0.9819f) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.x-0.0641f) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.y-0.0912f) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.z-0.1534f) < ERROR_MARGIN);
}

static void test_get_euler() {
    float ex = 0.1;
    float ey = 0.2;
    float ez = 0.3;
    Quaternion q = Quaternion(ex, ey, ez);
    Vector* v = q.getNewEuler();
    TEST_ASSERT(fabsf(v->x-ex) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->y-ey) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->z-ez) < ERROR_MARGIN);
    delete v;

    // pitch up gimbal lock
    ex = 0.0;
    ey = 3.0f*PI/2.0f;
    ez = 0.0;
    q = Quaternion(ex, ey, ez);
    v = q.getNewEuler();
    TEST_ASSERT(fabsf(v->x-ex) < WIDER_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->y-ey) < WIDER_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->z-ez) < WIDER_ERROR_MARGIN);
    delete v;

    // pitch down gimbal lock
    ex = 0.0;
    ey = PI/2.0f;
    ez = 0.0;
    q = Quaternion(ex, ey, ez);
    v = q.getNewEuler();
    TEST_ASSERT(fabsf(v->x-ex) < WIDER_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->y-ey) < WIDER_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->z-ez) < WIDER_ERROR_MARGIN);
}

static void test_operator_mult() {
    Quaternion a = Quaternion(1.0, 2.0, 3.0, 4.0);
    Quaternion b = Quaternion(6.0, 7.0, 8.0, 9.0);
    Quaternion c = a * b;
    // values from Matlab
    TEST_ASSERT(fabsf(c.r+68) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(c.x-14) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(c.y-36) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(c.z-28) < ERROR_MARGIN);
}

static void test_operator_scalar_div() {
    Quaternion a = Quaternion(1.0, 2.0, 3.0, 4.0);
    float b = 5;
    Quaternion c = a / b;

    TEST_ASSERT(fabsf(c.r-0.2f) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(c.x-0.4f) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(c.y-0.6f) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(c.z-0.8f) < ERROR_MARGIN);
}

static void test_operator_scalar_mult() {
    Quaternion a = Quaternion(1.0, 2.0, 3.0, 4.0);
    float b = 5.0;
    Quaternion c = a * b;

    TEST_ASSERT(fabsf(c.r-5.0f) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(c.x-10.0f) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(c.y-15.0f) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(c.z-20.0f) < ERROR_MARGIN);
}

static void test_conj() {
    float expR = 9.9;
    float expX = 1.1;
    float expY = 2.2;
    float expZ = 3.3;
    Quaternion q = Quaternion(expR, expX, expY, expZ);
    Quaternion q2 = q.conj();
    
    TEST_ASSERT(fabsf(q2.r-expR) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q2.x+expX) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q2.y+expY) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q2.z+expZ) < ERROR_MARGIN);

}

static void test_norm() {
    float expR = 9.9;
    float expX = 1.1;
    float expY = 2.2;
    float expZ = 3.3;
    Quaternion q = Quaternion(expR, expX, expY, expZ);

    float n = q.norm();
    
    TEST_ASSERT(fabsf(n-sqrtf(powf(expR,2) + powf(expX, 2) + powf(expY, 2) + powf(expZ, 2))) < ERROR_MARGIN);
}

static void test_normalize() {

    float expR = 9.9;
    float expX = 1.1;
    float expY = 2.2;
    float expZ = 3.3;
    Quaternion q = Quaternion(expR, expX, expY, expZ);

    q.normalize();
    //values from Matlab
    TEST_ASSERT(fabsf(q.r-0.9234f) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.x-0.1026f) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.y-0.2052f) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.z-0.3078f) < ERROR_MARGIN);
}

static void test_normalize_zero() {
    Quaternion q = Quaternion(0.0,0.0,0.0,0.0);
    q.normalize();
    TEST_ASSERT(fabsf(q.r) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.x) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.y) < ERROR_MARGIN);
    TEST_ASSERT(fabsf(q.z) < ERROR_MARGIN);
}

static void test_get_matrix() {
    // values from Matlab
    float mExp[3][3] = {
        {-0.6667, 0.6667, 0.3333},
        {0.1333, -0.3333333, 0.9333333},  
        {0.7333, 0.6667, 0.1333}
    };
    Quaternion q = Quaternion(0.1, 0.2, 0.3, 0.4);
    q.normalize();
    float m[3][3];
    q.getMatrix(m);
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            TEST_ASSERT(fabsf(m[i][j]-mExp[i][j]) < ERROR_MARGIN);
        }
    }
}

static void test_sandwich() {
    float g = 9.81;
    Quaternion q = Quaternion(0.1, 0, 0);
    Vector v = Vector(0, g*sinf(0.1f), g*cosf(0.1f));
    Vector* vp = q.getNewSandwich(&v);

    TEST_ASSERT(fabsf(vp->x-0) < WIDER_ERROR_MARGIN);
    TEST_ASSERT(fabsf(vp->y-0) < WIDER_ERROR_MARGIN);
    TEST_ASSERT(fabsf(vp->z-g) < WIDER_ERROR_MARGIN);

    delete vp;
}

static void test_sandwich2() {
    float qr = 0.1;
    float qx = 0.2;
    float qy = 0.3;
    float qz = 0.4;
    Quaternion q = Quaternion(qr, qx, qy, qz);
    float vx = 6.0;
    float vy = 7.0;
    float vz = 8.0;
    Vector v = Vector(vx, vy, vz);
    Vector* s = q.getNewSandwich(&v);

    TEST_ASSERT(fabsf(s->x-2.8f) < WIDER_ERROR_MARGIN);
    TEST_ASSERT(fabsf(s->y-7.0f) < WIDER_ERROR_MARGIN);
    TEST_ASSERT(fabsf(s->z-9.6f) < WIDER_ERROR_MARGIN);

    delete s;
}

static void test_slerp() {
    Quaternion q1 = Quaternion(PI/2.0f, 0, 0);
    q1.normalize();
    Quaternion q2 = Quaternion(-PI/2.0f, 0, 0);
    q2.normalize();
    Quaternion* q = q1.getNewSlerp(&q2, 1.0f/2.0f);
    q->normalize();

    Vector* v = q->getNewEuler();
    TEST_ASSERT(fabsf(v->x) < WIDER_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->y) < WIDER_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->z) < WIDER_ERROR_MARGIN);
    delete q;
    delete v;

    q1 = Quaternion(0, PI + 0.00001f, 0);
    q2 = Quaternion(0, -PI/2.0f, 0);
    q = q1.getNewSlerp(&q2, 2.0f/3.0f);

    v = q->getNewEuler();
    TEST_ASSERT(fabsf(v->x) < WIDER_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->y) < WIDER_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->z) < WIDER_ERROR_MARGIN);
    delete q;
    delete v;

    q1 = Quaternion(0, 0, PI);
    q2 = Quaternion(0, 0, -PI/2.0f);
    q = q1.getNewSlerp(&q2, 2.0f/3.0f);

    v = q->getNewEuler();
    TEST_ASSERT(fabsf(v->x) < WIDER_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->y) < WIDER_ERROR_MARGIN);
    TEST_ASSERT(fabsf(v->z) < WIDER_ERROR_MARGIN || fabsf(2.0f*PI-v->z) < WIDER_ERROR_MARGIN);
    delete q;
    delete v;
}

TestRef Quaternion_tests() {
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture("test_default_ctor", test_default_ctor),
        new_TestFixture("test_copy_ctor", test_copy_ctor),
        new_TestFixture("test_vector_ctor", test_vector_ctor),
        new_TestFixture("test_discrete_ctor", test_discrete_ctor),
        new_TestFixture("test_euler_ctor", test_euler_ctor),
        new_TestFixture("test_operator_mult", test_operator_mult),
        new_TestFixture("test_conj", test_conj),
        new_TestFixture("test_norm", test_norm),
        new_TestFixture("test_normalize", test_normalize),
        new_TestFixture("test_normalize_zero", test_normalize_zero),
        new_TestFixture("test_operator_scalar_mult", test_operator_scalar_mult),
        new_TestFixture("test_operator_scalar_div", test_operator_scalar_div),
        new_TestFixture("test_get_euler", test_get_euler),
        new_TestFixture("test_get_matrix", test_get_matrix),
        new_TestFixture("test_sandwich", test_sandwich),
        new_TestFixture("test_sandwich2", test_sandwich2),
        new_TestFixture("test_slerp", test_slerp)
    };

    EMB_UNIT_TESTCALLER(Vector_test, "Vector_test", setUp, tearDown, fixtures);
    return (TestRef)&Vector_test;
}
