#include <Logger.h>
#include <CliTask.h>

LogMessage::LogMessage() {
    time = xTaskGetTickCount();
}

LogMessage::~LogMessage() {
}

Text100LogMessage::Text100LogMessage(char* msg) {
    strncpy(textMessage, msg, 99);
    textMessage[99] = NULL;
}

char* Text100LogMessage::toString(char* buffer, uint16_t length) {
    sprintf(buffer, "Ticks: %i  %s", time, textMessage);
    return buffer;
}

char* Text100LogMessage::toDataString(char* buffer, uint16_t length) {
    sprintf(buffer, "%i,%s", time, textMessage);
    return buffer;
}

uint16_t Text100LogMessage::getSize() {
    return sizeof(*this);
}

char* Text100LogMessage::getShortType() {
    return "text";
}


bool  Logger::testLogger() {
    uint32_t j=0;
    uint8_t writeVal[1];
    uint8_t readBuffer[1];
    do {
        writeVal[0] = j & 0xFF;
        SDRAM_WriteBuffer(writeVal, j, 1);
        j += 16;
    } while(j<SDRAM_SIZE);

    j = 0;
    uint8_t val;
    do {
        val = j;
        SDRAM_ReadBuffer(readBuffer, j, 1);
        j += 16;
    } while(val == readBuffer[0] && j<SDRAM_SIZE);


    return (j == SDRAM_SIZE);
}

void Logger::init() {
    RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FMC, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);

    GPIO_PinAFConfig(GPIOC, GPIO_PinSource0, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource0, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource1, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource10, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource0, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource1, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource7, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource8, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource9, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource10, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource12, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource15, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOF, GPIO_PinSource0, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOF, GPIO_PinSource1, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOF, GPIO_PinSource2, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOF, GPIO_PinSource3, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOF, GPIO_PinSource4, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOF, GPIO_PinSource5, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOF, GPIO_PinSource11, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOF, GPIO_PinSource12, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOF, GPIO_PinSource13, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOF, GPIO_PinSource14, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOF, GPIO_PinSource15, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource0, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource1, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource2, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource4, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource5, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource8, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOG, GPIO_PinSource15, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOH, GPIO_PinSource2, GPIO_AF_FMC); 
    GPIO_PinAFConfig(GPIOH, GPIO_PinSource3, GPIO_AF_FMC); 

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_Init(GPIOC, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_14 | GPIO_Pin_15;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_Init(GPIOE, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_Init(GPIOF, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_8 | GPIO_Pin_15;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_Init(GPIOG, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_Init(GPIOH, &GPIO_InitStructure);

    FMC_SDRAMTimingInitTypeDef FMC_SDRAMTimingStructure;
    FMC_SDRAMTimingStructure.FMC_LoadToActiveDelay = 2;
    FMC_SDRAMTimingStructure.FMC_ExitSelfRefreshDelay = 7;
    FMC_SDRAMTimingStructure.FMC_SelfRefreshTime = 4;
    FMC_SDRAMTimingStructure.FMC_RowCycleDelay = 7;
    FMC_SDRAMTimingStructure.FMC_WriteRecoveryTime = 2;
    FMC_SDRAMTimingStructure.FMC_RPDelay = 2;
    FMC_SDRAMTimingStructure.FMC_RCDDelay = 2;
    
    FMC_SDRAMInitTypeDef  FMC_SDRAMInitStructure;
    FMC_SDRAMInitStructure.FMC_Bank = FMC_Bank1_SDRAM;
    FMC_SDRAMInitStructure.FMC_ColumnBitsNumber = FMC_ColumnBits_Number_8b;
    FMC_SDRAMInitStructure.FMC_RowBitsNumber = FMC_RowBits_Number_12b;
    FMC_SDRAMInitStructure.FMC_SDMemoryDataWidth = FMC_SDMemory_Width_16b;
    FMC_SDRAMInitStructure.FMC_InternalBankNumber = FMC_InternalBank_Number_4;
    FMC_SDRAMInitStructure.FMC_CASLatency = FMC_CAS_Latency_3;
    FMC_SDRAMInitStructure.FMC_WriteProtection = FMC_Write_Protection_Disable;
    FMC_SDRAMInitStructure.FMC_SDClockPeriod = FMC_SDClock_Period_2;
    FMC_SDRAMInitStructure.FMC_ReadBurst = FMC_Read_Burst_Disable;
    FMC_SDRAMInitStructure.FMC_ReadPipeDelay = FMC_ReadPipe_Delay_1;
    FMC_SDRAMInitStructure.FMC_SDRAMTimingStruct = &FMC_SDRAMTimingStructure;
    FMC_SDRAMInit(&FMC_SDRAMInitStructure);
    while(FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) != RESET) {}
          
    FMC_SDRAMCommandTypeDef  FMC_SDRAMCommandStructure;
    FMC_SDRAMCommandStructure.FMC_CommandMode = FMC_Command_Mode_CLK_Enabled;
    FMC_SDRAMCommandStructure.FMC_CommandTarget = FMC_Command_Target_bank1;
    FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber = 1;
    FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = 0;
    FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);  
    while(FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) != RESET) {}

    FMC_SDRAMCommandStructure.FMC_CommandMode = FMC_Command_Mode_PALL;
    FMC_SDRAMCommandStructure.FMC_CommandTarget = FMC_Command_Target_bank1;
    FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber = 1;
    FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = 0;
    FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);  
    while(FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) != RESET) {}

    FMC_SDRAMCommandStructure.FMC_CommandMode = FMC_Command_Mode_AutoRefresh;
    FMC_SDRAMCommandStructure.FMC_CommandTarget = FMC_Command_Target_bank1;
    FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber = 4;
    FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = 0;
    FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);  

    uint32_t tmpr = (uint32_t)
        SDRAM_MODEREG_BURST_LENGTH_2          |
        SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   |
        SDRAM_MODEREG_CAS_LATENCY_3           |
        SDRAM_MODEREG_OPERATING_MODE_STANDARD |
        SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;

    while(FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) != RESET) {}
    FMC_SDRAMCommandStructure.FMC_CommandMode = FMC_Command_Mode_LoadMode;
    FMC_SDRAMCommandStructure.FMC_CommandTarget = FMC_Command_Target_bank1;
    FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber = 1;
    FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = tmpr;
    FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure); 

    while(FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) != RESET) {}
    FMC_SetRefreshCount(683);
    while(FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) != RESET) {}

    isInitted = true;
} 

