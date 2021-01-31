#include <PwmGen.h>

PwmGen::PwmGen() {
    testMode = true;
}

void PwmGen::init() {
    testMode = false;
    //float period = 0.011;  // 11 ms


    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);
  


    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOH, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOI, &GPIO_InitStructure);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_TIM2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_TIM2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_TIM2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM2);
    GPIO_PinAFConfig(GPIOH, GPIO_PinSource10, GPIO_AF_TIM5);
    GPIO_PinAFConfig(GPIOH, GPIO_PinSource11, GPIO_AF_TIM5);
    GPIO_PinAFConfig(GPIOH, GPIO_PinSource12, GPIO_AF_TIM5);
    GPIO_PinAFConfig(GPIOI, GPIO_PinSource0, GPIO_AF_TIM5);

    int periodCounter = 250000;
    uint16_t prescaler = 3; //floor(2.0 * period * pclk1) / periodCounter; 

    
    TIM_TimeBaseStructure.TIM_Period = periodCounter;
    TIM_TimeBaseStructure.TIM_Prescaler = prescaler;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
    TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC1Init(TIM2, &TIM_OCInitStructure);
    TIM_OC1Init(TIM5, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
    TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Enable);

    TIM_OC2Init(TIM2, &TIM_OCInitStructure);
    TIM_OC2Init(TIM5, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
    TIM_OC2PreloadConfig(TIM5, TIM_OCPreload_Enable);

    TIM_OC3Init(TIM2, &TIM_OCInitStructure);
    TIM_OC3Init(TIM5, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
    TIM_OC3PreloadConfig(TIM5, TIM_OCPreload_Enable);

    TIM_OC4Init(TIM2, &TIM_OCInitStructure);
    TIM_OC4Init(TIM5, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);
    TIM_OC4PreloadConfig(TIM5, TIM_OCPreload_Enable);

    TIM_ARRPreloadConfig(TIM2, ENABLE);
    TIM_ARRPreloadConfig(TIM5, ENABLE);

    TIM_Cmd(TIM2, ENABLE);
    TIM_Cmd(TIM5, ENABLE);

//    float normalizedPosition = 0.3;
//    uint16_t counter = floor((1.0+normalizedPosition) * 22440.0);

//    for (int channel=ChannelEnum::CHANNEL1; channel<ChannelEnum::CHANNEL8; channel++) {
//        setChannelValueZeroToOne(ChannelEnum(channel), 0);
//    }
}

void PwmGen::setChannelValueZeroToOne(ChannelEnum channel, float zeroToOne) {
    zeroToOne = fmaxf(-0.2, zeroToOne);
    zeroToOne = fminf(1.2, zeroToOne);
    if (testMode) {
        testChannelValues[channel.getValue()] = zeroToOne;
        return;
    }
    uint16_t value = floor((1 + zeroToOne) * 22440);

    switch(channel.getValue()) {
        case ChannelEnum::CHANNEL1:
            TIM2->CCR1 = value;
            break;
        case ChannelEnum::CHANNEL2:
            TIM2->CCR2 = value;
            break;
        case ChannelEnum::CHANNEL3:
            TIM2->CCR3 = value;
            break;
        case ChannelEnum::CHANNEL4:
            TIM2->CCR4 = value;
            break;
        case ChannelEnum::CHANNEL5:
            TIM5->CCR1 = value;
            break;
        case ChannelEnum::CHANNEL6:
            TIM5->CCR2 = value;
            break;
        case ChannelEnum::CHANNEL7:
            TIM5->CCR3 = value;
            break;
        case ChannelEnum::CHANNEL8:
            TIM5->CCR4 = value;
            break;
        default:
            break;
    }
}

float PwmGen::getChannelValueZeroToOne(ChannelEnum channel) {
    if (testMode) {
        return testChannelValues[channel.getValue()];
    } 
    return 0;
}

ChannelEnum::ChannelEnum(uint8_t value) {
    this->value = value;
}

uint8_t ChannelEnum::getValue() {
    return value;
}
