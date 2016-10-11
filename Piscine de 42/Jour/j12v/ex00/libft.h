#ifndef LIBFT_H
# define LIBFT_H

#define BUF_SIZE 10
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_display_file(int fd);

#endif
