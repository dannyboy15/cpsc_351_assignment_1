p1-PACD1

Language: C++
Willing to Volunteer: Yes

Files
=====
* run
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
        ii. Copy the path and paste it in the cpp file.
    b. Open the cpp files and set `urlsFile` to path of urls file.
        i. Inlcuded is 4 standard files (urls.txt) or 10 large files (urls-10.txt)
2. Run the "run-downloaders" bash script (`bash run-downloaders`)

Execution Times
===============


Questions
=========
1. In the output of time, what is the difference between real, user, and sys times?
    a. Real time refers to the total amount of time that occurs from when the call is first made until the call terminates. This includes any time that is spent by subprocesses or waiting for I/O. If a subprocess stalls or is blocked, it is counted in this time.
    User time refers to the amount of CPU time when it is in user-mode. It only counts the time of the actual process and doesn't include time spent on other subprocesses.
    Sys time refers to the amount of CPU time when it is being used by the kernel. This includes tasks such as wrting to the hardrive or allocating memory.

2. Which is longer: user time or sys time? Use your knowledge to explain why.
    a. 

3. When downloading the files above, which downloader finishes faster? Why? Please Explain.
    a.

4. Repeat the experiment for 10 files (any reasonably large-sized les, e.g., 100 MB, will do). Is the downloader in the previous question still faster? If not so, why? Please Explain.
    a.

Hard Time/drama? Please explain your hard times and how you conquered them. 
