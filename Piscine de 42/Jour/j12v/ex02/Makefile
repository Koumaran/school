NAME = ft_tail
SRC = main.c print.c
FLAG = -Wall -Wextra -Werror
OUTPUT = main.o print.o
CC = gcc -o $(NAME) $(FLAG) $(SRC)

all:
	$(CC)

clean:
	/bin/rm -f $(OUTPUT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
