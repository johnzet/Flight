#include <I2C.h>

I2C::I2C(I2C_TypeDef* i2Cx, uint8_t address) {
    this->i2Cx = i2Cx;
    this->address = address;
}

void I2C::start(uint8_t direction) {
    I2C_WAIT_UNTIL(1000, I2C_GetFlagStatus(i2Cx, I2C_FLAG_BUSY), false);
    I2C_GenerateSTART(i2Cx, ENABLE);
    I2C_WAIT_UNTIL(1000, I2C_CheckEvent(i2Cx, I2C_EVENT_MASTER_MODE_SELECT), true);
    I2C_Send7bitAddress(i2Cx,   ((direction == I2C_Direction_Transmitter)? (uint8_t)((address) + 0b1) : address),   direction);
    if(direction == I2C_Direction_Transmitter){
        I2C_WAIT_UNTIL(1000, I2C_CheckEvent(i2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED), true);
    }
    else if(direction == I2C_Direction_Receiver){
        I2C_WAIT_UNTIL(1000, I2C_CheckEvent(i2Cx, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED), true);
    }
}

void I2C::write(uint8_t data) {
    I2C_SendData(i2Cx, data);
    I2C_WAIT_UNTIL(1000, I2C_CheckEvent(i2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED), true);
}

uint8_t I2C::read_ack() {
    I2C_AcknowledgeConfig(i2Cx, ENABLE);
    I2C_WAIT_UNTIL(1000, I2C_CheckEvent(i2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED), true);
    uint8_t data = I2C_ReceiveData(i2Cx);
    return data;
}

uint8_t I2C::read_nack() {
taskDISABLE_INTERRUPTS();
    I2C_AcknowledgeConfig(i2Cx, DISABLE);
    I2C_GenerateSTOP(i2Cx, ENABLE);
    I2C_WAIT_UNTIL(1000, I2C_CheckEvent(i2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED), true);
    uint8_t data = I2C_ReceiveData(i2Cx);
taskENABLE_INTERRUPTS();
    return data;
}

void I2C::stop() {
    I2C_GenerateSTOP(i2Cx, ENABLE);
}

void I2C::write(uint8_t regstr, uint8_t bytes, uint8_t* buffer) {
    start(I2C_Direction_Transmitter);
    write(regstr);
    for (uint8_t i=0; i<bytes;  i++) {
      write(*(buffer+i));
    }
    stop();
}

void I2C::read(uint8_t regstr, uint8_t bytes, uint8_t* buffer) {
    start(I2C_Direction_Transmitter);
    write(regstr);
    stop();

    start(I2C_Direction_Receiver);
    
    for (uint16_t i=0; i<bytes-1; i++) {
        *(buffer+i) = read_ack();
    }
    *(buffer+bytes-1) = read_nack();
}

void I2C::write(uint8_t regstr, uint8_t value) {
    uint8_t buffer[1];
    buffer[0] = value;
    write(regstr, 1, buffer);
}

uint8_t I2C::read(uint8_t regstr) {
    uint8_t buffer[1];
    read(regstr, 1, buffer);
    return buffer[0];
}

