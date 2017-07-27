Daniel Bravo <bravod@csu.fullerton.edu>
Colbert Chu <colbertchu@csu.fullerton.edu>
Anthony Hernandez <herankoana@csu.fullerton.edu>
Peter Vu <vupeter@csu.fullerton.edu>

CPSC 351 - Summer 2017, Assignment 1

Language: C++
Willing to Volunteer: Yes


Files
=====
* run-shell
* run-downloader
* shell.cpp
* serial.cpp
* parallel.cpp
* urls.txt
* urls-10.txt


Installation and Usage
======================

Shell Program
-------------
1. Run the "run-shell" bash script (`bash run-shell`)

Downloader Programs
--------------------
1. Change the program variables for the wget path and url file name.
    a. Open the cpp files and make sure the `cmdPath` variable matches the path of your wget command.
        i. To get the path to your wget command, open your CLI and type in `which wget`.
        ii. Copy the path and paste it in the cpp file for the `cmdPath` variable.
    b. Open the cpp files and set `urlsFile` to path of urls file.
        i. Inlcuded is 4 standard files (urls.txt) or 10 large files (urls-10.txt)
2. Run the "run-downloaders" bash script (`bash run-downloaders`)


Execution Times
===============
|        urls.txt       |     urls-10.txt      |                
|-----------------------|----------------------|            
|  Serial Downloader    | Serial Downloader    |            
|                       |                      |
|  real    10m18.308s   | real    5m33.069s    |                       
|  user    0m25.965s    | user    0m3.125s     |                     
|  sys     2m4.163s     | sys     0m12.666s    |          
|                       |                      |
|  Parallel Downloader  | Parallel Downloader  |
|                       |                      |
|  real    7m31.078s    | real    1m10.315s    |
|  user    0m25.502s    | user    0m2.213s     |
|  sys     2m10.318s    | sys     0m8.758s     |


Questions
=========
1. In the output of time, what is the difference between real, user, and sys times?
    a. Real time refers to the total amount of time that occurs from when the call is first made until the call terminates. This includes any time that is spent by subprocesses or waiting for I/O. If a subprocess stalls or is blocked, it is counted in this time.
    User time refers to the amount of CPU time when it is in user-mode. It only counts the time of the actual process and doesn't include time spent on other subprocesses.
    Sys time refers to the amount of CPU time when it is being used by the kernel. This includes tasks such as wrting to the hardrive or allocating memory.

2. Which is longer: user time or sys time? Use your knowledge to explain why.
    a. For both the serial and parallel downloaders, the sys time was greater than the user time (for the urls.txt about 5 times greater, for the urls-10.txt about 4 times greater). This is a result of the the type of work that the program is doing. The user-mode tasks are small, simply starting other processes. The kernel, on the other hand is in charge of managing the multiple processes that the program created. This includes switching the child processes to wget command and managing the download of the files.

3. When downloading the files above, which downloader finishes faster? Why? Please Explain.
    a. Of the two downloaders, the parallel downloader finished faster. This is because it was able to take advantage of its parallel structure to download the files at the same time. The serial downloader had to wait after one file was downloaded before starting the next one. The threads that the parallel downloader used each downloaded a file simultaneously. The serial downloader's threads each downloaded a file as well, however they did it one at a time. For example, if each file takes 5 minutes to download the serial downloader would take about 20 minutes (5 + 5 + 5 + 5), The parallel downloader would only take about 5 minutes because the files would be start downloading at about the same time and therefore finish at the same time.
    
    Serial Downloader:
    |--5min---||--5min---||--5min---||--5min---| = Total time ≈ 20 min
    |--file1--||--file2--||--file3--||--file4--|
    Parallel Downloader:
    |--5min---| = Total time ≈ 5 min
    |--file1--|
    |--file2--|
    |--file3--|
    |--file4--|

4. Repeat the experiment for 10 files (any reasonably large-sized les, e.g., 100 MB, will do). Is the downloader in the previous question still faster? If not so, why? Please Explain.
    a. Because the files being downloaded were much smaller, both downloaders finsihed faster than their counterpasrts with the previous files. However, the parallel downloader still finished faster than the serial downloader. This reason is the same as in the previous question. The serial downloaders waits until a file is downloaded before starting on the next one. The parallel downloader starts all the downloads at once.

5. Hard Time/drama? Please explain your hard times and how you conquered them.
    a. One of the challenges I had was my internet connnection. My internet connection is not very good (unstable and disconnects a lot) and slow. Because the files we were downloading were large (about 4GB) it took about an hour when I finally let it run. However, when I was first running it, I would quit the process after about 20 minutes because I thought it was stuck. When I ran the program at school, it downloaded the files in about 10 minutes (that's how I knew my program was working).
    One of my other challenges was trying to write the bash script that would run all the programs as required. I had breifly learned about bash scripting, so I had to do additional research make the script work correctly.
