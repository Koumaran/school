/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_lemin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:21:44 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/26 21:55:37 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			add_way_bonus(t_string *string, t_lem *lem)
{
	t_room		*room;
	t_list		*tmp;
	int			i;

	tmp = lem->way;
	i = 1;
	while (tmp)
	{
		ft_printf_string(string, "\nChemin %d:\n{green}[%s]{eoc}---", \
				i++, lem->start->name);
		room = (t_room*)tmp->content;
		while (room)
		{
			if (ft_strcmp(room->name, lem->end->name) == 0)
				ft_printf_string(string, "{red}[%s]{eoc}", room->name);
			else
				ft_printf_string(string, "[%s]", room->name);
			if (room->next)
				ft_stringadd(string, "---", 3);
			else
				ft_stringaddc(string, '\n');
			room = room->next;
		}
		tmp = tmp->next;
	}
}

static int		move_ant_room(t_lem *lem, t_room *way_room, int nb_way, int m)
{
	t_room		*room;
	int			ret;
	int			i;

	room = way_room;
	ret = 0;
	i = 0;
	while (room)
	{
		if (room->ant >= lem->nb_ant / nb_way + m)
			room->ant = -1;
		room->ant += (room->ant > 0) ? 1 : 0;
		if (!room->ant)
		{
			room->ant = ++i;
			break ;
		}
		if (ft_strcmp(room->name, lem->end->name) == 0 && room->ant == -1)
		{
			ret++;
			room->ant = lem->nb_ant / nb_way + m;
		}
		room = room->next;
	}
	return (ret);
}

static int		move_ant(t_lem *lem, int ret, int nb_way)
{
	t_list		*tmp;
	int			m;

	tmp = lem->way;
	while (tmp)
	{
		nb_way++;
		tmp = tmp->next;
	}
	tmp = lem->way;
	m = lem->nb_ant % nb_way;
	while (tmp)
	{
		ret += move_ant_room(lem, (t_room*)tmp->content, nb_way, m);
		tmp = tmp->next;
		m = 0;
	}
	ret = (ret == nb_way) ? ret : 0;
	return (ret);
}

static void		print_room_bonus(t_lem *lem, t_string *string, t_room *w_room)
{
	t_room		*room;

	room = w_room;
	while (room)
	{
		if (ft_strcmp(room->name, lem->end->name) == 0)
			ft_printf_string(string, "{red}[%s(%d)]{eoc}",\
					room->name, room->ant);
		else if (room->ant > 0)
			ft_printf_string(string, "[%s({blue}%d{eoc})]",\
					room->name, room->ant);
		else
			ft_printf_string(string, "[%s]", room->name);
		if (room->next)
			ft_stringadd(string, "---", 3);
		else
			ft_stringaddc(string, '\n');
		room = room->next;
	}
}

void			add_map(t_lem *lem, t_string *string)
{
	t_list		*way;

	while (move_ant(lem, 0, 0) == 0)
	{
		way = lem->way;
		while (way)
		{
			ft_printf_string(string, "{green}[%s]{eoc}---", lem->start->name);
			print_room_bonus(lem, string, (t_room*)way->content);
			way = way->next;
		}
		ft_stringaddc(string, '\n');
	}
}
