#include "../include/i2c.h"


void init_i2c(void) {

    //set scl clock (prescaler set to 1)
    TWBR = (F_CPU / (F_SCL * 2)) - 8;

    //enable i2c
    TWCR = 0;
    TWCR |= _BV(TWEN);
}


int i2c_start(void) {

    //set start bit
    TWCR = _BV(TWSTA) | _BV(TWINT)| _BV(TWEN);

    //check for receive confirmed
    while (!(TWCR & (1 << TWINT)));

    return TWSR;
}

void i2c_stop() {

    //set stop bit
    TWCR = _BV(TWSTO) | _BV(TWINT)| _BV(TWEN);
}


int i2c_transmit(uint8_t data) {

    //set data
    TWDR = data;
    TWCR = _BV(TWINT)| _BV(TWEN);

    //wait for send
    while(!(TWCR & _BV(TWINT)));

    //return whether ack
    return TWSR;
}

uint8_t i2c_receive(uint8_t ack) {

    TWCR = _BV(TWEN);

    if(ack) {
        //set acknowledge
        TWCR |= _BV(TWEA);
    }

    //start transmission
    TWCR |= _BV(TWINT);

    //wait for data
    while(!(TWCR & _BV(TWINT)));

    //return data
    return TWDR;
}