#ifndef PWM_CAPTURE_H
#define PWM_CAPTURE_H

#include <stm32f4xx.h>
#include <stm32f4xx_conf.h>
#include <stdio.h>
#include <math.h>
#include <PwmGen.h>
#include <FreeRTOS.h>
#include <task.h>

enum CaptureTimerIndex { TIMER3=0, TIMER4=1 };

class PwmCapture {
    public:
        PwmCapture();
        void init();
        float getChannelValueZeroToOne(ChannelEnum channel);
        void irqHandler(CaptureTimerIndex timerIndex);
        void irqChannelHandler(CaptureTimerIndex timerIndex, int channel);
        bool isReceiverSignalOK();

    private:
        uint32_t chanRisingCount[2][4];
        uint32_t chanPulseWidth[2][4];
        long timeOfLastCapture;
        float lastGoodCaptureValue[8];

        // testing
        bool testMode;
        float testChannelValues[8];
        friend void test_PwmCapture1();
        friend void test_tailServoReactionToYaw();
        friend void test_tailServoReactionToYaw2();
        void TEST_ONLY_setChannelValueZeroToOne(ChannelEnum channel, float value);
};

#endif