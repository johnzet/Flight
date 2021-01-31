#ifndef CONFIG_H
#define CONFIG_H

#include <stm32f4xx.h>
#include <stm32f4xx_flash.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern FlagStatus watchDogResetFlag;

#define MEMORY_WRITTEN_MARKER ((uint32_t)(0x12345678))
#define CONFIG_VERSION ((uint32_t)(0x00000001))

enum class AircraftType {QUADCOPTER, HELICOPTER, AIRPLANE};

class PidConfig {
    public:
        PidConfig();
        float p, i, d;
};

class Config {
    public:
        static Config& getInstance();
        void copy(Config& configSrc);
        AircraftType aircraftType;
        float dt;
        PidConfig pitchPid;
        PidConfig rollPid;
        PidConfig yawPid;
        float magXOffset, magXRange;
        float magYOffset, magYRange;
        float magDeclination;

        float tailMax, tailMin;
        bool tailReverse;
        
        float altimeterFeedback;
        float compassFeedback;
        float gps2posFeedback;
        float gps2velFeedback;
        float accel2frameFeedback;
        float accel2gyroFeedback;

        void getConfig(Config& config);
        void setConfig(Config& config);
        void loadDefaults();
        bool loadConfigFromFlash();
        void loadLatest();
        void saveConfigToFlash();
        void printConfig();
        bool isConsoleEnabled();
        void setConsoleEnabled(bool enabled);

        bool processGetSet(char* command, char* axisStr, char* propertyStr, char* valueStr);

    private:
        Config();
        const char* getAircraftTypeName(AircraftType aircraftType);

        uint32_t flashSector; //FLASH_SECTOR  FLASH_Sector_23
        uint32_t baseFlashAddress; // BASE_ADDRESS_SECTOR_23 0x081E0000

        // testing
        void setUseTestFlashBank(bool useTestBank);
        friend void test_CliReadWrite();
        bool consoleEnabled;
};

#define VOLTAGE_RANGE VoltageRange_3

#endif