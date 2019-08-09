#ifndef MSPLIB_H
#define MSPLIB_H
#include <msp430fr6989.h>
#endif

#define SAMPLES_NUMBER 100

int __attribute__ ((persistent)) samples[SAMPLES_NUMBER] = {0, 27, 91, 27, 43, 44, 5, 68, 2, 30, 40, 61, 92, 18, 88, 43, 2, 35, 24, 17, 32, 29, 79, 70, 63, 41, 0, 91, 22, 6, 63, 71, 98, 14, 35, 67, 60, 34, 41, 70, 89, 24, 54, 58, 64, 84, 14, 0, 53, 92, 22, 22, 20, 71, 94, 50, 19, 18, 87, 47, 79, 48, 9, 78, 37, 19, 35, 26, 99, 30, 91, 76, 90, 99, 82, 74, 31, 28, 80, 24, 39, 40, 58, 10, 74, 28, 29, 73, 9, 49, 33, 37, 66, 48, 86, 21, 7, 99, 60, 69};
int __attribute__ ((persistent)) current_sample = 0;

int get_sample(){
    int sample = samples[current_sample];
    current_sample = (current_sample + 1) % SAMPLES_NUMBER;
    return sample;
}

void reset_sensor(){
    current_sample = 0;
}
