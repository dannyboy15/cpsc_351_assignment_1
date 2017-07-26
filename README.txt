Daniel Bravo <bravod@csu.fullerton.edu>,
Colbert Chu <colbertchu@csu.fullerton.edu>
Anthony Hernandez <herankoana@csu.fullerton.edu>
Peter Vu <vupeter@csu.fullerton.edu>

CPSC 351 - Summer 2017, Assignment 1

p1-PACD1

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

Downloaders Programs
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
urls.txt
-------
Serial Downloader

real    50m28.821s
user    0m50.761s
sys     4m3.204s

Parallel Downloader

real    19m29.559s
user    0m35.223s
sys     3m24.066s

urls-10.txt
-----------
Serial Downloader

real    5m33.069s
user    0m3.125s
sys     0m12.666s

Parallel Downloader

real    1m10.315s
user    0m2.213s
sys     0m8.758s

Questions
=========
1. In the output of time, what is the difference between real, user, and sys times?
    a. Real time refers to the total amount of time that occurs from when the call is first made until the call terminates. This includes any time that is spent by subprocesses or waiting for I/O. If a subprocess stalls or is blocked, it is counted in this time.
    User time refers to the amount of CPU time when it is in user-mode. It only counts the time of the actual process and doesn't include time spent on other subprocesses.
    Sys time refers to the amount of CPU time when it is being used by the kernel. This includes tasks such as wrting to the hardrive or allocating memory.

2. Which is longer: user time or sys time? Use your knowledge to explain why.
    a. For both the serial and parallel downloader, the sys time was greater than the user time. This is a result of the the type of work that the program is doing. The user-mode task are small, simply starting other processes. The kernel, on the other hand is Is managing the multiple processes that the program created.

3. When downloading the files above, which downloader finishes faster? Why? Please Explain.
    a. Of the two downloaders, the parallel downloader finished faster. This is because it was able to tabke advantage of its parallel structure to download the files at the same time. The serial downloader had to wait after one file was downloaded before starting the next one.

4. Repeat the experiment for 10 files (any reasonably large-sized les, e.g., 100 MB, will do). Is the downloader in the previous question still faster? If not so, why? Please Explain.
    a.

Hard Time/drama? Please explain your hard times and how you conquered them. 
