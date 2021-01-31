#ifndef CLI_H
#define CLI_H

#include <stm32f4xx.h>
#include <stm32f4xx_conf.h>
#include <FreeRTOS.h>
#include <task.h>
#include <Config.h>
#include <Logger.h>
#include <SensorTask.h>

#define CLI_PROMPT "\033[35m" ">"     
#define CLI_BUFFER_LENGTH 200
#define NEWLINE "\n\r"


class CliTask : public TaskClass {
  public:
    CliTask(SensorTask* sensorTask);
    static void initCliUsart();
    void init();
    void task();
    void irqHandler();
    void dumpUsageStmt();
    void setSensorTask(SensorTask* sensorTask);

  private:
    volatile bool commandIsReady;
    char cliCharBuffer[CLI_BUFFER_LENGTH];
    char previousCommand[CLI_BUFFER_LENGTH];
    char commandBuffer[CLI_BUFFER_LENGTH];
    bool testMode;
    SensorTask* sensorTask;

    friend void test_CliReadWrite();
    friend void test_pid_params();
    friend void test_feedback_params();
    friend void test_properties();
    void processCommand(char*buffer);
};


#endif