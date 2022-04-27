#include <avr/io.h>
#include <util/delay.h>

#include "include/io.h"



int main() {

    init_pins();


    while(1) {
        
        set_led();
        _delay_ms(800);

        clear_led();
        _delay_ms(800);
    }

    return 0;
}