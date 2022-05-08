#ifndef I2C_H
#define I2C_H

#include <avr/io.h>
#include <util/twi.h>


#define F_SCL 400000

#define START_ACK 0x08

#define ADR_ACK 0x18
#define ADR_NACK 0x20

#define DATA_ACK 0x28
#define DATA_NACK 0x30

void init_i2c(void);

int i2c_start(void);
void i2c_stop(void);

int i2c_transmit(uint8_t data);
uint8_t i2c_receive(uint8_t ack);

#endif