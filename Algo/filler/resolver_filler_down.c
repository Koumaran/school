/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_filler_down.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 18:17:36 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/31 17:40:13 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_placement(t_fil *f, t_piece *p, int y, int i)
{
	while (++i < f->c_y)
	{
		p->j = -1;
		p->x = p->pos_x - p->a_x;
		while (++p->j < f->c_x)
		{
			if (f->cube[i][p->j] == '*' && (i != p->a_y || p->j != p->a_x))
			{
				if (y < 0 || y >= f->m_y || p->x < 0 || p->x >= f->m_x)
					return (0);
				if (f->map[y][p->x] != '.')
					return (0);
			}
			else if (f->cube[i][p->j] == '*' && i == p->a_y && p->j == p->a_x)
			{
				if (y < 0 || y >= f->m_y || p->x < 0 || p->x >= f->m_x)
					return (0);
				if (f->map[y][p->x] != f->h && f->map[y][p->x] != f->h + 32)
					return (0);
			}
			p->x++;
		}
		y++;
	}
	return (1);
}

static int		ft_test_placement(t_fil *fil, t_piece *piece)
{
	int		y;
	int		x;

	y = -1;
	while (fil->cube[++y])
	{
		x = -1;
		while (fil->cube[y][++x])
		{
			if (fil->cube[y][x] == '*')
			{
				piece->a_x = x;
				piece->a_y = y;
				if (ft_placement(fil, piece, piece->pos_y - piece->a_y, -1))
					return (1);
			}
		}
	}
	return (0);
}

int				add_midldown(t_fil *fil, t_piece *p)
{
	int		ret;

	ret = 0;
	p->pos_y = (fil->m_y / 2) - 2;
	while (++p->pos_y <= (fil->m_y / 2) + 1)
	{
		p->pos_x = fil->m_x;
		while (--p->pos_x >= 0)
		{
			if (fil->map[p->pos_y][p->pos_x] == fil->h ||
					fil->map[p->pos_y][p->pos_x] == fil->h + 32)
				if ((ret = ft_test_placement(fil, p)) == 1)
					break ;
		}
		if (ret == 1)
			break ;
	}
	return (ret);
}

void			resolver_filler_down(t_fil *fil, t_piece *piece, int m_vil)
{
	int		ret;

	ret = 0;
	if (fil->blocked == 0)
		ret = (m_vil == 1) ? add_midldown(fil, piece) : add_midlup(fil, piece);
	piece->pos_y = (ret == 0) ? fil->m_y : piece->pos_y + 1;
	while (--piece->pos_y >= 0 && ret == 0)
	{
		piece->pos_x = fil->m_x;
		while (--piece->pos_x >= 0)
		{
			if (fil->map[piece->pos_y][piece->pos_x] == fil->h ||
					fil->map[piece->pos_y][piece->pos_x] == fil->h + 32)
				if ((ret = ft_test_placement(fil, piece)) == 1)
					break ;
		}
		if (ret == 1)
			break ;
	}
}
