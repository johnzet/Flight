#ifndef KINEMATICS_H
#define KINEMATICS_H

#include <Vector.h>
#include <Quaternion.h>
#include <Logger.h>
#include <GpsTask.h>
#include <Config.h>
#include <exception>
#include <FreeRTOS.h>
#include <semphr.h>

/**
  *  Abreviations:
  *     Mps:  meters per second^2
  *     Dps:  degrees per second
  */

class Kinematics {
    private:
        Quaternion* attitudePtr = NULL;
        Vector* velocityPtr = NULL;
        Vector* positionPtr = NULL;
        const float g = 9.81;
        xSemaphoreHandle sampleMutex = NULL;
        Vector* aSamplePtr = NULL;
        Vector* gSamplePtr = NULL;
        float previousAltimeterSample = -100.0f;
        float dtSample;
        void takeMutex();
        void giveMutex();

    protected:

    public:
        Kinematics();
        Kinematics(const Quaternion* attitudeArg, const Vector* velocityArg, const Vector* positionArg);
        ~Kinematics();
        
        void setDtSample(const float dtSample);
        void setLinearAccelerationSample(const Vector* aSample);
        void setAngularVelocitySample(const Vector* gSample);
        void setAltimeterSample(const float altimeterSample);
        float getDtSample();
        Vector* getNewLinearAccelerationSample();
        Vector* getNewAngularVelocitySample();
//        float getAltimeterSample();
        void processSample();

        Quaternion* getNewAttitude();
        Vector* getNewVelocity();
        Vector* getNewPosition();
        float getAccelerationDueToGravity();

        void markOrigin();

        // Feedback
        void setAltitude(float altitude);
        void setGpsSample(GpsSample* gpsSample);
        void initialSetBearingRadiansCCwN(const float angle);
        void updateBearingRadiansCCwN(const float angle);
        void updateAttitudeFromFeedback(Quaternion* estimatedAttitude);
};

class KinematicsEstimateMessage : public LogMessage {
  private:
    float dt;
    Quaternion attitude;
    Vector velocity;
    Vector position;
    char* _toString(char* buffer, uint16_t length, const char* formatStr);

  public:
    KinematicsEstimateMessage(float dt, Quaternion attitude, Vector velocity, Vector position);
    char* toString(char* buffer, uint16_t length);
    char* toDataString(char* buffer, uint16_t length);
    uint16_t getSize();
    char* getShortType();
};



#endif