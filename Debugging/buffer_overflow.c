 //1 : we compile the program with the flag  -g 
// 2: and then do lldb ./a.out, after run the program with the command "run" the program will run till it crash and tells you where is the problem 

//3: (lldb) frame variable ptr
//This command prints the value and type of the variable ptr in the current stack frame.

// 4:  View the Code
//To see where you are:
//(lldb) list
//Want to see more context?

//(lldb) list 70

//5 : . Check the Backtrace
//Let’s confirm where this function was called from:

//(lldb) bt
//For now, it’ll just show main, but when you have deeper functions, this is crucial.
#include <stdio.h>

int main(void) {
    char buffer[5] = "hey";

    // Overflow: writing beyond index 4
    for (int i = 0; i <= 10; i++) {
        buffer[i] = 'A';  // ⚠️ writing beyond buffer size
    }

    printf("Buffer: %s\n", buffer);
    return 0;
}

//(lldb) breakpoint set --file buffer_overflow.c --line 22
//This tells LLDB:

//"Set a breakpoint at line 22 of the file buffer_overflow.c."
//and then run the program by "run"