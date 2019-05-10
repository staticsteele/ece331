/*
 * Steele Muchemore-Allen ECE 331 Project #1
 * Program that allows getting and setting the clock 
 * delay of the edge gpio pins from userspace. Implements 
 * kernel ioctl() for edge.
 */

#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h> 
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include "encoder.h"

//Set and Get user functions
void getDelay(int fd);
void setDelay(int fd, int *val);
 
int main(int argc, char *argv[])
{
	// arg checking
	if (argc >  2) {
		perror("Usage: Check args\n");
		return 1; 
	}

	int fd;
	int setval; 
	int *ip;

	// Set value with agrv[1] 
	if (argc == 2) {
		//converts string to int for functions 
		//Check for errors here??
		setval = strtol(argv[1], NULL, 10);
		ip = &setval;

		// Open write only
		fd = open("/dev/edge", O_WRONLY);
		if (fd < 0) {
			perror("Failed to open edge device.\n");
			return 2;
		}
		setDelay(fd, ip);
	} else {	
		// Opens to get current delay
		fd = open("/dev/edge", O_WRONLY);
		if (fd < 0) {
			perror("Failed to open edge device.\n");
			return 2;
		}
		getDelay(fd);
	}
	// Cleanup
	close(fd);
	return 0;
}

void getDelay(int fd) 
{
	int ret,delay = 0;
	int *del = &delay;

	// Passes file desc., command for kernel, and ptr to store delay
	ret = ioctl(fd, EDGE_IOCGDELAY, del);
	if (ret < 0) {
		printf("EDGE_IOCGDELAY failed: %d\n", ret);
		close(fd);
		exit(EXIT_FAILURE);
	}
	printf("Clock delay is currently set to %d ms.\n", delay);
}

void setDelay(int fd, int *val)
{
	int ret;
	
	// Passes file desc., command for kernel, and ptr to val for delay
	ret = ioctl(fd, EDGE_IOCSDELAY, val);
	if (ret < 0) {
		printf("EDGE_IOCSDELAY failed: %d\n:", ret);
		close(fd);
		exit(EXIT_FAILURE);
	}
	printf("Clock delay set to %d ms.\n", *val);
}
