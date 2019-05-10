/*
 * Steele Muchemore-Allen ECE 331 
 * File contains all the functions used in encoder program 
 * to manipulate the raspberry pi gpio pins.
 */

#include "gpio.h"

//Function opens export file and writes pin name to export. 
//Checks for errors when opening and writing.
void GPIO_Export(int pin)
{
        char buffer[BUFFER_MAX];
        ssize_t bytes_written;
        int fd;

        fd = open("/sys/class/gpio/export", O_WRONLY);
        
        if (fd == -1) {
                perror("Failed to open export for writing");
                exit(EXIT_FAILURE);                                                                       
        }
        bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
        
        if (write(fd, buffer, bytes_written) == -1) {
                perror("Failed to export pin");
                GPIO_Unexport_All();
                close(fd);
                exit(EXIT_FAILURE);
        }
        close(fd);
}

//Function opens unexport file and writes pin name to unexport. 
//Checks for errors when opening and writing.
void GPIO_Unexport(int pin)
{
        char buffer[BUFFER_MAX];
        ssize_t bytes_written;
        int fd;

        fd = open("/sys/class/gpio/unexport", O_WRONLY);

        if (fd == -1) {
                perror("Failed to open unexport for writing");
                exit(EXIT_FAILURE);
        }
        bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
        
        if (write(fd, buffer, bytes_written) == -1) {
                perror("Failed to unexport pin");
                close(fd);
                exit(EXIT_FAILURE);
        }
        close(fd);
}

//Function opens direction file for pin if it was exported and writes dir. 
//Checks for errors when opening and writing.
void GPIO_Direction(int pin,char *dir)
{
        char direction[BUFFER_MAX];
        char path[DIRECTION_MAX];
        int fd;

        strcpy(direction, dir);
        snprintf(path, DIRECTION_MAX, "/sys/class/gpio/gpio%d/direction", pin);
        fd = open(path, O_WRONLY);

        if (fd == -1) {
                perror("Failed to open gpio direction for writing");
                exit(EXIT_FAILURE);                                                                                  
        }
        if (write(fd, &direction, strcmp(direction, "in") == 0 ? 2 : 3) == -1) {
                perror("Failed to set direction");
                close(fd);
                exit(EXIT_FAILURE);
        }
        close(fd);
}

//Function opens value file for pin if it was exported and writes value. 
//Checks for errors when opening and writing.
void GPIO_Set(int pin, int value)
{
        static const char values[] = "01";
        char path[VALUE_MAX];
        int fd;

        snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
        fd = open(path, O_WRONLY);
        
        if (fd == -1) {
                perror("Failed to open gpio value for writing");
                exit(EXIT_FAILURE);
        }
        if (write(fd, &values[LOW == value ? 0 : 1], 1) == -1) {
                perror("Failed to write value");
                close(fd);
                exit(EXIT_FAILURE);
        }
        close(fd);
}

//Function initializes used pins by exporting then setting them to low output.
void GPIO_Init(void)
{
        struct timespec tim, tim2;
        tim.tv_sec = 0;
        tim.tv_nsec = 99999999;        
       
        GPIO_Export(4);
        GPIO_Export(17);
        GPIO_Export(18);
        GPIO_Export(22);
        
        //Delay long enough for pins to be exportedi before writing to them
        nanosleep(&tim, &tim2);

        GPIO_Direction(4, OUT);
        GPIO_Direction(17, OUT); 
        GPIO_Direction(18, OUT);
        GPIO_Direction(22, OUT);
        
        GPIO_Set(4, LOW);
        GPIO_Set(17, LOW);
        GPIO_Set(18, LOW);
        GPIO_Set(22, LOW);

        GPIO_Set(4, HIGH);
}

//Function cleans reverts changes to pins and unexports them.
void GPIO_Clean(void)
{
        GPIO_Set(4, LOW);
        GPIO_Set(17, LOW);
        GPIO_Set(18, LOW);
        GPIO_Set(22, LOW);
        
        GPIO_Direction(4, IN);
        GPIO_Direction(17, IN); 
        GPIO_Direction(18, IN);
        GPIO_Direction(22, IN);
     
        GPIO_Unexport(4);
        GPIO_Unexport(17);
        GPIO_Unexport(18);
        GPIO_Unexport(22);
}

//Function used when pins were exported but not unexported one time through.
void GPIO_Unexport_All(void)
{
        GPIO_Unexport(4);
        GPIO_Unexport(17);
        GPIO_Unexport(18);
        GPIO_Unexport(22);
}
