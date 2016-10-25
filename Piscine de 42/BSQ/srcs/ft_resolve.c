/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:18:36 by atoulous          #+#    #+#             */
/*   Updated: 2016/04/23 13:05:56 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**g_map;
char	g_carac[3];

static int		ft_square(int size, int pos_x, int pos_y)
{
	int		y;
	int		x;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (g_map[pos_y + y][pos_x + x] != g_carac[0])
				return (0);
		}
	}
	return (1);
}

static void		ft_complete_square(int x, int y, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			g_map[y + i][x + j] = g_carac[2];
	}
}

void			ft_resolve(int pos_x, int pos_y)
{
	int		x;
	int		y;
	int		size;

	y = -1;
	size = 0;
	while (g_map[++y])
	{
		x = -1;
		while (g_map[y][++x])
		{
			while (ft_square(size + 1, x, y))
			{
				pos_x = x;
				pos_y = y;
				size++;
			}
		}
	}
	ft_complete_square(pos_x, pos_y, size);
}
