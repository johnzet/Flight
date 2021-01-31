#ifndef SENSOR_TASK_H
#define SENSOR_TASK_H

#include <__cross_studio_io.h>
#include <stm32f4xx.h>
#include <stm32f4xx_conf.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <queue.h>
#include <task.h>
#include <Math.h>
#include <TaskWrapper.h>
#include <Kinematics.h>
#include <IMU.h>
#include <AltimeterTask.h>
#include <GpsTask.h>

#define NEWLINE "\n\r"


class SensorTask : public TaskClass {
  public:
    SensorTask(AltimeterTask* altimeter, xSemaphoreHandle altimeterSemaphore, GpsTask* gpsTask);
    ~SensorTask();
    void init();
    void task();
    Kinematics* getKinematics();
    Quaternion* getNewReferenceFrame();
    bool isGpsLocked();
    void markOrigin();
    void convertImuSampleToAircraftReferenceFrame(ImuSample* imuSample);
    void updateReferenceFrameFromFeedback(Quaternion* referenceFrameAdjustment);
    void setLoggingEnabled(bool enabled);
    void calibrateSensors();

  private:
    Quaternion* imuReferenceFrame;
    Quaternion* boardRotationReferenceFrame;
    Kinematics* kinematics;
    IMU* imu;
    GpsTask* gpsTask;
    AltimeterTask* altimeter;
    xSemaphoreHandle altimeterSemaphore;
    xQueueHandle imuSampleQueue;
    bool loggingEnabled;

};

#endif