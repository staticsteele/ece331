/*
 *Program finds maximum memory malloc() cna allocate without fail.
 */

#include <stdlib.h>
#include <stdio.h>

int main (void)
{
        int a, b, c,  i;
        double MB;
        void *v;
                
        //Uses a halving search, finds when i/2 bytes okay, but not i bytes.
        //Keeps looping until malloc() fails.
        for (i = 1; (v = malloc(i)) != NULL; i <<= 1)
                free(v);
        
        //Narrows down on bytes from allowed value above.
        //Bisection search.
        for (a = (i >> 1), b = i; a < (b - 1);) {
                c = (a + b) >> 1;
                //a becomes max # of bytes if malloc() doesn't fail
                if ((v = malloc(c)) != NULL) {
                        a = c;
                        free(v);
                } else {
                        b = c;
                }       
        }
        
        //Converts bytes to Mb for easier reading.
        MB = a/1e6;

        printf("Maximum allocated Megabytes: %.3lf MB\n", MB);

        return 0;
}
