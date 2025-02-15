FLAG = -Wall -Wextra -Werror
CC = cc
OBJ = ft_display_file

all :$(OBJ)


ft_display_file.o : ft_display_file.c
	$(CC) $(FLAG) -c ft_display_file.c

$(OBJ) : ft_display_file.o
	$(CC) $(FLAG)  ft_display_file.o -o ft_display_file
clean : 
	rm -f *.o
fclean : clean
	rm -f $(OBJ)
