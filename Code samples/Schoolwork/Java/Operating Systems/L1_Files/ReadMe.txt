{\rtf1\ansi\ansicpg1252\cocoartf2513
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 Process Communication Issue:\
\
1. The program\'92s child process does not exit, and the parent process does not wait to receive a signal/results when the child process ends. Therefore the parent will terminate without communicating with the child process which is essential for garnering the correct result. \
2. To fix the issue from question 1, we have the child process use exit(Total) and send its signal and status (in this case it is also its calculated result) to the wait(&status) system call in the parent function before the result is calculated by adding the sum. Now the system i) waits for the termination of the child process and ii) actually retrieves the numerical results to be used.\
3. From my observation, it is when n=26, or after n=25. This is because when n is 26 or above, its child process is returning a number larger than 1 byte (255) can hold in the memory allocated to status\'92s value, that is why the number overflows and returns an incorrect value.\
4. After switching the key functions calls of the parent and child, the child now takes longer to reach byte overflow because it is dealing with the smaller half of consecutive numerical summing. From my observation the number now reaches its divisive point at n=43, or after n=42, when again its child process is returning a value larger than the allocation permitted.\
\
Race Condition Issue:\
\
1. The numbers are not correct because multiple processes have access to manipulate the same variable at the same time, which could cause the variable to have incorrect incrementation. Since in this case the incrementation is missed due to lack of synchronization, it will likely never reach 15000, hence the numbers are not correct.\
2. Theoretically, I believe the lowest bound should be 5000, as that is the minimum incrementation that a single child process will be able to perform even supposedly when the other two happens to miss correct incrementation completely. Therefore, the execution scenario that would allow the program to reach its lowest bound is when by some chance all the increments are done simultaneously.\
3. See code.}