gcc -c *.c
ar arc libft.a *.o 
rm *.o
# what is the difference between arc , rv
# “The options rv indicate that we want to replace members of the archive with the object files listed and that ar should verbosely echo its actions. We can use the replace option even though the archive doesn't exist. The first argument after the options is the archive name followed by a list of object files. (Some versions of ar also require the "c" option, for create, if the archive does not exist but GNU ar does not.) The two lines following the ar command are its verbose output indicating the object files were added.

# Using the replace option to ar allows us to create or update an archive incrementally:

# $ar rv libcounter.a counter.o
# r - counter.o
# $ ar rv libcounter.a lexer.o
# r - lexer.o
# Here ar echoed each action with "r" to indicate the file was replaced in the archive.

# A library can be linked into an executable in several ways. The most straightforward way is to simply list the library file on the command line. The compiler or linker will use the file suffix to determine ”

