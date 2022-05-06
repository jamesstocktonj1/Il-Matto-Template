#ifndef SERIAL_H
#define SERIAL_H

#include <stdio.h>
#include <avr/io.h>


#define BAUD_RATE 9600


void init_serial(void);

int uputchar0(char c, FILE *stream);
int ugetchar0(FILE *stream);

#endif