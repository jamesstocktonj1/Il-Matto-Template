#ifndef SERIAL_H
#define SERIAL_H

#include <stdio.h>
#include <avr/io.h>


#define BAUD_RATE 9600
#define BAUD_RATE1 9600


void init_serial(void);

int uputchar0(char c, FILE *stream);
int ugetchar0(FILE *stream);

#ifdef UDR1
void init_serial1(void);

int uputchar1(char c);
int ugetchar1(void);
#endif

#endif