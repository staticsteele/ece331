/*
 * Steele Muchemore-Allen ECE 331 Project #1
 * Userspace program used to send data to edge device.
 * Fork is used to create multiple processes in order to test
 * locking. Data is passed on cmd line when program runs.
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


int main(int argc, char *argv[])
{
	// arg checking
	if (argc != 2) {
		perror("usage: check args\n");
		return 1; 
	}

	int fd, wp, len;
	char * data;

	data = argv[1];
	len = strlen(data);
	
	fork();
	fork();

	// open write only
	fd = open("/dev/edge", O_WRONLY);
	if (fd < 0) {
		perror("Failed to open edge device.\n");
		return 2;
	}
	
	// write data to edge device
	wp = write(fd, data, len);
	if (wp < 0) {
		perror("Failed to write to edge device.\n");
		return 3;
	}

	// cleanup
	close(fd);
	return 0;

}
