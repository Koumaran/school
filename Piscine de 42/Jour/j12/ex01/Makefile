NAME = ft_cat
SRC = main.c print.c
FLAG = -Wall -Wextra -Werror
OUTPUT = main.o print.o

all:
	gcc $(FLAG) $(SRC) -c
	gcc $(FLAG) $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(OUTPUT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
