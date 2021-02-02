{\rtf1\ansi\ansicpg1252\cocoartf2513
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;\red255\green255\blue255;}
{\*\expandedcolortbl;;\cssrgb\c0\c1\c1;\cssrgb\c100000\c100000\c99985\c0;}
\margl1440\margr1440\vieww28600\viewh15560\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 Note:\
The folder \'91Multithreading\'92 contain source codes for multithreading methods.\
The folder \'91Singlethreading\'92 contain source codes for singlethreading methods.\
\
\
1. See Code in ThreadBots.java. It is the third thread (combos beginning with \'91v\'92) that solved the password.\
2. Each thread handled testing out a third of the possible password combinations concurrently (in separate cores). They share the same code in heap memory so no memory is allocated for any of the child processes. Between them they shared some variables such as the challenge in the parent thread, including a Boolean variable that helped optimize the time and stop the threads once the password is cracked. \
3. If we executed it as a single-threaded process, the compute time would\'92ve been O((n^4)x3) because in a worst-case scenario we would\'92ve found the password last after three quadruple-nested-loops. In multithreading we are able to avoid starting over the whole quadruple nested loop if the password does not start with an initial letter that is tested first, for example i or t. With my code, after one test execution with multithreading, the password is found typically around 300 \cf2 \cb3 milliseconds, whereas another test execution using single-threading took close to 500 milliseconds.\cf0 \cb1 \
4. In my case, single threading resolved the issue usually slightly faster than multithreading (280-440 milliseconds to multihreading\'92s typical 300-420 milliseconds). I believe this is due to the password being there early in the loop which may give single-threading the advantage of being able to catch that slightly earlier and stopping. However in a case where the password is long and complex the chances of it being there early will be slimmer and slimmer. So for a shorter password, a single thread may save you the time and trouble of multithreading, but as complexity grows multithreading is more efficient.}