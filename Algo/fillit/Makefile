# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/18 19:25:23 by jsivanes          #+#    #+#              #
#    Updated: 2016/08/23 19:29:21 by jsivanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc -Wall -Wextra -Werror

HEAD = inc 

H_LIBFT = libft/include

SRC = src/main.c src/ft_create_tet.c 	\
	  src/ft_tetris.c src/ft_resolve.c  \
	  src/init_map.c

OBJ = $(SRC:.c=.o)

LIBFT = -Llibft -I$(H_LIBFT) -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) $^ -I$(HEAD) $(LIBFT)

%.o: %.c
	@$(CC) -I$(HEAD) -I$(H_LIBFT) -o $@ -c $<

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

