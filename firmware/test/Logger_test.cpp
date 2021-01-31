#include <embUnit/embUnit.h>
#include <Logger.h>

static void setUp(void) {
}

static void tearDown(void) {
}

static void test_Singleton() {
    Logger& inst1 = Logger::getInstance();
    Logger& inst2 = Logger::getInstance();
    inst1.setId(1);
    inst2.setId(2);
    TEST_ASSERT_NOT_NULL(&inst1);
    TEST_ASSERT_NOT_NULL(&inst2);
    TEST_ASSERT(&inst1 == &inst2);
    TEST_ASSERT(inst1.getId() == 2);
    TEST_ASSERT(inst2.getId() == 2);
}

TestRef Logger_tests(void) {
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture("test_Singleton", test_Singleton)
    };

    EMB_UNIT_TESTCALLER(Logger_tests, "Logger_tests", setUp, tearDown, fixtures);
    return (TestRef)&Logger_tests;
}
