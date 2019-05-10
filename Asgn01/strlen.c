/*
 *Program that returns the length of single command line argument
 * as string of a's. Returns error if # of args != 1 is passed
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h> 

int main(int argc, char *argv[])
{
        if(argc == 1) {
	        printf("Usage: %s count\n",argv[0]);
		return 1;
	}
	if(argc > 2) {
	        printf("Pass only one argument.\n");
		return 1;
	}

        uint32_t len;
	len = strlen(argv[1]);
	printf("%d\n",len);

        return 0;
}
