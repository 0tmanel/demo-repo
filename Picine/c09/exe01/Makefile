LIB = includes
SRC_DIR= srcs
SRC = $(wildcard $(SRC_DIR)/*.c)
OBF = $(SRC:.c=.o)
all : libft.a

%.o: %.c
	cc -Wall -Wextra -Werror -I$(LIB)  -c $< -o $@


libft.a : $(OBF)
	ar rcs libft.a  $(OBF)

myprogram: libft.a $(OBF)
	cc -Wall -Wextra -Werror  -o myprogram libft.a $(OBF)

clean:
	rm -f $(OBF)

fclean: clean
	
	rm -f $(OBJ)