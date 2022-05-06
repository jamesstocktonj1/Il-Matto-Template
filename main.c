#include <avr/io.h>
#include <util/delay.h>

#include "include/io.h"
#include "include/serial.h"

signed short a;
int8_t b;



int main() {

    init_pins();


    while(1) {
        printf("Hello World!\n");
        
        set_led();
        _delay_ms(800);

        clear_led();
        _delay_ms(800);
    }

    return 0;
}