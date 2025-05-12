/*
 * File:   main.c
 * Author: Sebastian Moosbauer
 *
 * Created on May 12, 2025, 17:21 AM
 */


#include <xc.h>

void __init(void);

static unsigned char led_mask = 0b00111100;
void main(void) {
    __init();

    while (1) {
       for(int i = 0; i < 10000; ++i){
           Nop();
       }
       LATB ^= led_mask;
    }

    return;
}

void __init(void) {
    OSCCON = 0x50;
    
    ANSELB = 0;
    TRISB &= 0b11000011;
    LATB   = 0b00010100;
}

