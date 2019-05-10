#ifndef GPIO_H
#define GPIO_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define VALUE_MAX 30
#define BUFFER_MAX 3
#define DIRECTION_MAX 35 
#define LOW 0
#define HIGH 1
#define IN "in" 
#define OUT "out"

void GPIO_Export(int pin);
void GPIO_Unexport(int pin);
void GPIO_Direction(int pin, char *dir);
void GPIO_Set(int pin, int value);
void GPIO_Init(void);
void GPIO_Clean(void);
void GPIO_Unexport_All(void);

#endif
