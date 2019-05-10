//Program that will print user specified # of a's

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 

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

	uint32_t len, c;
	len = atoi(argv[1]);

	for(c = 0; c < len; c++)
	        printf("a");

	return 0;
}
