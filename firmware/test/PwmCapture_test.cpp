#include <embUnit/embUnit.h>
#include <PwmCapture.h>


static void setUp(void) {
}

static void tearDown(void) {
}

// friend of PwmCapture
void test_PwmCapture1() {
    PwmCapture pwmCapture = PwmCapture();
    float actual = 0.2f;
    pwmCapture.TEST_ONLY_setChannelValueZeroToOne(ChannelEnum::CHANNEL1, actual);
    float value = pwmCapture.getChannelValueZeroToOne(ChannelEnum::CHANNEL1);
    TEST_ASSERT(fabs((actual) - value) < 0.001);
}

TestRef PwmCapture_tests(void) {
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture("test_PwmCapture1", test_PwmCapture1),
    };

    EMB_UNIT_TESTCALLER(PwmCapture_tests, "PwmCapture_tests", setUp, tearDown, fixtures);
    return (TestRef)&PwmCapture_tests;
}
