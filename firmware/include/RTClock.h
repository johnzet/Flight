#ifndef RTCLOCK_H
#define RTCLOCK_H

#include <stm32f4xx.h>
#include <stm32f4xx_conf.h>

class RTClock {

    public:
        RTClock();
        void init();
        uint32_t getTime();
};

#endif