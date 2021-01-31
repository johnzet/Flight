#ifndef ALTIMETER_TASK_H
#define ALTIMETER_TASK_H

#include <__cross_studio_io.h>
#include <stm32f4xx.h>
#include <stm32f4xx_conf.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <queue.h>
#include <task.h>
#include <I2C.h>
#include <Math.h>
#include <TaskWrapper.h>


class AltimeterTask : public TaskClass {
  public:
    AltimeterTask(xSemaphoreHandle semaphore);
    void init();
    void task();
    portBASE_TYPE getAltimeterSample(float* sampleData);


  private:
    uint8_t altAddress;
    I2C *altI2C;
    uint16_t ac4, ac5, ac6;  // cal data
    int16_t ac1, ac2, ac3, b1, b2, mb, mc, md;  // cal data
    void initIO();
    void readCalData();
    float measureAltitude();

    xSemaphoreHandle semaphore;
    xQueueHandle queue;

};

#endif