/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roaming.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 18:51:32 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/10 20:58:59 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_ant		*new_ant(t_room *start, int nb)
{
	t_ant	*new;

	if (!(new = (t_ant*)ft_memalloc(sizeof(t_ant))))
		return (NULL);
	new->nb = nb;
	new->room = start;
	new->next = NULL;
	return (new);
}

t_ant		*init_ant(t_room *start, int nb_ant)
{
	t_ant	*tmp;
	t_ant	*ant;
	int		nb;

	nb = 1;
	if (!(ant = new_ant(start, nb)))
		return (NULL);
	tmp = ant;
	while (--nb_ant)
	{
		if (!(tmp->next = new_ant(start, ++nb)))
			return (NULL);
		tmp = tmp->next;
	}
	return (ant);
}

int			ant_sended(t_ant *ant, t_room *end)
{
	t_ant		*tmp;

	tmp = ant;
	while (tmp)
	{
		if (tmp->room && ft_strcmp(tmp->room->name, end->name) != 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		move_ant(t_ant **ant, t_list *way, t_room *start)
{
	t_ant		*tmp_ant;
	t_list		*tmp_lst;
	int			first;
	t_room		*room_way;

	tmp_ant = *ant;
	tmp_lst = way;
	while (tmp_lst)
	{
		first = 0;
		room_way = (t_room*)tmp_lst->content;
		while (tmp_ant && first == 0)
		{
			if (tmp_ant->room == start)
			{
				first++;
				tmp_ant->room = room_way;
			}
			else if (tmp_ant->room)
				tmp_ant->room = tmp_ant->room->next;
			tmp_ant = tmp_ant->next;
		}
		tmp_lst = tmp_lst->next;
	}
}

void		send_ants(t_lem *lem, t_list *way)
{
	t_ant		*ant;
	t_ant		*tmp_ant;

	ant = NULL;
	if ((ant = init_ant(lem->start, lem->nb_ant)) == NULL)
		ft_error("error");
	while (!ant_sended(ant, lem->end))
	{
		move_ant(&ant, way, lem->start);
		tmp_ant = ant;
		while (tmp_ant)
		{
			if (tmp_ant->room && tmp_ant->room != lem->start)
			{
				ft_printf("L%d-%s", tmp_ant->nb, tmp_ant->room->name);
				if (tmp_ant->next && tmp_ant->next->room != lem->start)
					ft_putchar(' ');
			}
			tmp_ant = tmp_ant->next;
		}
		ft_putchar('\n');
	}
	clear_ant(&ant);
	clear_room(&lem->room);
}