#include "libft.h"

int	get_nb(char *str)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (!str[i])
		return (nb);
	return (-1);
}

void	ft_cat(int fd)
{
	char	*buf;
	int	ret;

	buf = malloc((BUF_SIZE + 1) * sizeof(char *));
	ret = 1;
	if (fd > 0)
	{
		ft_putstr("==> ");
		ft_putstr(str);
		ft_putstr(" <==\n");
	}	
	while (ret)
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		ft_putstr(buf);
	}
}

void	ft_tail(int ac,char **av, char **tab_err, int i)
{
	int	nb;

	nb = get_nb(av[2]);
	if (nb < 0)
		ft_putstr("invalid number of bytes\n", av[2], 2);
	else if (ac == 3)
		ft_cat(0);
	else
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY, I			
	
}
int	main(int ac, char **av)
{
	char	**tab_err;

	tab_err = init_tab_err();
	if (ac < 3 || (ac > 2 && av[1] == "-c\0"))
		ft_putstr("option requires an argument -- c\n", 0, 2);
	else if (ac > 2)
			ft_tail(ac, av, tab_err, 3);
	free_tab_err(tab_err);
	return (0);
}
