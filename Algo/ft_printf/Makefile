# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/17 21:17:01 by jsivanes          #+#    #+#              #
#    Updated: 2016/07/26 19:22:37 by jsivanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

HEAD = -Iheader/
C_DIR = srcs
O_DIR = objdir

FLAGS = -Wall -Wextra -Werror

C_FILES = $(shell find $(C_DIR) -type f -print | grep "\.c")
C_DIRS = $(shell find $(C_DIR) -type d -print)

O_DIRS = $(C_DIRS:$(C_DIR)/%=$(O_DIR)/%)
O_FILES= $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)

all: $(NAME)

$(NAME): $(O_FILES)
	@ar rc $@ $^
	@ranlib $@

$(O_DIR)/%.o: $(C_DIR)/%.c
	@mkdir -p $(O_DIRS) $(O_DIR)
	@gcc $(FLAGS) -o $@ -c $? $(HEAD)

.PHONY: clean fclean re

clean:
	@echo "File .o of libft cleaned"
	@rm -rf $(O_DIR)

fclean: clean
	@echo "Executable libft deleted"
	@rm $(NAME)
	
re: fclean all

