#ifndef SERIAL_H
#define SERIAL_H

#include <stdio.h>
#include <avr/io.h>


#ifndef BAUD_RATE
#define BAUD_RATE 9600
#endif

#ifndef BAUD_RATE1
#define BAUD_RATE1 9600
#endif


void init_serial(void);

int uputchar0(char c, FILE *stream);
int ugetchar0(FILE *stream);

#ifdef UDR1
void init_serial1(void);

int uputchar1(char c);
void uputline1(char *l);
int ugetchar1(void);
#endif

#endif