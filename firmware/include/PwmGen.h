#ifndef PWM_GEN_H
#define PWM_GEN_H

#include <stm32f4xx.h>
#include <stm32f4xx_conf.h>
#include <math.h>

class ChannelEnum {
    public:
        static const uint8_t CHANNEL1 = 0;
        static const uint8_t CHANNEL2 = 1;
        static const uint8_t CHANNEL3 = 2;
        static const uint8_t CHANNEL4 = 3;
        static const uint8_t CHANNEL5 = 4;
        static const uint8_t CHANNEL6 = 5;
        static const uint8_t CHANNEL7 = 6;
        static const uint8_t CHANNEL8 = 7;
        uint8_t value;
        ChannelEnum(uint8_t value);
        uint8_t getValue();
};

class PwmGen {

    public:
        PwmGen();
        void init();
        void setChannelValueZeroToOne(ChannelEnum channel, float value);

        // testing
        bool testMode;
        float testChannelValues[8];
        float getChannelValueZeroToOne(ChannelEnum channel);
};

#endif