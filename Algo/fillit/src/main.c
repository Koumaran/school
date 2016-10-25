/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:40:52 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/08 15:41:20 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static size_t	ft_filelen(char *file)
{
	size_t		i;
	int			fd;
	char		buf;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (read(fd, &buf, 1))
		i++;
	if (close(fd) == -1)
		return (0);
	return (i);
}

static char		*ft_get_tmp(char *file)
{
	char	*tmp;
	size_t	filelen;
	int		fd;

	filelen = ft_filelen(file);
	if (!(tmp = (char*)malloc(filelen + 1)))
		return (NULL);
	fd = open(file, O_RDONLY);
	read(fd, tmp, filelen);
	tmp[filelen] = '\0';
	close(fd);
	return (tmp);
}

static int		ft_check_file(char *map, int i, int sharp, int count)
{
	while (map[++i])
	{
		sharp += (map[i] == '#') ? 1 : 0;
		if ((++count % 5) == 0)
			if (map[i] != '\n')
				return (0);
		if (map[i] != '#' && map[i] != '.' && map[i] != '\n')
			return (0);
		if (count == 21)
		{
			if (sharp != 4 || map[i] != '\n')
				return (0);
			sharp = 0;
			count = 0;
		}
	}
	if (count != 20 || sharp != 4)
		return (0);
	return (1);
}

int				main(int ac, char **av)
{
	char	*map;

	if (ac == 2)
	{
		map = ft_get_tmp(av[1]);
		if (ft_check_file(map, -1, 0, 0))
			ft_tetris(map);
		else
			ft_putstr("error\n");
	}
	if (ac < 2)
		write(2, "fillit: missing file operand\n", 29);
	if (ac > 2)
		write(2, "fillit: too much files operand\n", 29);
	return (0);
}
