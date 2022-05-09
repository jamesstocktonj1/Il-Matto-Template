#ifndef SPI_H
#define SPI_H

#include <avr/io.h>


#ifndef SPI_CLK
#define SPI_CLK 1000000
#endif


void init_spi(void);

void spi_transmit(int data);
int spi_receive(void);

#endif