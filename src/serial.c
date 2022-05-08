#include "../include/serial.h"


void init_serial() {

    //setup baud rate
    UBRR0H = (F_CPU/(BAUD_RATE*16L)-1) >> 8;
	UBRR0L = (F_CPU/(BAUD_RATE*16L)-1);
    
    //enable tx and rx
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);

    //receive 8-bits
    UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);

    //setup input and output streams
    static FILE uout = FDEV_SETUP_STREAM(uputchar0, NULL, _FDEV_SETUP_WRITE);
	static FILE uin = FDEV_SETUP_STREAM(NULL, ugetchar0, _FDEV_SETUP_READ);

    stdout = &uout;
	stderr = &uout;
	stdin = &uin;
}


int uputchar0(char c, FILE *stream) {

    //force \r for \n
    if(c == '\n') uputchar0('\r', stream);

    //wait for register to be cleared
    while (!(UCSR0A & _BV(UDRE0)));

    //write to buffer
	UDR0 = c;
	return c;
}

int ugetchar0(FILE *stream) {

    //wait for receive
    while(!(UCSR0A & _BV(RXC0)));
	return UDR0;
}
