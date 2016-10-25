NAME = ft_tail
SRCS = *.c
FLAG = -Wall -Wextra -Werror
OBJ = *.o

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRCS) -c
	gcc $(FLAG) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
