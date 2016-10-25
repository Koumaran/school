# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/23 19:17:45 by jsivanes          #+#    #+#              #
#    Updated: 2016/08/31 18:04:55 by jsivanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jsivanes.filler

CC = gcc -Wextra -Werror -Wall
HEAD = .
H_LIBFT = libft/header
C_FILES = filler.c parse_filler.c resolver_filler.c resolver_filler_up.c\
		  resolver_filler_down.c filler_option.c

OBJ = $(C_FILES:.c=.o)

LIBFT = -Llibft -I$(H_LIBFT) -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) $^ -I$(HEAD) $(LIBFT)

%.o: %.c
	@$(CC) -I$(HEAD) -I$(H_LIBFT) -o $@ -c $<

.PHONY: clean fclean re

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
