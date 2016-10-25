/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetris.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 19:32:10 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/23 18:14:09 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char		*ft_push_top(char *map, char letter, int i, int y)
{
	while (map[i] != letter)
		i++;
	if (i < 4)
	{
		while (y != 4)
			if (map[i++] == letter)
				y++;
		while (i < 19)
		{
			if (map[i] == '\n')
				i++;
			map[i++] = '.';
		}
	}
	else
	{
		i = i - (i - 5);
		while (i < 20)
			map[y++] = map[i++];
		return (ft_push_top(map, letter, 0, 0));
	}
	return (map);
}

static int	ft_sqrt(int nb)
{
	int		racine;

	racine = 0;
	while (racine * racine < nb)
		racine++;
	if (racine * racine >= nb)
		return (racine);
	return (0);
}

void		ft_free(char **map, char *tmp, char **tetris)
{
	int		i;

	i = 0;
	free(tmp);
	while (map[i])
		free(map[i++]);
	free(map);
	i = 0;
	while (tetris[i])
		free(tetris[i++]);
	free(tetris);
}

void		ft_tetris(char *tmp)
{
	int		i;
	t_struct	*box;

	box = ft_memalloc(sizeof(t_struct));
	box->cube = ((ft_strlen(tmp) + 1) / 21);
	if ((box->map = init_map(tmp, -1, box->cube)))
	{
		box->cube = ft_sqrt(box->cube * 4);
		box->tetris = ft_create_tet(box->cube);
		while ((box->tetris = ft_fillit(box, box->map, 0, 0)) == NULL)
		{
			box->cube++;
			free(box->tetris);
			box->tetris = ft_create_tet(box->cube);
		}
		i = -1;
		while (box->tetris[++i])
			ft_putstr(box->tetris[i]);
		ft_free(box->map, tmp, box->tetris);
	}
	else
		ft_putstr("error\n");
}
