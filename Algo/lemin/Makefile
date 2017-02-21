# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 16:24:50 by jsivanes          #+#    #+#              #
#    Updated: 2016/12/28 14:50:34 by jsivanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc -Wextra -Werror -Wall
HEAD = -I.
H_LIBFT = libft/header/
C_FILES = main.c clear_lem.c ft_verif_lem.c parse_join.c parse_join2.c \
		  parse_sharp.c parse_room.c bonus_lemin.c resolve_lem.c\
		  resolve_lem2.c roaming.c clear_lem2.c

OBJ = $(C_FILES:.c=.o)

LIBFT = -Llibft -I$(H_LIBFT) -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) $^ $(HEAD) $(LIBFT)

%.o: %.c
	@$(CC) -I$(HEAD) -I$(H_LIBFT) -o $@ -c $<

.PHONY: clean fclean re

clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all
