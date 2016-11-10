# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/26 19:26:33 by jsivanes          #+#    #+#              #
#    Updated: 2016/11/09 15:17:44 by jsivanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

CC = gcc -Wextra -Werror -Wall
HEAD = -I.
H_LIBFT = libft/header/
C_FILES = ft_list.c pab.c parse.c rab.c rrab.c sab.c \
		  operation.c swap_brute.c swap_brute_2.c\
		  swap_brute_r.c swap_selection.c swap_selection_r.c verification.c\
		  option_push_swap.c min_max.c print_ps.c lunch_push.c

OBJ = $(C_FILES:.c=.o)

LIBFT = -Llibft -I$(H_LIBFT) -lft

all: $(NAME) $(NAME2)

$(NAME): $(OBJ) $(NAME).o
	@make -C libft
	@$(CC) -o $(NAME) $^ $(HEAD) $(LIBFT)

$(NAME2): $(OBJ) $(NAME2).o
	@$(CC) -o $(NAME2) $^ $(HEAD) $(LIBFT)

%.o: %.c
	@$(CC) -I$(HEAD) -I$(H_LIBFT) -o $@ -c $<

$(NAME).o: $(NAME).c
	@$(CC) -I$(HEAD) -I$(H_LIBFT) -o $@ -c $<

$(NAME2).o: $(NAME2).c
	@$(CC) -I$(HEAD) -I$(H_LIBFT) -o $@ -c $<

.PHONY: clean fclean re

clean:
	@make clean -C libft
	@rm -f $(OBJ) $(NAME).o $(NAME2).o

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME) $(NAME2)

re: fclean all

