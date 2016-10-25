# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/11 19:44:57 by jsivanes          #+#    #+#              #
#    Updated: 2016/05/14 14:44:45 by jsivanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c				\
	   ft_memccpy.c				\
	   ft_strcat.c				\
	   ft_strncat.c				\
	   ft_bzero.c				\
	   ft_memchr.c				\
	   ft_strchr.c				\
	   ft_strncmp.c				\
	   ft_isalnum.c				\
	   ft_memcmp.c				\
	   ft_strclr.c				\
	   ft_strncpy.c				\
	   ft_isalpha.c				\
	   ft_memcpy.c				\
	   ft_strcmp.c				\
	   ft_strnequ.c				\
	   ft_isascii.c				\
	   ft_memdel.c				\
	   ft_strcpy.c				\
	   ft_strnew.c				\
	   ft_isdigit.c				\
	   ft_memmove.c				\
	   ft_strdel.c				\
	   ft_strnstr.c				\
	   ft_isprint.c				\
	   ft_memset.c				\
	   ft_strdup.c				\
	   ft_strrchr.c				\
	   ft_itoa.c				\
	   ft_putchar.c				\
	   ft_strequ.c				\
	   ft_strsplit.c			\
	   ft_lstadd.c				\
	   ft_putchar_fd.c			\
   	   ft_striter.c				\
	   ft_strstr.c				\
	   ft_lstdel.c				\
	   ft_putendl.c				\
	   ft_striteri.c			\
	   ft_strsub.c				\
	   ft_lstdelone.c			\
	   ft_putendl_fd.c			\
	   ft_strjoin.c				\
	   ft_strtrim.c				\
	   ft_lstiter.c				\
	   ft_putnbr.c				\
	   ft_strlcat.c				\
	   ft_tolower.c				\
	   ft_lstmap.c				\
	   ft_putnbr_fd.c			\
	   ft_strlen.c				\
	   ft_toupper.c				\
	   ft_lstnew.c				\
	   ft_putstr.c				\
	   ft_strmap.c				\
	   ft_memalloc.c			\
	   ft_putstr_fd.c			\
	   ft_strmapi.c				\
	   ft_strsplit_lst.c		\
	   ft_strrev.c				\
	   ft_memalloc_2d.c			\
	   ft_memfree_2d.c			\
	   ft_filelen.c				\
	   ft_file_to_char.c		\
	   ft_putnbr_base.c

OBJ = $(SRCS:.c=.o)

BLUE = \033[1;34m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;34m**************\033[0;37m************\033[0;31m************\033[0m"
	@echo "\033[0;34m* ._.     ._. \033[0;37m.__  .____. \033[0;31m.________. *\033[0m"
	@echo "\033[0;34m* | |     | | \033[0;37m|  \ | ___| \033[0;31m|________| *\033[0m"
	@echo "\033[0;34m* | |     | | \033[0;37m|__/ | |_.  \033[0;31m    | |    *\033[0m"
	@echo "\033[0;34m* | |___. | | \033[0;37m|  \ | __|  \033[0;31m    | |    *\033[0m"
	@echo "\033[0;34m* |_____| |_| \033[0;37m|__/ |_|    \033[0;31m    |_|    *\033[0m"
	@echo "\033[0;34m**************\033[0;37m************\\033[0;31m************\033[0m"
	@echo "		BY SIVANESAN 2016 "
	@ar rc $@ $^
	@ranlib $@

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $?

.PHONY: clean fclean re

clean:
	@echo "File .o cleaned"
	@rm -f $(OBJ)

fclean: clean
	@echo "Executable libft deleted"
	@rm -f $(NAME)
	
re: fclean all