Logger::Logger() {
    addressOffset = 0;
    isInitted = false;
}

Logger& Logger::getInstance()  {
    static Logger instance; 
    return instance;
}

void Logger::setId(const uint32_t id) {
    this->id = id;
}

const uint32_t Logger::getId() {
    return id;
}

void Logger::logMessage(LogMessage* msg) {
    if (!isInitted) return;
    if (addressOffset >= SDRAM_SIZE) {
        return;
    }
    uint32_t size = msg->getSize();
    SDRAM_WriteBuffer((uint8_t*)&size, addressOffset, 4);
    addressOffset += 4;
    uint8_t* buffer = (uint8_t*)msg;
    SDRAM_WriteBuffer(buffer, addressOffset, size);
    addressOffset += size;
}

void Logger::dumpLog(const char* typeStr) {
    if (!isInitted) return;
    uint32_t offset = 0;
    char charBuffer[200]; 
    while (addressOffset > offset) {
        uint32_t size = 0;
        SDRAM_ReadBuffer((uint8_t*)&size, offset, 4);
        offset += 4;

        uint8_t* msgBuffer = new uint8_t[size];
        SDRAM_ReadBuffer(msgBuffer, offset, size);
        LogMessage* msg = (LogMessage*)msgBuffer;
        if (strcmp(typeStr, msg->getShortType()) == 0) {
            printf("%s" NEWLINE, msg->toString(charBuffer, sizeof(charBuffer)));
        }
        offset += size;
        delete[] msgBuffer;
    }
}

void Logger::SDRAM_WriteBuffer(uint8_t* buffer, uint32_t address, uint32_t size) {
    uint32_t sdramAddress = (uint32_t)SDRAM_BANK_ADDR;
    memcpy((uint8_t*)(sdramAddress+address), buffer, size);
}

void Logger::SDRAM_ReadBuffer(uint8_t* buffer, uint32_t address, uint32_t size) {
    uint32_t sdramAddress = (uint32_t)SDRAM_BANK_ADDR;
    memcpy(buffer, (uint8_t*)(sdramAddress+address), size);
}

void Logger::clear() {
    addressOffset = 0;
}


