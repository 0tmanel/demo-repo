

gcc -c *.c
ar rcs libft.a *.o
rm *.o
#A static library (like libft.a) is a collection of compiled 
#object files (.o files) bundled into a single file. It contains 
#reusable code that can be linked to other programs. In this case, 
#it seems like libft.a contains functions from the .c files you compiled.