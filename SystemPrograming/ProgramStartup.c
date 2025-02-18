//Program startup is the process that occurs when an executable program is loaded into memory and begins execution. It happens before your main() function runs. During this phase, the system and runtime environment prepare everything your program needs to execute correctly.
/*
🧩 Stages of Program Startup:
Loading the Program (by the OS)

The Operating System (OS) loads the program's instructions and data into memory.
Sets up command-line arguments (argc, argv).
Allocates memory for environment variables.
C Runtime (CRT) Initialization

Initializes global and static variables.
Sets up file descriptors: STDIN, STDOUT, STDERR.
Prepares the heap and stack.
May call constructors for global objects (in C++).
Transfer to Program Entry Point (_start)

The OS passes control to the program’s entry point, typically a function named _start(), provided by the C runtime library.
_start() handles further initialization and calls main().
Execution of main()

main(argc, argv, envp) is executed with the command-line arguments.
Program runs the user-defined logic.
Program Termination

After main() returns, _start() performs cleanup (e.g., closing file descriptors).
The program exits with a status code (e.g., return 0;).
📝 Example Program:
*/
#include <stdio.h>

int main(int argc, char **argv) {
    printf("Program started with %d arguments\n", argc);
    return 0;
}
/*
Before main(), the OS and runtime do all the startup work.
The program prints the number of arguments after the startup finishes.
🛠️ Behind the Scenes (_start and main):
The real entry point of a C program is _start(), not main().
_start() is provided by the C runtime (CRT) and is linked during compilation.
_start():
Sets up the environment.
Calls main().
Passes the return value of main() to the OS.
*/
