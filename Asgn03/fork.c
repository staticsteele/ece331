/*
 *Program creates child process and prints out child pid.
 */
#include <stdio.h> 
#include <unistd.h>

int main(void)
{
        pid_t pid;
        
        //Return value is 0 for child process
        if (fork() == 0){
                printf("I am the child.\n");
                pid = getpid();
                printf("Child pid is %d\n",pid);
        }
        else
                printf("I am the parent\n");

        return 0;
}

