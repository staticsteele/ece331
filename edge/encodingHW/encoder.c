/*
 * Steele Muchemore-Allen ECE 331 Encoder
 *
 * Encoder function takes a single command line argument
 * and encodes it in the following scheme:
 *      bits '00' --> '1010'
 *      bits '01' --> '0101'
 *      bits '10' --> '1001'
 *      bits '11' --> '0110'
 * The input is changed into an encoder string of characters.
 * stringtobin() then changes it to a binary ASCII string for stdout.
 */

#include "encoder.h"

char *encoder(char *input)
{
        int i, j, position, value, bits;
       
        int len = strlen(input);

        //allocates memory for encoded data, 4 times as big as input bytes 
        // AKS MUST check for errors here
        char *final = (char *) malloc(len * 4 + 1);
        
        if (final == NULL) {
                perror("Memory not allocated properly");
                exit(EXIT_FAILURE);
        }

        //Start filling encoded data from the bottom up
        position = len * 4 - 1;

        for(i = len - 1; i >= 0; i--) {
               
                //Looks at input chars starting at end of argv[1]
                value = *(input + i);

                for (j = 0; j < 8; j += 2) {
                        
                        //Clears all but 2 bits, shifting by 2 each time
                        bits = (value >> j) & 3;
                        
                        //Sets encoded value based on masked input bits
                        // AKS A better exists that does not require any conditionals
                        switch (bits) { 
                        case 0:
                                *(final + position) = 0xA; 
                                break;
                        case 1:
                                *(final + position) = 0x5;
                                break;
                        case 2:
                                *(final + position) = 0x9; 
                                break;
                        case 3:
                                *(final + position) = 0x6;
                                break;
                        default: 
                                break;
                        }                
                        position--;
                }
        }
        return stringtobin(final, len);
}


char *stringtobin(char *coded,int inlen)
{
        int i, j;
        char ch;
        
        int codedlen = inlen * 4;
        
        //Allocates memory 8 times greater than length of encoded string
        char *outbinary = (char *) malloc(codedlen *8 +1);
        
        if (outbinary == NULL) {
                perror("Memory not allocated properly");
                exit(EXIT_FAILURE);
        }

       *outbinary = '\0';
        
        //will create 4 bits for each "char" make in encoded string
        for (i = 0; i < codedlen; i++) {
                
                ch = *(coded+i);
                //Look at the 4 bits we made from the original 2 bits
                for(j = 3; j >= 0; j--) {
                        
                        if (ch & (1 << j))
                                strcat(outbinary,"1");
                        else 
                                strcat(outbinary,"0");
              }
        }
        return outbinary;
}       
