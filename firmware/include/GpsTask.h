#ifndef GPS_H
#define GPS_H

#include <stm32f4xx.h>
#include <stm32f4xx_conf.h>
#include <stdio.h>
#include <string.h>
#include <arm_math.h>
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>
#include <Vector.h>
#include <TaskWrapper.h>
#include <delay.h>

#define GPS_BUFFER_LENGTH 100

class GpsSample {
    private:
        Vector* position, *velocity;
        TickType_t timestamp;
    
    public:
        GpsSample(Vector* position, Vector* velocity, TickType_t timestamp);
        GpsSample(GpsSample* gpsSample);
        ~GpsSample();
        Vector* getNewPosition();
        Vector* getNewVelocity();
        TickType_t getTimestamp();
};

class GpsTask : public TaskClass  {
    private:
        char gpsBuffer[GPS_BUFFER_LENGTH];
        char parsableGpsBuffer[GPS_BUFFER_LENGTH];
        void initGpsUsart();
        void initGps();
        void sendChar(const char c);
        void sendStr(const char* buffer, uint32_t length);
        uint8_t calcChecksum(const char* buffer, uint32_t length);
        double utcTime, latitude, longitude;
        float speed, course;
        int date;
        char status, latInd, lonInd;
        double originLatitude, originLongitude;
        void calculateSampleData(TickType_t timestamp);
        GpsSample* gpsSample;
        xSemaphoreHandle gpsMutex = NULL;

    public:
        GpsTask();
        ~GpsTask();
        void init();
        void task();
        void irqHandler();
        void markOrigin();
        void parsePacket(const char* buffer);  // exposed for testing only
        bool isLocked();
        GpsSample* getNewSample();
};


#endif