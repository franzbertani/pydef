#include <stdint.h>
#include <string.h>
#include "printf.h"
#include <msp430fr6989.h>


int  __attribute__ ((persistent)) count = 0;

int main (void){
    WDTCTL = WDTPW | WDTHOLD;
    siren_command("PRINTF: Starting\n");
    int a = 0;

    while(1){
        siren_command("PRINTF: count = %u\r\n", count);
        siren_command("PRINTF: a = %u\r\n", a);
        a++;
        count++;
        __delay_cycles(1000);
    }
}
