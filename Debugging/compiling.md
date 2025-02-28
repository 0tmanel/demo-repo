1. Enable All Warnings in Clang (Default Compiler on macOS)
Since macOS uses Clang instead of GCC, use:


clang -Wall -Wextra -Wpedantic -Werror my_program.c -o my_program
This will catch more potential bugs.

2. Install and Use Static Analysis Tools
cppcheck (Static Code Analysis)
Install it using Homebrew:


brew install cppcheck
Then run:

cppcheck --enable=all my_program.c
Clang Static Analyzer

scan-build clang my_program.c
3. Use a Debugger (LLDB instead of GDB)
macOS comes with LLDB instead of GDB:


clang -g my_program.c -o my_program
lldb ./my_program
Then inside LLDB:

sh

4. Detect Memory Errors (Valgrind Alternative)
Valgrind doesn’t work well on macOS, so use leaks or AddressSanitizer:

Using leaks (Built-in)
Run:


leaks -atExit -- ./my_program
Using AddressSanitizer
Compile with:

clang -fsanitize=address -g my_program.c -o my_program
Then run:


./my_program
It will detect memory leaks and buffer overflows.


# A core dump is a file that captures the memory of a running program when it crashes! It contains a snapshot of the program’s state, including:

# Memory contents (variables, heap, stack)
# CPU registers (current instruction, stack pointer, etc.)
# Function call stack (backtrace)
# Loaded libraries and program binary
# It’s like a frozen-in-time picture of your program right at the moment of the crash — super useful for debugging!

🧠 Why Core Dumps Happen:

# A core dump is created when a program crashes due to a fatal error, like:

# Segmentation fault (SIGSEGV) — Accessing invalid memory
# Bus error (SIGBUS) — Invalid memory alignment
# Floating-point exception (SIGFPE) — Division by zero, etc.
# Abort signal (SIGABRT) — Calling abort() explicitly
🛠 Using Core Dumps for Debugging:
After a crash, you can inspect the core file with a debugger:

Enable Core Dumps (if not already):
On Linux/macOS, run:

ulimit -c unlimited
Then, run your program. If it crashes, a core file appears in your working directory.

Analyze with LLDB or GDB:
For macOS (LLDB):

lldb -c core ./my_program
For Linux (GDB):

gdb ./my_program core
Look at the Backtrace:
In the debugger, type:

bt
# This shows the call stack at the crash point, so you can trace what function caused the crash.

🚀 Example:
Let’s crash a program intentionally:

#include <stdio.h>

int main() {
    int *ptr = NULL;    // Null pointer
    *ptr = 42;          // Dereference NULL (segmentation fault)
    return 0;
}
Compile and run:

gcc crash.c -o crash
ulimit -c unlimited
./crash
This generates a core file. You can load it into GDB:

gdb ./crash core
And see the crash point with:

bt


