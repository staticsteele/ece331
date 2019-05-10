/*
 *Program opens file from command line argument and reads
 *through it for '\n' to count total lines in file.
 */

#include <stdio.h>
 
int main(int argc, char *argv[])
{
        FILE *fp;
        int count = 0; 
        char c;

        if (argc == 1) {
                printf("No filename.\n");
                return -1;
        } else if (argc > 2) {
                printf("Too many arguements.\n");
                return -1;
        }

        //Opens file for reading with "r'"
        fp = fopen(argv[argc-1], "r");

        //If our file pointer points to nothing when opened
        if (fp == NULL) {
                printf("Could not open file %s\n", argv[argc-1]);
                return -1;
        }
        
        //As long as we dont hit EOF, keep checking char by char for '\n'
        while (!feof(fp)) {

                c = fgetc(fp);
                if (c == '\n')
                        count++;
        }

        fclose(fp);
        printf("The file %s has %d lines.\n", argv[argc-1], count);
        return 0;

}
