#include "libft.h"

void	ft_cat(int fd)
{
	char	buf[BUF_SIZE + 1];
	int	ret;

	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		ft_putstr(buf, 0, 1);
	}
}
void	ft_open(int ac, char **av, int	i, char **tab_err)
{
	int		fd;

	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
			ft_putstr(tab_err[errno], av[i], 2);
		else
		{
			ft_cat(fd);
			close(fd);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	**tab_err;

	if (ac > 1)
	{
		tab_err = init_tab_err();
		ft_open(ac, av, 1, tab_err);
		free_tab_err(tab_err);
	}
	else
		ft_cat(0);
	return (0);
}
