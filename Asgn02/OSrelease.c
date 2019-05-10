/*
 *Program that uses uname() to get OS release and prints it 
 */
#include <stdio.h>
#include <sys/utsname.h>

int main(void)
{
        struct utsname system;
        
        //uname call returns -1 if error occured based on documentation
	if (uname(&system) == -1) {
	        printf("uname system call failed");
		return 1;
	}

	printf("Release = %s\n",system.release);
	return 0;
}


