/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:27:05 by jsivanes          #+#    #+#             */
/*   Updated: 2016/04/08 17:06:18 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cat(int fd)
{
	char	buf;

	while (read(fd, &buf, 1))
		write(1, &buf, 1);
}

void	ft_open(int ac, char **av, int i)
{
	int		fd;

	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
			ft_putstr("No such file or directory\n", av[i], 2);
		else
		{
			ft_cat(fd);
			close(fd);
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac > 1)
		ft_open(ac, av, 1);
	else
		ft_cat(0);
	return (0);
}
