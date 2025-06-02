to detect memory leak or buffer overflow, or stack overflow use this command : 

 # gcc -g -fsanitize=address -fno-omit-frame-pointer -o myprogram myprogram.c



# The "-fsanitize=address" flag enables AddressSanitizer, a runtime memory error detector designed to find memory-related bugs such as:

Heap buffer overflows

Stack buffer overflows

Use-after-free errors

# When you compile your program with this flag, the compiler instruments the code to include checks that detect these types of errors at runtime. If an error is detected, AddressSanitizer provides a detailed error message, including the type of error, the memory address involved, and a stack trace to help you identify the source of the problem.

# AddressSanitizer is a powerful tool for catching elusive memory bugs that might not be immediately apparent during normal testing.


##################################

# The -fno-omit-frame-pointer flag instructs the compiler to retain the frame pointer in the generated code. By default, compilers may omit the frame pointer to optimize performance, but this can make debugging more difficult.

# Retaining the frame pointer allows debuggers and tools like AddressSanitizer to produce accurate and complete stack traces, which are invaluable when diagnosing crashes or memory errors. Without the frame pointer, stack traces may be incomplete or inaccurate, hindering your ability to trace the source of issues.

# Including this flag is especially important when debugging complex programs or when using tools that rely on accurate stack information.
