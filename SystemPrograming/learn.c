/*
####################HOW THE PROGRAM IS EXECUTED######################
 when you execute a program, it is typically run by the shell, but there's more to it. Here's a breakdown of what happens when you execute a program in a Unix-like system (like Linux or macOS):

1. Shell's Role in Execution:
The shell (such as Bash, Zsh, or Fish) is the program that interacts with the user, interprets commands, and launches programs.
When you type a command (e.g., ./myprogram or python myscript.py), the shell is responsible for finding the program and running it.
2. Steps Involved:
a) Command Parsing:
When you enter a command in the shell, it first parses the input. For example, when you type ./myprogram, the shell:
Identifies the program myprogram.
Determines the file path (e.g., ./ indicates the current directory).
b) Finding the Program:
The shell looks for the program in the specified location. If it's a relative or absolute path (like ./myprogram), the shell knows to look in that exact directory.
If it's a command without a path (e.g., ls, gcc), the shell checks directories listed in the $PATH environment variable to locate the program.
c) Forking a Process:
The shell forks a new process. This means the shell creates a child process that will run the program you specified.
Forking is an OS-level operation that creates a new process (essentially a clone of the shell's process).
The child process gets a copy of the shell's environment (like variables, file descriptors, etc.), but it is independent of the shell.
d) Executes the Program:
The child process calls the exec() system call (or one of its variants like execvp()) to replace itself with the program you want to run. This means the child process is now running the program, not the shell.
After exec() is called, the program's code is loaded into the process’s memory space, and the program starts running.
e) Program Execution:
The program starts executing its instructions, performing whatever task it's designed to do (like printing output, performing calculations, etc.).
The shell itself waits for the program to finish (if you run it directly from the terminal), and once the program terminates, control returns to the shell.
f) Program Exit:
When the program finishes, it exits with an exit status (usually 0 for success, non-zero for errors). This exit status is passed back to the shell.
The shell can use this exit status to determine if the program ran successfully (e.g., you can use $? to get the last program’s exit status).
3. Example:
Let's take the command ./myprogram as an example:

Shell receives: ./myprogram

The shell identifies ./myprogram as the program to execute.
Forking:

The shell creates a new process (a child process) that will run myprogram.
Executes:

The child process calls exec() to replace itself with myprogram.
Running the Program:

The program starts running in the child process's memory space.
Program Termination:

The program finishes executing and exits with an exit code.
Return to Shell:

The shell regains control, and you see the prompt again.
*/