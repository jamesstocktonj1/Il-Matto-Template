#include "../include/spi.h"


void init_spi() {

    //set clock to 
    SPCR = _BV(SPR0);

    //set to master and enable spi
    SPCR |= _BV(MSTR) | _BV(SPE);

}

void spi_transmit(int data) {

    SPDR = data;
    while(!(SPSR & _BV(SPIF)));   
}

int spi_receive(void) {

    while(!(SPSR & _BV(SPIF)));
    return SPDR;
}