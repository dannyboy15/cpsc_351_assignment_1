/**
    CPSC 351-Summer 2017 Assignment 1
    serial.cpp
    Purpose: Downloads files from specified urls using a parallel architecture.

    @author Daniel Bravo <bravod@csu.fullerton.edu>
	@author Colbert Chu <colbertchu@csu.fullerton.edu>
	@author Anthony Hernandez <herankoana@csu.fullerton.edu>
	@author Peter Vu <vupeter@csu.fullerton.edu>
    @version 1.0 07/26/17 
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fstream>
#include <vector>
using namespace std;

/**
 * Forks children and lets them perform their tasks
 * @param urls - the URLs to download
 * @param path - the path to the wget command
 */
void create_children(vector<string>& urls, string path) {	
	
	/* Counter for the number of processes */
	int numForks = 0;

	/* The process id */
	pid_t pid;
	
	/* Go through all the URLs */
	for(vector<string>::iterator urlIt = urls.begin();
			urlIt != urls.end(); ++urlIt) {

		/* Create a child */
		numForks++;
		pid = fork();

		/* Make sure the fork was a success */
		if(pid < 0) {
			perror("fork:");
			exit(1);
		}
		/* The child code */
		else if(pid == 0) {
			fclose(stdout);
			fclose(stderr);

			/* Deploy wget */
			if(execlp(path.c_str(), "wget", urlIt->c_str(), "-P", "test_downloads/p", NULL) < 0) {
				perror("execlp");
				exit(1);
			}	
		}
	}

	/* Wait until no children are left */
	while(numForks > 0) {
        wait(NULL);
        numForks--;
    }
}

/**
 * Read the URLs from the file
 * @param urls - the URLs to download
 * @param file - the filename of the URLs file
 */
void readUrls(vector<string>& urls, string file) {
	/* Open the file */
	ifstream urlFile(file.c_str());		
	
	/* The URL buffer */
	string urlBuffer;
	
	/* Make sure the file was opened */
	if(!urlFile.is_open()) {
		fprintf(stderr, "Failed to open the file");
		exit(1);
	}
	
	/* Read the entire file */
	while(!urlFile.eof()) {
		/* Read the buffer */
		urlFile >> urlBuffer;
		
		/* Are we at the end of the file */
		if(!urlFile.eof())
			urls.push_back(urlBuffer);	
	}
	
	/* Close the file */
	urlFile.close();
}

int main() {
	/* File with URLs to download */
	string urlsFile = "urls.txt";
	// string urlsFile = "urls-10.txt";

	/* Path to wget command */
	string cmdPath = "/usr/local/bin/wget"; // For macOS
	// string cmdPath = "/usr/bin/wget"; // For Linux

	/* Read the URL files */
	vector<string> urls;
		
	/* Read the URLs */
	readUrls(urls, urlsFile);
	
	/* Create child processes */
	create_children(urls, cmdPath);
	
	// printf("Complete\n");
		
	return 0;	
}
