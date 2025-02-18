CC = gcc
FLAGS =  -Wall -Wextra -Werror
OBJ = ft_cat

all : $(OBJ)

$(OBJ) : ft_cat.o ft_cat.c
	$(CC) $(FLAGS) ft_cat.o -o $(OBJ)

ft_cat.o : ft_cat.c
	$(CC) $(FLAGS) -c ft_cat.c -o ft_cat.o 


clean :
	rm -f *.o

fclean : clean
	rm -f ft_cat