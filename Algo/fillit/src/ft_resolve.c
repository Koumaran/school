/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 12:59:36 by atoulous          #+#    #+#             */
/*   Updated: 2016/04/19 20:01:46 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void		ft_deletemap(t_struct *box, char letter)
{
	int		i;
	int		j;

	j = 0;
	while (box->tetris[j])
	{
		i = 0;
		while (box->tetris[j][i])
		{
			if (box->tetris[j][i] == letter)
				box->tetris[j][i] = '.';
			i++;
		}
		j++;
	}
}

static char		ft_checkletter(char *map)
{
	char	letter;
	int		i;

	i = 0;
	while (map[i])
	{
		if (ft_isalpha(map[i]))
			letter = map[i];
		i++;
	}
	return (letter);
}

static int		ft_mapisvalid(t_struct *box, char *map, int x, int y)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = x;
	while (map[++i])
	{
		if (ft_isalpha(box->tetris[y][x]) && ft_isalpha(map[i]))
			return (0);
		if (map[i] != '\n')
			x++;
		if (x > box->cube)
			return (0);
		if (map[i] == '\n')
		{
			y++;
			x = tmp;
			if (y > box->cube - 1)
				return (0);
		}
	}
	return (1);
}

static int		ft_putintetris(t_struct *box, char *map, int x, int y)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = x;
	if (ft_mapisvalid(box, map, x, y))
		while (map[++i])
		{
			if (map[i] == '.')
				x++;
			if (ft_isalpha(map[i]))
			{
				if (box->tetris[y][x] == '.')
					box->tetris[y][x++] = map[i];
			}
			if (map[i] == '\n')
			{
				y++;
				x = tmp;
			}
		}
	else
		return (0);
	return (1);
}

char			**ft_fillit(t_struct *box, char **map, int x, int y)
{
	while (!(ft_putintetris(box, *map, x, y)))
	{
		x++;
		if (x > box->cube)
		{
			y++;
			x = 0;
			if (y > box->cube - 1)
				return (NULL);
		}
	}
	if (*(map + 1))
	{
		while (!(ft_fillit(box, map + 1, 0, 0)))
		{
			ft_deletemap(box, ft_checkletter(*map));
			return (ft_fillit(box, map, ++x, y));
		}
	}
	return (box->tetris);

}
