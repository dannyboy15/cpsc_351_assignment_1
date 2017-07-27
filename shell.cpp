/**
    CPSC 351-Summer 2017 Assignment 1
    shell.cpp
    Purpose: An interactive shell that takes a single command without arguements
    and executes it.

    @author Daniel Bravo <bravod@csu.fullerton.edu>
	@author Colbert Chu <colbertchu@csu.fullerton.edu>
	@author Anthony Hernandez <herankoana@csu.fullerton.edu>
	@author Peter Vu <vupeter@csu.fullerton.edu>
    @version 1.0 07/26/17 
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	/* The command buffer */
	string cmdBuff;
	
	/* The ID of the child process */
	pid_t pid;
	
	/* Keep running until the user has typed "exit" */
	do 
	{
		/* Prompt the user to enter the command */
		cerr << "cmd>";
		cin >> cmdBuff;
		
		/* If the user wants to exit */
		if(cmdBuff != "exit")
		{
			/* Create a child */
			pid = fork();
			
			/* Error check to make sure the child was successfully created */
			if (pid < 0) { /* error occurred */
				fprintf(stderr, "Fork Failed\n");
				return 1;
			}
			else if (pid == 0) { /* child process */
				/* Child process replace program with specified command line
					and error check the execlp() system call */
				if (-1 == execlp(("/bin/" + cmdBuff).c_str(), cmdBuff.c_str(), NULL)) {
					perror("Error");
					return 1;
				}
			}
			else { /* parent process */
			          /* parent will wait for the child to complete */
			          wait(NULL);
			          // printf("Child Complete\n");
			}
		}
	}
	while(cmdBuff != "exit");
	
	return 0;	
}
