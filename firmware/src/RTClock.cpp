#include <RTClock.h>

RTClock::RTClock() {
}

void RTClock::init() {
    RCC_RTCCLKConfig(RCC_RTCCLKSource_HSE_Div8);
    RTC_InitTypeDef rtcInitStruct;
    rtcInitStruct.RTC_HourFormat = RTC_HourFormat_24;
    rtcInitStruct.RTC_AsynchPrediv = 100 -1;
    rtcInitStruct.RTC_SynchPrediv = 10000 -1;
    RTC_Init(&rtcInitStruct);
}

uint32_t RTClock::getTime() {
    return 0; //RTC_GetTime())
}