# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/07 16:47:05 by lgosse            #+#    #+#              #
#    Updated: 2016/04/05 15:17:00 by lgosse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	push_swap.c \
			validity.c \
			swap.c \
			push.c \
			rotate.c \
			reverse_rotate.c \
			simple_sort.c \
			getsol.c \
			end.c \
			print_end.c \
			init.c \
			functions_get.c \
			predicate.c \
			sort.c \
			first_swap.c \
			third_swap.c \
			game.c

OBJ_NAME = $(SRC_NAME:.c=.o)

NAME = push_swap

SRC_PATH = src/
LIB_PATH = libft/includes/
OBJ_PATH = obj/

SRC_LIB = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -I,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
LDFLAGS = -Llibft
LDLIBS = -lft

all:$(NAME)

$(NAME):$(OBJ)
	make -C libft/
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "\033[32mCompilation done !\033[0m"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(LIB) -o $@ -c $<

clean:
	@echo "\033[31mCleaned following files :\033[0m"
	@make -C libft/ clean
	@rm -fv $(OBJ)
	@rm -rfv $(OBJ_PATH)
	@echo "\033[32mClean objects done !\033[0m"

fclean: clean
	@rm -fv $(NAME)
	@echo "\033[32mClean executable done !\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
