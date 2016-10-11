#ifndef LIBFT_H
# define LIBFT_H

#define BUF_SIZE 10
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int		ft_strlen(char *str);
void	ft_putnbr(int nb);
void	ft_putstr(char *str, char *name_file, int error);
void	ft_display_file(int fd);
void	ft_open(int ac, char **av, int i, char **tab_err);
void	free_tab_err(char **tab);
char	*ft_strdump(char *str);
char	**init_tab_err(void);
void	ft_putchar(char c);
void	ft_putnbr(int nb);

#endif
