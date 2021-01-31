#ifndef LOGGER_H
#define LOGGER_H

#include <__cross_studio_io.h>
#include <stm32f4xx.h>
#include <stm32f4xx_conf.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>

#define SDRAM_BANK_ADDR     ((uint32_t)0xC0000000)
#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000) 
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200) 
#define SDRAM_SIZE (1024*1024*8)

class LogMessage {
  public: 
    LogMessage();
    long time;
    virtual ~LogMessage();
    virtual char* toString(char* buffer, uint16_t length) = 0;
    virtual char* toDataString(char* buffer, uint16_t length) = 0;
    virtual uint16_t getSize() = 0;
    virtual char* getShortType() = 0;
};

class Text100LogMessage : public LogMessage {
  private:
    char textMessage[100];
  public:
    Text100LogMessage(char* msg);
    char* toString(char* buffer, uint16_t length);
    char* toDataString(char* buffer, uint16_t length);
    uint16_t getSize();
    char* getShortType();
};

class Logger {
  private:
    Logger();
    uint32_t addressOffset;
    uint32_t id;
    bool isInitted;
    void SDRAM_WriteBuffer(uint8_t* pBuffer, uint32_t uwWriteAddress, uint32_t uwBufferSize);
    void SDRAM_ReadBuffer(uint8_t* pBuffer, uint32_t uwReadAddress, uint32_t uwBufferSize);
    Logger(Logger const&);         // Don't Implement
    void operator=(Logger const&); // Don't implement
  public:
    static Logger& getInstance();
    void init();
    void setId(const uint32_t id);
    const uint32_t getId();
    bool testLogger();
    void logMessage(LogMessage*  msg);
    void dumpLog(const char* typeStr);
    void clear();
};

#define LOG_TEXT(text)  LogMessage* msg = new Text100LogMessage(text); Logger::getInstance().logMessage(msg); delete msg;


#endif
