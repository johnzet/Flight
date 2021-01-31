#include <embUnit/embUnit.h>
#include <I2C.h>
#include <string.h>

static void setUp(void) {
}

static void tearDown(void) {
}

static void test_IntException() {
    bool pass = false;
    try {
        throw(42);
        TEST_FAIL("Exception not thrown");
    }
    catch(I2cTimeoutException& te) {
        TEST_FAIL("Wrong exception type caught");
        pass = true;
    }
    catch(int e) {
        if (e == 42) pass = true;
    }
    TEST_ASSERT(pass);
}

static void test_TimeoutException() {
    bool pass = false;
    try {
        throw(I2cTimeoutException());
        TEST_FAIL("Exception not thrown");
    }
    catch(int e) {
        TEST_FAIL("Wrong exception type caught");
    }
    catch(I2cTimeoutException& te) {
        const char* whatStr = te.what();
        TEST_ASSERT(strcmp(whatStr, "I2C timeout exception thrown") == 0);
        pass = true;
    }
    TEST_ASSERT(pass);
}

static void test_FnWait_TestFn_Inner(char* a, int b) {
    TEST_ASSERT(strcmp(a, "test text") == 0);
    TEST_ASSERT(b > 0);
}

static bool test_FnWait_TestFn(char* a, int uSec) {
    test_FnWait_TestFn_Inner(a,uSec);
    return uSec > 42;
}

static void test_FnWait() {
    I2C_WAIT_UNTIL(100, test_FnWait_TestFn("test text", 50), true);
}

static void test_FnWait_Timeout() {
    bool pass = false;
    try {
        I2C_WAIT_UNTIL(10, test_FnWait_TestFn("test text", 1), true);
        TEST_FAIL("Exception not thrown");
    }
    catch(I2cTimeoutException& te) {
        pass = true;
    }
    TEST_ASSERT(pass);
}

TestRef I2C_tests(void) {
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture("test_Exception", test_IntException),
        new_TestFixture("test_TimeoutException", test_TimeoutException),
        new_TestFixture("test_FnWait", test_FnWait),
        new_TestFixture("test_FnWait_Timeout", test_FnWait_Timeout)
    };

    EMB_UNIT_TESTCALLER(I2C_tests, "I2C_tests", setUp, tearDown, fixtures);
    return (TestRef)&I2C_tests;
}
