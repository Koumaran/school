/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:08:18 by atoulous          #+#    #+#             */
/*   Updated: 2016/04/23 13:05:20 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lunch_bsq(int fd)
{
	if (ft_read_first(fd))
	{
		if (ft_read_second(fd))
		{
			ft_resolve(0, 0);
			ft_print();
		}
		else
			ft_putstr("map error\n");
	}
	else
		ft_putstr("map error\n");
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;

	fd = 0;
	i = 0;
	if (ac < 2)
		ft_lunch_bsq(0);
	else
	{
		while (++i < ac)
		{
			if ((fd = open(av[i], O_RDONLY)) > -1)
			{
				ft_lunch_bsq(fd);
				close(fd);
			}
			else
				ft_putstr("map error\n");
		}
	}
	return (0);
}
