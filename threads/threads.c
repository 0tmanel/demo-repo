/*

What is the point of threads? We obviously need processes, since they are the abstraction of a running program. But why decouple the unit of execution and introduce threads? There are six primary benefits to multithreading:

1 : Programming abstraction
Dividing up work and assigning each division to a unit of execution (a thread) is a natural approach to many problems. Design patterns that utilize this approach in‐ clude the thread-per-connection and thread pool patterns. Programmers find these patterns useful and intuitive. Some, however, view threads as an anti-pattern. The inimitable Alan Cox summed this up well with the quote, “threads are for people who can’t program state machines.” That is, there is in theory no programming problem that is solvable with threads that isn’t solvable with a state machine.

2 : Parallelism
In machines with multiple processors, threads provide an efficient way to achieve true parallelism. As each thread receives its own virtualized processor and is an independently schedulable entity, multiple threads may run on multiple processors at the same time, improving a system’s throughput. To the extent that threads are used to achieve parallelism—that is, there are no more threads than processors— the “threads are for people who can’t program state machines” maxim does not apply.
 
3: Improving responsiveness

Even on a uniprocessor machine, multithreading can improve a process’s respon‐ siveness. In a single-threaded process, a long-running operation can prevent an application from responding to user input, making it appear as if the application has froze. With multithreading, such operations may be delegated to worker threads, allowing at least one thread to remain responsive to user input and perform UI operations.

4: Blocking I/O

This is related to the previous item. Without threads, blocking I/O halts the entire process. This can be detrimental to both throughput and latency. In a multithreaded process, individual threads may block, waiting on I/O, while other threads continue to make forward progress. Asynchronous and nonblocking I/O are alternative sol‐ utions to threads for this issue.

5:Context switching

The cost of switching from one thread to a different thread within the same process is significantly cheaper than process-to-process context switching.

6: Memory savings

Threads provide an efficient way to share memory yet utilize multiple units of execution. In this manner they are an alternative to multiple processes.



1. Threads
A thread is the smallest unit of execution within a process. It’s like a lightweight sub-process that can run in parallel with other threads. A program (process) can have multiple threads that execute concurrently.

Process: A running program (with its own memory space, resources, etc.)
Thread: A single sequence of execution within that process.
Why use threads?
Concurrency: Threads allow multiple tasks to run in parallel, taking advantage of multi-core processors. For example, while one thread waits for data from a file or a network request, another thread can do some work in the meantime.
Efficiency: Threads share the same memory space (within the same process), so they can communicate with each other more easily than separate processes.
Example of threads in action:
Imagine a web server handling multiple user requests at the same time. Each user request could be handled by a different thread. While one thread processes one request, another can start processing the next request without waiting for the first to finish.

Key Thread Concepts:
Main thread: The thread that starts the execution of a program.
Child threads: Any threads created by the main thread or other threads.
Thread lifecycle: Threads go through various states: ready, running, waiting, and terminated.

2. Locks
A lock is a mechanism used to ensure that only one thread at a time can access a critical section of code (a shared resource). Locks are essential to prevent race conditions—problems that occur when multiple threads try to modify shared data at the same time.

When a thread locks a resource, other threads are prevented from accessing it until the lock is released. This ensures the integrity of data and prevents conflicts.

Why use locks?
Without locks, multiple threads might try to modify the same data simultaneously, leading to unpredictable results (e.g., inconsistent data, crashes). Locks make sure that only one thread can access critical code (or shared data) at a time, preventing this kind of issue.

Types of Locks:
Mutex (Mutual Exclusion): A lock that allows only one thread to access a resource at a time. Other threads have to wait for the mutex to be released before they can access the resource.
Read/Write Locks: These allow multiple threads to read a resource simultaneously, but only one thread can write to it at a time.
Spinlocks: A type of lock where the thread continuously checks (spins) if the lock is available. Spinlocks can be faster than regular locks in certain cases but can cause performance issues if overused.
Example of a lock in action:
Let's say two threads are trying to update a bank account balance at the same time. Without a lock, both threads could read the balance, calculate the new balance, and write it back simultaneously, potentially causing an incorrect result. By using a lock, you can ensure that only one thread can update the balance at a time.

##############################CONCURRENCY################


Concurrency refers to the ability of a system to handle multiple tasks or operations at the same time, but not necessarily simultaneously. It’s about managing tasks that can be in progress at the same time, and potentially interleaving them to make efficient use of resources.

In computing, concurrency involves dealing with multiple tasks or processes that are executing in overlapping time periods. However, it doesn't necessarily mean those tasks are running at the exact same moment (that would be parallelism). Concurrency is more about structuring your program or system to handle multiple tasks in an efficient manner.

Key points:
Concurrency is about dealing with multiple tasks at once, but not necessarily executing them at the same time.
Tasks can be split and managed in such a way that they appear to be running simultaneously (like switching between tasks quickly).
It helps improve performance, especially on systems with multiple processors or cores, but it also requires careful management to avoid conflicts (like race conditions or deadlocks).



*/