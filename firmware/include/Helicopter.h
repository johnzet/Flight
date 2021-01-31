#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <Aircraft.h>

namespace ReceiverChannel {
    enum RC {
        COLLECTIVE=ChannelEnum::CHANNEL1, 
        ROLL=ChannelEnum::CHANNEL2, 
        PITCH=ChannelEnum::CHANNEL3,
        YAW=ChannelEnum::CHANNEL4, 
        LOG_DATA=ChannelEnum::CHANNEL5,
        THROTTLE=ChannelEnum::CHANNEL6, 
        MODE=ChannelEnum::CHANNEL7, 
        PID_ADJUST=ChannelEnum::CHANNEL8
   };
}
namespace ServoChannel {
    enum SC {
        CCPM_30=ChannelEnum::CHANNEL2, 
        CCPM_150=ChannelEnum::CHANNEL3, 
        CCPM_270=ChannelEnum::CHANNEL1, 
        THROTTLE=ChannelEnum::CHANNEL6, 
        TAIL_ROTOR=ChannelEnum::CHANNEL4
   };
}

class Helicopter : public Aircraft {
    public:
        Helicopter(SensorTask* sensorTask, PwmCapture* pwmCapture, PwmGen* pwmGen);
        ~Helicopter();
        void init();
        void updatePassThroughOpenLoopControl();
        void updateGyroOnlyClosedLoopControl();
        void updateFullClosedLoopControl();
        void updateSemiAutonomousClosedLoopControl();
        Quaternion* getNewAttitudeForGyroFeedback();  // may return null
        bool isLoggingEnabled();

    private:
        Pid* pitchPid = NULL;
        Pid* rollPid = NULL;
        Pid* yawPid = NULL;
        void ccpmPwmGenerate(PwmGen* pwmGen, float collective0to1, float pitch0to1, float roll0to1);
        bool isHovering();
        bool isInCoordinatedFlight();
};



#endif