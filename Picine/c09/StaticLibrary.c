/////static libraries

// Libraries are collections of precompiled functions that have been written to be reusable. Typically, they consist of sets of related functions to perform a common task.

//Standard system libraries are usually stored in /lib and /usr/lib. The C compiler (or more exactly, the linker) needs to be told which libraries to search, because by default it searches only the standard C library.

//A library filename always starts with lib. Then follows the part indicating what library this is (like c for the C library, or m for the mathematical library). The last part of the name starts with a dot (.), and specifies the type of the library:
//❑ .a for traditional, static libraries
//❑ .so for shared

//Static Libraries is The simplest form of library is just a collection of object files kept together in a ready-to-use form. When a program needs to use a function stored in the library, it includes a header file that declares the function. The compiler and linker take care of combining the program code and the library into a single executable program.

//Static libraries, also known as archives, conventionally have names that end with .a

//You can create and maintain your own static libraries very easily by using the ar (for archive) program and compiling functions separately with gcc -c. Try to keep functions in separate source files as much as possible

//##################################################
//In this example, you create your own small library containing two functions and then use one of them in an example program. The functions are called khalid and Otman and just print greetings.

//1. First, create separate source files (imaginatively called Otman.c and khalid.c) for each function. Here’s the first:
           #include <stdio.h>
           void khalid(int arg)
           {
               printf("Khalid: we passed %d\n", arg);
           }
//And here’s the second:
           #include <stdio.h>
           void otman(char *arg)
           {
               printf("Otman: we passed %s\n", arg);
           }
//2. You can compile these functions individually to produce object files ready for inclusion into a library. Do this by invoking the C compiler with the -c option, which prevents the compiler from trying to create a complete program. Trying to create a complete program would fail because you haven’t defined a function called main.

//$gcc -c otman.c khalid.c 
//$ls *.o
//otman.o khalid.o
//3. Now write a program that calls the function otman. First, it’s a good idea to create a header file for your library. This will declare the functions in your library and should be included by all applications that want to use your library. It’s a good idea to include the header file in the files khalid.c and otman.c too. This will help the compiler pick up any errors.

           /*
               This is lib.h. It declares the functions fred and bill for users
  
*/
#ifndef LIB_H
#define LIB_H
       void bill(char *);
       void fred(int);
#endif
//4. The calling program (program.c) can be very simple. It includes the library header file and calls one of the functions from the library.
       #include <stdlib.h>
       #include “lib.h”
int main() {
           otman("Hello World");
exit(0); 
}
//5. You can now compile the program and test it. For now, specify the object files explicitly to the compiler, asking it to compile your file and link it with the previously compiled object module bill.o.

//$gcc -c program.c
//$gcc -o program program.o bill.o $ ./program
//bill: we passed Hello World
$
//6. Now you’ll create and use a library. Use the ar program to create the archive and add your object files to it. The program is called ar because it creates archives, or collections, of individual files placed together in one large file. Note that you can also use ar to create archives of files of any type. (Like many UNIX utilities, ar is a generic tool.)

// $ar crv libfoo.a bill.o fred.o a - bill.o
//a - fred.o

//7. The library is created and the two object files added. To use the library successfully, some systems, notably those derived from Berkeley UNIX, require that a table of contents be created for the library. Do this with the ranlib command. In Linux, this step isn’t necessary (but it is harmless) when you’re using the GNU software development tools.

//   $ranlib libfoo.a

                                       
//Your library is now ready to use. You can add to the list of files to be used by the compiler to create your program like this:

//$ gcc -o program program.o libfoo.a $ ./program
//bill: we passed Hello World
//$
//You could also use the –l option to access the library, but because it is not in any of the standard places, you have to tell the compiler where to find it by using the –L option like this:

//$ gcc –o program program.o –L. –lfoo
