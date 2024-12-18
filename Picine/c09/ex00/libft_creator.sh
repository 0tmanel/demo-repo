

gcc -c *.c
ar rcs libft.a *.o
rm *.o
#A static library (like libft.a) is a collection of compiled 
#object files (.o files) bundled into a single file. It contains 
#reusable code that can be linked to other programs. In this case, 
#it seems like libft.a contains functions from the .c files you compiled.#

#* ar is the name of a program "archiver" that creates static libraries.

#* The 'c' flag tells ar to create the library if it doesn't already exist.

#* The 'r' flag tells it to replace older object files in the library, 
#with the new object files.

#* libft.a is the name of the library. 
#The prefix "lib" and suffixe ".a" are mandatory.

#* "*.o" is equivalent to " all files whose names end with ".o". 
#This means that our library will contain all object files in our current directory.