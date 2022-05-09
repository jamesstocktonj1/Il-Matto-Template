#include <avr/io.h>
#include <util/delay.h>

#include "include/io.h"
#include "include/serial.h"
#include "include/i2c.h"
#include "include/spi.h"



int main() {

    init_pins();
    init_serial();
    init_serial1();


    while(1) {
        printf("Hello World!\n");
        uputline1("Hello World!\n");
        
        set_led();
        _delay_ms(800);

        clear_led();
        _delay_ms(800);
    }

    return 0;
}