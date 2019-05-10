#include <stdio.h>
#include <string.h>

int string_reverse(char * String);
int string_upper(char * String);

// A program to show string reversal and capitalization
int main(int argc, char * argv[]){

	char str[80];

	// Copy the string to our storage
	strcpy(str, "Hello World!");
	// Print the string
	printf("%s\n", str);
	// Reverse the string
	string_reverse(str);
	printf("%s\n", str);
	// Print it again
	string_upper(str);
	printf("%s\n", str);

	return 0;
}

// Reverse a string
int string_reverse(char * String){

	// Code goes here

	return 0;

}

// Capitalize a string
int string_upper(char * String){

	// Code goes here

	return 0;

}
