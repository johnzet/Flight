#ifndef CONTROL_TASK_H
#define CONTROL_TASK_H

#include <__cross_studio_io.h>
#include <stm32f4xx.h>
#include <stm32f4xx_conf.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <queue.h>
#include <task.h>
#include <Math.h>
#include <stdlib.h>
#include <string>
#include <exception>
#include <TaskWrapper.h>
#include <SensorTask.h>
#include <PwmCapture.h>
#include <PwmGen.h>
#include <Logger.h>
#include <Aircraft.h>
#include <Helicopter.h>

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

enum class ControlState {
    CONTROL_PASS_THROUGH_OPEN_LOOP=0, 
    GYRO_ONLY_CLOSED_LOOP=1, 
    FULL_CLOSED_LOOP=2, 
    SEMI_AUTONOMOUS_CLOSED_LOOP=3,
};


class ControlTask : public TaskClass {
  public:
    ControlTask(SensorTask* sensorTask);
    void init();
    void task();
    std::string getControlStateLabel(ControlState controlState);
    void controlGyroDrift();
    ControlState getControlState();

  private:
    SensorTask* sensorTask;
    PwmCapture* pwmCapture;
    PwmGen* pwmGen;
    Aircraft* aircraft;
    ControlState controlState;

    bool isStartingControlledFlight(ControlState controlState, ControlState requestedControlState, bool isGpsLocked, bool isReceiverActive);
    ControlState getNextState(ControlState controlState, ControlState requestedControlState, bool isGpsLocked, bool isReceiverActive);
    void processState(ControlState controlState);
    
    ControlState getRequestedControlState();
    Aircraft* instantiateAircraft();
    bool isReceiverSignalOK();

    void updatePassThroughOpenLoopControl();
    void updateGyroOnlyClosedLoopControl();
    void updateFullClosedLoopControl();
    void updateSemiAutonomousClosedLoopControl();

    // testing
    friend void test_isStartingControlledFlight();
    friend void test_getNextState();
};

#endif