#ifndef LIBFT_H
# define LIBFT_H

#define BUF_SIZE 10
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

void	ft_cat(int fd);
void	ft_putstr(char *str, char *name_file, int output);

#endif
