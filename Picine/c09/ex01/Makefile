#$(CFLAGS): This is a variable that contains the compilation flags.
 #Common flags include -Wall (enable all warnings), -Wextra 
 #(enable extra warnings), -Werror (treat warnings as errors), and others.
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = include
SRC_DIR= src
SRC = $(wildcard $(SRC_DIR)/*.c)
OBF = $(SRC:.c=.o)
#$(SRCS:.c=.o): This is a substitution reference in Make.
# It replaces all occurrences of .c with .o in the list of files in SRCS.


OBJ = libft.a
EXEC = my_program
all : $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -I$(LIB) -c $< -o $@
#$(CC) -o $@ $< is a common pattern, where $@ refers 
#to the output file(e.g., my_program or an object file 
#like foo.o), and $< is the first prerequisite (e.g., foo.c).

#In a Makefile, the target *.o means you want to match all .o files, 
#but Make doesn't directly support pattern matching in the way you're using it.
 #Instead, Make uses pattern rules with specific syntax like % to indicate 
 # "wildcard" or pattern matching.

$(OBJ) : $(OBF) 
	ar rcs $(OBJ) $(OBF)

$(EXEC): $(OBJ) $(OBF)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(OBF)


.PHONY: clean 
clean:
	rm -f $(OBF)
#“It is important to note that make cannot distinguish between 
#a file target and phony target.”
#“GNU make includes a special target, 
#.PHONY, to tell make that a target is not a real file. ”
#“Phony targets can also be thought of as shell scripts embedded in a makefile.”

.PHONY : fclean
fclean : clean
	rm -f  $(EXEC)

re: fclean all



#In a Makefile, a rule is a fundamental building block that defines
 #how to build or update a target. A rule consists of three main components:

#Target: The file that you want to create or update 
#(e.g., an object file, an executable).

#Prerequisites (Dependencies): The files that the target depends on. 
#These are usually source files or other files that must be up to date
 #before the target can be created.

#Recipe (Command): The actual commands or actions that are executed to create or 
#update the target, usually involving compiling, linking, or other shell commands.