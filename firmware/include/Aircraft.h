#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <SensorTask.h>
#include <PwmCapture.h>
#include <PwmGen.h>
#include <Pid.h>


class Aircraft {
    public:
        Aircraft(SensorTask* sensorTask, PwmCapture* pwmCapture, PwmGen* pwmGen);
        virtual void init() = 0;
        virtual void updatePassThroughOpenLoopControl() = 0;
        virtual void updateGyroOnlyClosedLoopControl() = 0;
        virtual void updateFullClosedLoopControl() = 0;
        virtual void updateSemiAutonomousClosedLoopControl() = 0; 
        virtual Quaternion* getNewAttitudeForGyroFeedback() = 0;  // May return null
        virtual bool isLoggingEnabled() = 0;

    protected:
        SensorTask* sensorTask;
        PwmCapture* pwmCapture;
        PwmGen* pwmGen;

    private:

};



#endif