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
			/* TODO: Create a child */
			pid = fork();
			
			/* TODO: Error check to make sure the child was successfully created */
			if (pid < 0) { /* error occurred */
				fprintf(stderr, "Fork Failed\n");
				return 1;
			}
			else if (pid == 0) { /* child process */
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
				
			/*** TODO: If I am child, I will do this: ****/
			/* Call execlp() to replace my program with that specified at the command line.
			 * PLEASE NOTE: YOU CANNOT PASS cmdBuff DIRECTLY to execlp(). It is because 
			 * cmdBuff is an object of type string (i.e., a class) and execlp() expects
 			 * an array of characters.  However, you can pass cmdBuff.c_str(), which will
			 * return an array of characters representation of the string object.
			 * 
			 * Also, please do not forget to error check your exelp() system calls.
			 */
			
			
			/*** TODO: If I am a parent, I will do the following ***/
			/* Wait for the child process to terminate */
		}
	}
	while(cmdBuff != "exit");
	
	return 0;	
}
