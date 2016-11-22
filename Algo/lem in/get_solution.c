/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:33:19 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/22 14:56:16 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list		*smaller_way(t_list *way, int len)
{
	t_list		*tmp;
	t_list		*ret;
	t_room		*room;
	int			i;

	tmp = way;
	while (tmp)
	{
		room = (t_room*)tmp->content;
		i = 0;
		while (room)
		{
			i++;
			room = room->next;
		}
		if (i > len)
		{
			len = i;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void			add_antinroom(t_room *room, int ant, int nb)
{
	t_room		*tmp;
	int			i;

	tmp = room->next;
	i = nb;
	if (nb == 1)
		room->ant = i;
	else
	{
		while (room)
		{
			if (room->ant)
				room->ant++;
			if (room->ant > ant)
				room->ant = 0;
			room = room->next;
		}
	}
}

void		ft_print_smallem(t_lem *lem, t_list *way, int ant)
{
	t_room		*room;
	t_room		*tmp;
	int			i;


	room = (t_room*)way->content;
	i = 1;
	while (lem->end->ant != ant)
	{
		add_antinroom(room, ant, i++);
		tmp = room;
		while (tmp)
		{
			if (tmp->ant > 0)
				ft_printf("L%d-%s ", tmp->ant, tmp->name);
			if (ft_strcmp(tmp->name, lem->end->name) == 0)
				lem->end->ant = tmp->ant;
			tmp = tmp->next;
		}
		ft_putchar('\n');
	}
}

int			get_solution(t_lem *lem, t_list *way)
{
	t_list		*tmp;

	if (!way)
		return (0);
	tmp = smaller_way(way, 0);
	ft_print_smallem(lem, tmp, lem->nb_ant);
	while (way)
	{
		tmp = way;
		way = way->next;
		clear_room((t_room**)&tmp->content);
		free(tmp);
	}
	return (1);
}
