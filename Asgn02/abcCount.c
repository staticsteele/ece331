/*
 *Program will search command line arguments (including argv[0])
 *for the string "abc" and will output the # of times it appears. 
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
        char str[] = "abc";
        int i, count = 0;
                 
        for (i = 0; i < argc; i++) {
                //strstr() returns NULL pointer if no matching substring
                if(strstr(argv[i],str) != NULL)
                        count++;
        }

        printf("The number of \"abc\" occurances is: %d\n",count);
        return 0;
}

