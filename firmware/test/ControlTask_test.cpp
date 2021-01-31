#include <embUnit/embUnit.h>
#include <ControlTask.h>


static void setUp(void) {
}

static void tearDown(void) {
}

static void test_ControlStateLabels() {
    ControlTask ct = ControlTask(NULL);
    TEST_ASSERT(ct.getControlStateLabel(ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP).find("pass-through", 20) >= 0)
    TEST_ASSERT(ct.getControlStateLabel(ControlState::GYRO_ONLY_CLOSED_LOOP).find("Gyro", 10) >= 0)
    TEST_ASSERT(ct.getControlStateLabel(ControlState::FULL_CLOSED_LOOP).find("Full", 10) >= 0)
    TEST_ASSERT(ct.getControlStateLabel(ControlState::SEMI_AUTONOMOUS_CLOSED_LOOP).find("Semi-autonomous", 20) >= 0)
}

void test_isStartingControlledFlight() {
    ControlTask controlTask = ControlTask(NULL);
    ControlState currentState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    ControlState requestedState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    bool isGpsLocked = false;
    bool isReceiverActive = false;
    TEST_ASSERT(false == controlTask.isStartingControlledFlight(currentState, requestedState, isGpsLocked, isReceiverActive));

    currentState = ControlState::FULL_CLOSED_LOOP;
    requestedState = ControlState::FULL_CLOSED_LOOP;
    isGpsLocked = false;
    isReceiverActive = true;;
    TEST_ASSERT(false == controlTask.isStartingControlledFlight(currentState, requestedState, isGpsLocked, isReceiverActive));

    currentState = ControlState::FULL_CLOSED_LOOP;
    requestedState = ControlState::FULL_CLOSED_LOOP;
    isGpsLocked = true;
    TEST_ASSERT(false == controlTask.isStartingControlledFlight(currentState, requestedState, isGpsLocked, isReceiverActive));

    currentState = ControlState::GYRO_ONLY_CLOSED_LOOP;
    requestedState = ControlState::FULL_CLOSED_LOOP;
    isGpsLocked = true;
    TEST_ASSERT(true == controlTask.isStartingControlledFlight(currentState, requestedState, isGpsLocked, isReceiverActive));
}

void test_getNextState() {
    ControlTask controlTask = ControlTask(NULL);
    ControlState currentState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    ControlState requestedState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    bool isGpsLocked = false;
    bool isReceiverActive = false;
    TEST_ASSERT(ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive));

    currentState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    requestedState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    isGpsLocked = false;
    TEST_ASSERT(ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive));

    currentState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    requestedState = ControlState::GYRO_ONLY_CLOSED_LOOP;
    isGpsLocked = false;
    TEST_ASSERT(ControlState::GYRO_ONLY_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive));

    currentState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    requestedState = ControlState::FULL_CLOSED_LOOP;
    isGpsLocked = false;
    TEST_ASSERT(ControlState::GYRO_ONLY_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive));

    currentState = ControlState::GYRO_ONLY_CLOSED_LOOP;
    requestedState = ControlState::FULL_CLOSED_LOOP;
    isGpsLocked = true;
    TEST_ASSERT(ControlState::GYRO_ONLY_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive));

    currentState = ControlState::GYRO_ONLY_CLOSED_LOOP;
    requestedState = ControlState::FULL_CLOSED_LOOP;
    isReceiverActive = true;
    isGpsLocked = true;
    TEST_ASSERT(ControlState::FULL_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive));

    currentState = ControlState::FULL_CLOSED_LOOP;
    requestedState = ControlState::FULL_CLOSED_LOOP;
    isGpsLocked = false;
    TEST_ASSERT(ControlState::FULL_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive));

    currentState = ControlState::FULL_CLOSED_LOOP;
    requestedState = ControlState::GYRO_ONLY_CLOSED_LOOP;
    isGpsLocked = true;
    TEST_ASSERT(ControlState::GYRO_ONLY_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive));
}

TestRef ControlTask_tests(void) {
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture("test_ControlStateLabels", test_ControlStateLabels),
        new_TestFixture("test_isStartingControlledFlight", test_isStartingControlledFlight),
        new_TestFixture("test_getNextState", test_getNextState)
    };

    EMB_UNIT_TESTCALLER(ControlTask_tests, "ControlTask_tests", setUp, tearDown, fixtures);
    return (TestRef)&ControlTask_tests;
}
