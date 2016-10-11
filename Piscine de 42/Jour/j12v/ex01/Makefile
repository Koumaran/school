NAME = ft_cat
SRC = main.c print.c error.c
FLAG = -Wall -Wextra -Werror
OUTPUT = main.o print.o error.o
CC = gcc -o $(NAME) $(FLAG) $(SRC)

all:
	$(CC)

clean:
	/bin/rm -f $(OUTPUT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
