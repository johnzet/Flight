#ifndef IMU_H
#define IMU_H

#include <__cross_studio_io.h>
#include <stm32f4xx.h>
#include <string.h>
#include <FreeRTOS.h>
#include <queue.h>
#include <task.h>
#include <I2C.h>
#include <Vector.h>
#include <delay.h>
#include <config.h>
#include <arm_math.h>
#include <Quaternion.h>

class ImuSample {
  public:
    // linear acceleration is in Gs
    // angular velocity is in degrees/s
    ImuSample(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz, float altAmsl);
    ImuSample(ImuSample *imuSample);
    ImuSample();
    Vector* getNewLinearAccelerationMps();
    Vector* getNewAngularVelocityRps();
    float getCompassAngleRadiansCCwN();  // 0 radians at right x-axis crossing 
    void convertToReferenceFrame(Quaternion* referenceFrame);

    float ax, ay, az;
    float gx, gy, gz;
    float mx, my, mz;
    float altAmsl;
};

    /*  InvenSense MPU-9250
     *  Accel & Gyro    Mag       Bearing
     *       X ^        Y ^          ^  0 degrees
     *         |          |          |
     *         |          |          |
     *   Y     |    X     |     <neg |  pos>
     *   <-----O    <-----X          |  
     *         Z          Z
     */        

class IMU {
  public:
    IMU(xQueueHandle sampleQueue);
    void init();
    void calibrate();
    void irqHandler();

  private:
    I2C *imuI2C;
    I2C *compassI2C;
    uint8_t imuAddress;
    uint8_t compassAddress;
    uint8_t magCal[3];
    ImuSample imuSample;
    volatile bool sampleReadyFlag;
    ImuSample* cal;
    xQueueHandle sampleQueue = NULL;
    bool calibrating;

    void configureImuComm();
    void initImu();
    void initInterrupt();
    bool isSampleReady();
    ImuSample* getSample();
};


class ImuMessage : public LogMessage {
  private:
    ImuSample imuSample;
    char* _toString(char* buffer, uint16_t length, const char* formatStr);

  public:
    ImuMessage(ImuSample *imuSample);
    char* toString(char* buffer, uint16_t length);
    char* toDataString(char* buffer, uint16_t length);
    uint16_t getSize();
    char* getShortType();
};

#endif