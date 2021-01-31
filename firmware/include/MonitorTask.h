#ifndef MONITOR_TASK_H
#define MONITOR_TASK_H

#include <__cross_studio_io.h>
#include <stm32f4xx.h>
#include <stm32f4xx_conf.h>
#include <stm32f4xx_iwdg.h>
#include <FreeRTOS.h>
#include <task.h>
#include <LEDs.h>
#include <SensorTask.h>
#include <ControlTask.h>
#include <AltimeterTask.h>
#include <GpsTask.h>

class MonitorTask : public TaskClass {
  public:
    MonitorTask(LEDs* leds, SensorTask* sensorTask, ControlTask* controlTask, AltimeterTask* altimeterTask, GpsTask* gpsTask);
    void init();
    void task();
    enum TaskId {ALTIMETER, SENSOR, CONTROL};

  private:
    LEDs* leds;
    SensorTask* sensorTask;
    ControlTask* controlTask;
    AltimeterTask* altimeterTask;
    GpsTask* gpsTask;
};

#endif