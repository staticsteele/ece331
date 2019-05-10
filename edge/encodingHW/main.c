/*
 * Steele Muchemore-Allen ECE 331 Encoder
 *
 * Program takes a single command line argument and
 * passes it as an argument to an encoder. The encoded
 * binary string is passed back and then printed to stout.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "encoder.h"
#include "gpio.h"

int main(int argc, char *argv[])
{
        const char *encoded;
        int i, bit0, bit1;

        //time struct for 10ms from nanosleep()
        struct timespec tim, tim2;
        tim.tv_sec = 0;
        tim.tv_nsec = 10000000;
        
        //Exports used gpio pins and sets init direction/value
        GPIO_Init();

        if (argc != 2) {
                printf("Usage: %s input\n",argv[0]);
                printf("  input: chars to encode\n");
                exit(EXIT_FAILURE);
        }
        
        encoded = encoder(argv[1]);

        //Sets gpios 18 and 22 with 2 bit pairs
        for(i = 0; i < strlen(encoded); i += 2) {
                bit0 = *(encoded + i + 1) - '0';
                bit1 = *(encoded + i) - '0';
                GPIO_Set(18, bit0);
                GPIO_Set(22, bit1);
                nanosleep(&tim, &tim2);
                GPIO_Set(17, HIGH);
                nanosleep(&tim, &tim2);
                GPIO_Set(17, LOW);
        }

        //Prints encoded binary ASCII string 
        printf("%s\n",encoded);

        //Free memory allocated in encoder.c
        free((void *)encoded);

        //Unexports used gpio pins
        GPIO_Clean();

        exit(EXIT_SUCCESS);
}

