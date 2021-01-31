
#include <embUnit/embUnit.h>
#include <Vector.h>
#include <math.h>

#define ERROR_MARGIN 0.000001
static void setUp(void) {
}

static void tearDown(void) {
}

static void test_default_ctor(void) {
    Vector v = Vector();
    TEST_ASSERT(fabs(v.x) < ERROR_MARGIN);
    TEST_ASSERT(fabs(v.y) < ERROR_MARGIN);
    TEST_ASSERT(fabs(v.z) < ERROR_MARGIN);
}

static void test_ctor(void) {
    float expX = 1.1;
    float expY = 2.2;
    float expZ = 3.3;
    Vector v = Vector(expX, expY, expZ);
    TEST_ASSERT(fabs(v.x-expX) < ERROR_MARGIN);
    TEST_ASSERT(fabs(v.y-expY) < ERROR_MARGIN);
    TEST_ASSERT(fabs(v.z-expZ) < ERROR_MARGIN);
}

static void test_copy_ctor(void) {
    float expX = 1.1;
    float expY = 2.2;
    float expZ = 3.3;
    Vector vOrig = Vector(expX, expY, expZ);
    Vector v = Vector(vOrig);
    TEST_ASSERT(fabs(v.x-expX) < ERROR_MARGIN);
    TEST_ASSERT(fabs(v.y-expY) < ERROR_MARGIN);
    TEST_ASSERT(fabs(v.z-expZ) < ERROR_MARGIN);
}

static void test_operator_multiply_by_scalar() {
    float expX = 1.1;
    float expY = 2.2;
    float expZ = 3.3;
    float scalar = 4.6;
    Vector vin = Vector(expX, expY, expZ);
    Vector vout = vin * scalar;

    TEST_ASSERT(fabs(vout.x-expX*scalar) < ERROR_MARGIN);
    TEST_ASSERT(fabs(vout.y-expY*scalar) < ERROR_MARGIN);
    TEST_ASSERT(fabs(vout.z-expZ*scalar) < ERROR_MARGIN);
}

static void test_operator_plus() {
    float expX1 = 1.1;
    float expY1 = 2.2;
    float expZ1 = 3.3;
    float expX2 = 7.1;
    float expY2 = 8.2;
    float expZ2 = 9.3;
    Vector v1 = Vector(expX1, expY1, expZ1);
    Vector v2 = Vector(expX2, expY2, expZ2);
    Vector vout = v1 + v2;

    TEST_ASSERT(fabs(vout.x-expX1-expX2) < ERROR_MARGIN);
    TEST_ASSERT(fabs(vout.y-expY1-expY2) < ERROR_MARGIN);
    TEST_ASSERT(fabs(vout.z-expZ1-expZ2) < ERROR_MARGIN);
}

static void test_operator_minus() {
    float expX1 = 1.1;
    float expY1 = 2.2;
    float expZ1 = 3.3;
    float expX2 = 7.1;
    float expY2 = 8.2;
    float expZ2 = 9.3;
    Vector v1 = Vector(expX1, expY1, expZ1);
    Vector v2 = Vector(expX2, expY2, expZ2);
    Vector vout = v1 - v2;

    TEST_ASSERT(fabs(vout.x-expX1+expX2) < ERROR_MARGIN);
    TEST_ASSERT(fabs(vout.y-expY1+expY2) < ERROR_MARGIN);
    TEST_ASSERT(fabs(vout.z-expZ1+expZ2) < ERROR_MARGIN);
}

TestRef Vector_tests(void) {
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture("test_default_ctor", test_default_ctor),
        new_TestFixture("test_copy_ctor", test_copy_ctor),
        new_TestFixture("test_ctor", test_ctor),
        new_TestFixture("test_operator_multiply_by_scalar", test_operator_multiply_by_scalar),
        new_TestFixture("test_operator_plus", test_operator_plus),
        new_TestFixture("test_operator_minus", test_operator_minus)
    };

    EMB_UNIT_TESTCALLER(Vector_test, "Vector_test", setUp, tearDown, fixtures);
    return (TestRef)&Vector_test;
}
