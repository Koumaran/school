/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:22:40 by jsivanes          #+#    #+#             */
/*   Updated: 2016/02/25 17:28:14 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_display_file(int fd)
{
	char	buf[BUF_SIZE + 1];
	int		ret;

	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		ft_putstr(buf);
	}
}

int		main(int ac, char **av)
{
	int		fd;

	if (ac < 2)
		ft_putstr("File name missing.\n");
	if (ac > 2)
		ft_putstr("Too many arguments.\n");
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("open() error\n");
			return (1);
		}
		ft_display_file(fd);
		if (close(fd) == -1)
		{
			ft_putstr("close() error\n");
			return (1);
		}
	}
	return (0);
}
