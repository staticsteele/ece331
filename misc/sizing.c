#include <stdio.h>

// Program that prints the sizes of data types for the current machine
int main (int argc, char * argv[]) {

	// Size of char 
	printf("The size of a char is: %d\n",sizeof(char));
	printf("The size of an int is: %d\n",sizeof(int));
	printf("The size of a short int is: %d\n",sizeof(short int));
	printf("The size of a long int is: %d\n",sizeof(long int));
	printf("The size of a double is : %d\n",sizeof(double));
	printf("The size of a float is: %d\n",sizeof(float));
	printf("The size of a char pointer is: %d\n",sizeof(char *));

	return 0;

}
