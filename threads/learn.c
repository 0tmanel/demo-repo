/*
Let’s get into some of the details. Say we wanted to run a program that creates two threads, each of which does some independent work, in this case printing “A” or “B”. The code is shown in Figure 26.2 (page 4).
The main program creates two threads, each of which will run the function mythread(), though with different arguments (the string A or B). Once a thread is created, it may start running right away (depending on the whims of the scheduler); alternately, it may be put in a “ready” but not “running” state and thus not run yet. Of course, on a multiprocessor, the threads could even be running at the same time, but let’s not worry about this possibility quite yet.
*/
 #include <stdio.h>
 #include <assert.h>
 #include <pthread.h>
 #include "common.h"
 #include "common_threads.h"

7 void *mythread(void *arg) {
8 printf("%s\n", (char *) arg);
9 return NULL;
10 }
11
12 int
13 main(int argc, char *argv[]) {
14 pthread_t p1, p2;
15 int rc;
16 printf("main: begin\n");
17 Pthread_create(&p1, NULL, mythread, "A");
18 Pthread_create(&p2, NULL, mythread, "B");
19 // join waits for the threads to finish
20 Pthread_join(p1, NULL);
21 Pthread_join(p2, NULL);
22 printf("main: end\n");
23 return 0;
24 }
