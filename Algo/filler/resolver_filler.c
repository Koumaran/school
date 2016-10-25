/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_filler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:43:56 by jsivanes          #+#    #+#             */
/*   Updated: 2016/09/20 14:40:42 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		get_vilainpos(t_fil *fil, int *player_pos, char c)
{
	int		y;
	int		x;
	int		small;

	y = -1;
	small = 0;
	while (++y < fil->m_y && small == 0)
	{
		x = -1;
		while (++x < fil->m_x)
		{
			if (fil->map[y][x] == c)
			{
				*player_pos = y;
				small = 1;
			}
			else if (fil->map[y][x] == c - 32)
				*player_pos = y;
		}
	}
}

static void		get_heropos(t_fil *fil)
{
	int		x;
	int		y;
	int		found;

	y = -1;
	found = 0;
	while (++y < fil->m_y && found == 0)
	{
		x = -1;
		while (++x < fil->m_x && found == 0)
		{
			if (fil->map[y][x] == fil->h)
			{
				fil->h_y = y;
				found = 1;
			}
		}
	}
}

static void		blocked(t_fil *fil, int tmp_v_y, int y, int x)
{
	int		hero;
	int		vilain;

	hero = 0;
	vilain = 0;
	y = (fil->m_y / 2) - 2;
	while (++y <= (fil->m_y / 2) + 1)
	{
		x = -1;
		while (++x < fil->m_x)
		{
			if (fil->map[y][x] == fil->h)
				hero++;
			if (fil->map[y][x] == fil->v || fil->map[y][x] == fil->v - 32)
				vilain++;
		}
	}
	fil->blocked = (hero + vilain == fil->m_x * 3) ? 1 : 0;
	if (fil->orientation == -1)
		fil->orientation = (fil->h_y < fil->v_y) ? 1 : 0;
	else
		fil->orientation = (tmp_v_y < fil->v_y) ? 1 : 0;
}

void			resolver_filler(t_fil *fil, t_opt *opt)
{
	t_piece		piece;
	int			tmp_v_y;
	int			m_vil;

	ft_bzero(&piece, sizeof(t_piece));
	if (fil->h_y == -1)
		get_heropos(fil);
	tmp_v_y = fil->v_y;
	get_vilainpos(fil, &fil->v_y, fil->v);
	blocked(fil, tmp_v_y, 0, 0);
	m_vil = (fil->v_y >= fil->h_y) ? 1 : 0;
	if (fil->blocked == 0)
	{
		if (fil->h < (fil->m_y / 2) + 1)
			resolver_filler_down(fil, &piece, m_vil);
		else
			resolver_filler_up(fil, &piece, m_vil);
	}
	if (fil->orientation == 0 && fil->blocked == 1)
		resolver_filler_down(fil, &piece, m_vil);
	else if (fil->orientation == 1 && fil->blocked == 1)
		resolver_filler_up(fil, &piece, m_vil);
	ft_printf("%d %d\n", (piece.pos_y - piece.a_y), (piece.pos_x - piece.a_x));
	if (opt->s)
		opt_s(opt, (piece.pos_y - piece.a_y), (piece.pos_x - piece.a_x));
}
