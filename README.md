# demo

- some general notes


- In Git, an untracked file refers to a file that exists in your working directory but is not being tracked by Git. This means that Git is not yet aware of the file, and it is not part of the version control system. Essentially, Git does not know about any changes to this file, and it won't include it in commits unless you explicitly add it to the staging area.

- gcc -O2 -g -Wall -Wextra -Werror -std=c11 -pedantic -o program program.c -lm
Breakdown of Each Flag:
-O2: Optimizes the code for better performance without excessive compilation time. This is typically a good default for non-debug builds.

-g: Includes debug symbols in the output binary, allowing you to debug the program with tools like gdb.

-Wall: Enables most commonly used warning messages, helping to catch potential issues early.

-Wextra: Enables additional warning messages that aren't included by -Wall. It helps catch more subtle problems.

-Werror: Treats all warnings as errors, ensuring that you don’t accidentally ignore any warning messages.

-std=c11: Forces the compiler to adhere to the C11 standard, which includes the latest language features and improvements. You can change this to -std=c99 or another version depending on your needs.

-pedantic: Ensures the code strictly adheres to the C standard and raises warnings or errors for non-standard code.

-o program: Specifies the output file name (program in this case). This is the name of the compiled binary that will be produced.

program.c: The source file you're compiling.

-lm: Links the math library (libm), which is needed if you're using math functions like sqrt(), sin(), etc.

