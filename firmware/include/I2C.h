#ifndef I2C_H
#define I2C_H

#include <__cross_studio_io.h>
#include <stm32f4xx.h>
#include <stm32f4xx_conf.h>
#include <exception>
#include <cstdarg>
#include <delay.h>
#include <Logger.h>

class I2C {
    private:
        I2C_TypeDef* i2Cx;
        uint8_t address;

        void start(uint8_t direction);
        void stop();
        void write(uint8_t data);
        uint8_t read_ack();
        uint8_t read_nack();

    public:
        I2C(I2C_TypeDef* i2Cx, uint8_t address);
        void write(uint8_t regstr, uint8_t bytes, uint8_t* buffer);
        void read(uint8_t regstr, uint8_t bytes, uint8_t* buffer);
        void write(uint8_t regstr, uint8_t value);
        uint8_t read(uint8_t regstr);
};

class I2cTimeoutException : public std::exception {
    public:
        I2cTimeoutException() throw() {  // put a breakpoint on this line to debug exceptions
        }
        virtual const char* what() const throw()  {
            return "I2C timeout exception thrown";
    }
};

#define I2C_WAIT_UNTIL(uSec, fn, value) {int waitTime=0; while((fn) != (value)) {if (waitTime++>(uSec)) throw(I2cTimeoutException()); delay_us(1);}}


#endif