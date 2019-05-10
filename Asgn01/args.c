/*
 *Program will print all passed
 *command line arguments. 
 */


#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{

	uint32_t count;
	for(count=0; count<argc; count++)
	        printf("argv[%d]: %s\n",count,argv[count]);
		
	return 0;
}

