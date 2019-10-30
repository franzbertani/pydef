#include "printf.h"
#include <msp430fr6989.h>

int __attribute__ ((persist)) cc =0;

int main(){
    siren_command("START_CCOUNT: task\n");
    siren_command("GET_CCOUNT: task- %u\n", &cc);
    siren_command("PRINTF: %u\n", cc);
    return 0;
}
