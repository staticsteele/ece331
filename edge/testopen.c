/*
 * Steele Muchemore-Allen ECE 331 Project #1
 * Simple program to test and see what modes 
 * that Edge can be opened based on kernel open()
 */

#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	int fd;

	fd = open("/dev/edge", O_RDONLY);
	if (fd < 0) {
		perror("Failed to open edge O_RDONLY\n");
	}
	close(fd);

	fd = open("/dev/edge", O_RDWR);
	if (fd < 0) {
		perror("Failed to open edge O_RDWR\n");
	}
	close(fd);	

	fd = open("/dev/edge", O_WRONLY);
	if (fd < 0) {
		perror("Failed to open edge O_WRONLY\n");
	}
	close(fd);

	fd = open("/dev/edge", O_WRONLY | O_APPEND);
	if (fd < 0) {
		perror("Failed to open edge O_WRONLY | O_APPEND\n");
	}
	close(fd);

	fd = open("/dev/edge", O_WRONLY | O_CLOEXEC);
	if (fd < 0) {
		perror("Failed to open edge O_WRONLY | O_CLOEXEC\n");
	}
	close(fd);

	fd = open("/dev/edge", O_WRONLY | O_CREAT);
	if (fd < 0) {
		perror("Failed to open edge O_WRONLY | O_CREAT\n");
	}
	close(fd);

	fd = open("/dev/edge", O_WRONLY | O_NONBLOCK);
	if (fd < 0) {
		perror("Failed to open edge O_WRONLY | O_NONBLOCK\n");
	}
	close(fd);

	return 0;
}
