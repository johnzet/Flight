#include <embUnit/embUnit.h>
#include <CliTask.h>


static void setUp(void) {
}

static void tearDown(void) {
}

void test_CliReadWrite() {
#ifndef TARGET_IS_SIMULATOR
    Config& config = Config::getInstance();
    config.setUseTestFlashBank(true);
    CliTask cli = CliTask(NULL);

    char buffer[40];

    strcpy(buffer, "default"); cli.processCommand(buffer);
    strcpy(buffer, "set yaw pidd 200.0"); cli.processCommand(buffer);
    strcpy(buffer, "save"); cli.processCommand(buffer);
    strcpy(buffer, "set yaw pidd 300.0"); cli.processCommand(buffer);
    TEST_ASSERT(fabsf(config.yawPid.d - 300.0f) < 0.00001f);
    strcpy(buffer, "load"); cli.processCommand(buffer);
    TEST_ASSERT(fabsf(config.yawPid.d - 200.0f) < 0.00001f);
    config.setUseTestFlashBank(false);

#endif
}

void test_pid_params() {
    Config& config = Config::getInstance();
    CliTask cli = CliTask(NULL);
    char buffer[40];

    TEST_ASSERT(config.yawPid.p < 10.0f);
    TEST_ASSERT(config.yawPid.p > 0.0f);
    TEST_ASSERT(config.tailMin > 0.0f);
    TEST_ASSERT(config.tailMax < 1.0f);

    strcpy(buffer, "set tail reverse false"); cli.processCommand(buffer);
    TEST_ASSERT(!config.tailReverse);
    strcpy(buffer, "set tail reverse true"); cli.processCommand(buffer);
    TEST_ASSERT(config.tailReverse);

    strcpy(buffer, "set yaw pidp 0.22"); cli.processCommand(buffer);
    strcpy(buffer, "set tail min 0.33"); cli.processCommand(buffer);
    strcpy(buffer, "set tail max 0.77"); cli.processCommand(buffer);
    
    TEST_ASSERT(fabsf(config.yawPid.p - 0.22f) < 0.00001f);
    TEST_ASSERT(fabsf(config.tailMin - 0.33f) < 0.00001f);
    TEST_ASSERT(fabsf(config.tailMax - 0.77f) < 0.00001f);
    TEST_ASSERT(config.tailReverse);
}

//static void test_command_history() {
//    Config& config = Config::getInstance();
//    CLI cli = CLI();
//    char buffer[40];
//
//    strcpy(buffer, "set yaw pidp 0.23"); cli.processCommand(buffer);
//    TEST_ASSERT(fabsf(config.yawPid.p - 0.23f) < 0.00001f);
//    
//    config.yawPid.p = 0.42;
//    TEST_ASSERT(fabsf(config.yawPid.p - 0.42f) < 0.00001f);
//
//    buffer[0] = 0x1b; 
//    buffer[1] = 0x5b;
//    buffer[1] = 0x41;
//    buffer[2] = '\r';
//    buffer[3] = '\n';
//    buffer[4] = NULL;
//    cli.processCommand(buffer);
//    TEST_ASSERT(fabsf(config.yawPid.p - 0.23f) < 0.00001f);
//
//}

void test_feedback_params() {
    Config& config = Config::getInstance();
    CliTask cli = CliTask(NULL);
    char buffer[40];

    TEST_ASSERT(config.altimeterFeedback > 0.0f);
    TEST_ASSERT(config.altimeterFeedback < 1.0f);
    TEST_ASSERT(config.compassFeedback > 0.0f);
    TEST_ASSERT(config.compassFeedback < 1.0f);
    TEST_ASSERT(config.gps2posFeedback > 0.0f);
    TEST_ASSERT(config.gps2posFeedback < 1.0f);
    TEST_ASSERT(config.gps2velFeedback > 0.0f);
    TEST_ASSERT(config.gps2velFeedback < 1.0f);
    TEST_ASSERT(config.accel2frameFeedback > 0.0f);
    TEST_ASSERT(config.accel2frameFeedback < 1.0f);
    TEST_ASSERT(config.accel2gyroFeedback > 0.0f);
    TEST_ASSERT(config.accel2gyroFeedback < 1.0f);

    strcpy(buffer, "set feedback altimeter 0.42"); cli.processCommand(buffer);
    TEST_ASSERT(fabsf(config.altimeterFeedback -0.42f) < 0.00001f);

    strcpy(buffer, "set feedback compass 0.43"); cli.processCommand(buffer);
    TEST_ASSERT(fabsf(config.compassFeedback -0.43f) < 0.00001f);

    strcpy(buffer, "set feedback gps2pos 0.44"); cli.processCommand(buffer);
    TEST_ASSERT(fabsf(config.gps2posFeedback -0.44f) < 0.00001f);

    strcpy(buffer, "set feedback gps2vel 0.45"); cli.processCommand(buffer);
    TEST_ASSERT(fabsf(config.gps2velFeedback -0.45f) < 0.00001f);

    strcpy(buffer, "set feedback accel2frame 0.46"); cli.processCommand(buffer);
    TEST_ASSERT(fabsf(config.accel2frameFeedback -0.46f) < 0.00001f);

    strcpy(buffer, "set feedback accel2gyro 0.47"); cli.processCommand(buffer);
    TEST_ASSERT(fabsf(config.accel2gyroFeedback -0.47f) < 0.00001f);
}

void test_properties() {
    Config& config = Config::getInstance();
    CliTask cli = CliTask(NULL);
    char buffer[10];

    TEST_ASSERT(! config.isConsoleEnabled());
    strcpy(buffer, "console"); cli.processCommand(buffer);
    TEST_ASSERT(config.isConsoleEnabled());
    strcpy(buffer, ""); cli.processCommand(buffer);
    TEST_ASSERT(! config.isConsoleEnabled());
}


TestRef CLI_tests(void) {
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture("test_CliReadWrite", test_CliReadWrite),
        new_TestFixture("test_pid_params", test_pid_params),
//        new_TestFixture("test_command_history", test_command_history),
        new_TestFixture("test_feedback_params", test_feedback_params),
        new_TestFixture("test_properties", test_properties)
    };

    EMB_UNIT_TESTCALLER(CLI_tests, "CLI_tests", setUp, tearDown, fixtures);
    return (TestRef)&CLI_tests;
}
