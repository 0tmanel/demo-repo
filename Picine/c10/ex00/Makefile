#The default target (make will look for this by default)
# is to build the ft_display_file executable.
all : ft_display_file

#To create the executable (ft_display_file),
# you first need to compile the object file main.o.
#The command gcc -o ft_display_file main.o links the object file main.o 
#to create the executable ft_display_file.
ft_display_file : main.o
	gcc -o ft_display_file main.o

#This target says that to create main.o, the source file main.c needs to be compiled.
#The command gcc -c main.c compiles the main.c file into the object file main.o.
main.o : main.c 
	gcc -c main.c
clean:
	rm -f *.o
fclean: clean
	rm -f ft_display_file
#fclean is used to clean everything up, 
#including the main binary (the ft_display_file executable). 
#This target is useful if you want to completely reset the build environment.