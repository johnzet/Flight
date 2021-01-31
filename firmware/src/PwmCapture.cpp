#include <PwmCapture.h>

extern "C" {
    PwmCapture* irqCaptureObject;
}

PwmCapture::PwmCapture() {
    testMode = true;
    for (int i=0; i<8; i++) lastGoodCaptureValue[i] = 1500.0f;  // center
    irqCaptureObject = this;
    for (uint8_t t=0; t<2; t++) {
        for (uint8_t c=0; c<4; c++) {
            chanRisingCount[t][c] = 0;
            chanPulseWidth[t][c] = 0;
        }
    }
    timeOfLastCapture = 0;
}

void PwmCapture::init() {
    testMode = false;

    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_ICInitTypeDef TIM_ICInitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_TIM4);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_TIM4);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM4);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM4);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM3);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM3);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM3);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_TIM3);


    TIM_TimeBaseStructure.TIM_Period = 0xFFFFFFFF;  // autoreload
    TIM_TimeBaseStructure.TIM_Prescaler = 89;  // results in a captured value of microseconds
    TIM_TimeBaseStructure.TIM_ClockDivision = 1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

    TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_BothEdge;
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitStructure.TIM_ICFilter = 0x0;
    TIM_ICInit(TIM3, &TIM_ICInitStructure);
    TIM_CCxCmd(TIM3, TIM_Channel_1, TIM_CCx_Enable);
    TIM_ICInit(TIM4, &TIM_ICInitStructure);
    TIM_CCxCmd(TIM4, TIM_Channel_1, TIM_CCx_Enable);
    
    TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;
    TIM_ICInit(TIM3, &TIM_ICInitStructure);
    TIM_CCxCmd(TIM3, TIM_Channel_2, TIM_CCx_Enable);
    TIM_ICInit(TIM4, &TIM_ICInitStructure);
    TIM_CCxCmd(TIM4, TIM_Channel_2, TIM_CCx_Enable);
    
    TIM_ICInitStructure.TIM_Channel = TIM_Channel_3;
    TIM_ICInit(TIM3, &TIM_ICInitStructure);
    TIM_CCxCmd(TIM3, TIM_Channel_3, TIM_CCx_Enable);
    TIM_ICInit(TIM4, &TIM_ICInitStructure);
    TIM_CCxCmd(TIM4, TIM_Channel_3, TIM_CCx_Enable);

    TIM_ICInitStructure.TIM_Channel = TIM_Channel_4;
    TIM_ICInit(TIM3, &TIM_ICInitStructure);
    TIM_CCxCmd(TIM3, TIM_Channel_4, TIM_CCx_Enable);
    TIM_ICInit(TIM4, &TIM_ICInitStructure);
    TIM_CCxCmd(TIM4, TIM_Channel_4, TIM_CCx_Enable);

    TIM_Cmd(TIM3, ENABLE);
    TIM_ITConfig(TIM3, TIM_IT_CC1, ENABLE);
    TIM_ITConfig(TIM3, TIM_IT_CC2, ENABLE);
    TIM_ITConfig(TIM3, TIM_IT_CC3, ENABLE);
    TIM_ITConfig(TIM3, TIM_IT_CC4, ENABLE);

    TIM_Cmd(TIM4, ENABLE);
    TIM_ITConfig(TIM4, TIM_IT_CC1, ENABLE);
    TIM_ITConfig(TIM4, TIM_IT_CC2, ENABLE);
    TIM_ITConfig(TIM4, TIM_IT_CC3, ENABLE);
    TIM_ITConfig(TIM4, TIM_IT_CC4, ENABLE);

    TIM3->SR = 0;
    TIM4->SR = 0;
    timeOfLastCapture = 0;

    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = configMIDDLE_PRIORITY_INTERRUPT;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = configMIDDLE_PRIORITY_INTERRUPT;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

extern "C" void TIM3_IRQHandler(void)
{
    if (irqCaptureObject != NULL) {
        irqCaptureObject->irqHandler(CaptureTimerIndex::TIMER3);
    }
}

extern "C" void TIM4_IRQHandler(void)
{
    if (irqCaptureObject != NULL) {
        irqCaptureObject->irqHandler(CaptureTimerIndex::TIMER4);
    }
}

void PwmCapture::irqHandler(CaptureTimerIndex timerIndex) {
    for (int channel = 0; channel<4; channel++) {
        irqChannelHandler(timerIndex, channel);
    }
}

void PwmCapture::irqChannelHandler(CaptureTimerIndex timerIndex, int channel) {

    TIM_TypeDef *timer;
    if (timerIndex == CaptureTimerIndex::TIMER3) timer = TIM3;
    else if (timerIndex == CaptureTimerIndex::TIMER4) timer = TIM4;
    else return;

    uint32_t status = timer->SR & 0xFFFFFFFF;
    timer->SR = (uint16_t)~(TIM_SR_TIF | TIM_SR_UIF);

    uint16_t statusFlag;
    uint32_t ccRegister;
    uint16_t polarity;
    switch (channel) {
        case 0:
            ccRegister = timer->CCR1;
            statusFlag = TIM_FLAG_CC1;
            polarity = TIM_CCER_CC1P;
            break;
        case 1:
            ccRegister = timer->CCR2;
            statusFlag = TIM_FLAG_CC2;
            polarity = TIM_CCER_CC2P;
            break;
        case 2:
            ccRegister = timer->CCR3;
            statusFlag = TIM_FLAG_CC3;
            polarity = TIM_CCER_CC3P;
            break;
        case 3:
            ccRegister = timer->CCR4;
            statusFlag = TIM_FLAG_CC4;
            polarity = TIM_CCER_CC4P;
            break;
        default:
            return;
    }

    uint16_t value = 0;
    if (status & (statusFlag)) {
        status &= ~statusFlag;
        value = ccRegister & 0xFFFF;
        timer->SR = (uint16_t)~(statusFlag | (statusFlag << 8));  // clear interrupt flag and overflow flag
        if (!(timer->CCER & polarity)) {
            chanRisingCount[timerIndex][channel] = value;
            timer->CCER |= polarity;
        } else {
            if (value > chanRisingCount[timerIndex][channel]) {
                chanPulseWidth[timerIndex][channel] = value - chanRisingCount[timerIndex][channel];
            } else {
                chanPulseWidth[timerIndex][channel] = 0xFFFF-chanRisingCount[timerIndex][channel] + value;
            }
            timer->CCER &= ~polarity;

            // TODO  Remember to check for a pulse width > ~3ms;
            timeOfLastCapture = xTaskGetTickCountFromISR();

        }
    }
}

float PwmCapture::getChannelValueZeroToOne(ChannelEnum channel) {
    float value;
    if (testMode) {
        value = (testChannelValues[channel.getValue()] + 1.0f) * 1000.0f;
    } else {
        uint32_t intValue;
        if (channel.getValue() <= 3) intValue = chanPulseWidth[0][channel.getValue()];
        else intValue = chanPulseWidth[1][channel.getValue() - 4];
        value = intValue;
        if (value > 2200.0f) {
            value = lastGoodCaptureValue[channel.getValue()];
        } else {
            lastGoodCaptureValue[channel.getValue()] = value;
        }
    }

    value = (value - 1000.0f)/1000.0f;
    return value;
}

void PwmCapture::TEST_ONLY_setChannelValueZeroToOne(ChannelEnum channel, float value) {
    testChannelValues[channel.getValue()] = value;
}

bool PwmCapture::isReceiverSignalOK() {
    long timeNow = xTaskGetTickCount();
    return (timeNow - timeOfLastCapture) < 1000;
}
