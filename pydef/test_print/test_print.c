#include <stdio.h>
#include <stdint.h>
#include "printf.h"

#ifndef MSPLIB_H
#define MSPLIB_H
#include <msp430fr6989.h>
#endif
long int __attribute__ ((persistent)) fram_long = 1000000;
long int volatile_long = 1000000;
int __attribute__ ((persistent)) fram_int = 1000;
int volatile_int = 1000;

void sub(){
    long int sub;
    sub = 987564;
    fram_long=sub;
}
int main(){
    sub();

    siren_command("PRINTF: fram_long %l\n", fram_long);
    siren_command("PRINTF: volatile_long %l\n", volatile_long);
    siren_command("PRINTF: fram_int %u\n", fram_int);
    siren_command("PRINTF: volatile_int %u\n", volatile_int);

    return 0;

}

