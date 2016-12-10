/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_lem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:32:37 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/10 19:39:49 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		clear_ant(t_ant **ant)
{
	t_ant		*tmp;
	t_ant		*tmp2;

	tmp = *ant;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	*ant = NULL;
}
void		clear_room(t_room **way_room)
{
	t_room		*room;
	t_room		*tmp;

	room = *way_room;
	while (room)
	{
		ft_strdel(&room->name);
		tmp = room;
		room = room->next;
		free(tmp);
	}
	*way_room = NULL;
}

void		clear_join(t_join **join)
{
	t_join	*tmp;
	t_join	*clear;

	tmp = *join;
	while (tmp)
	{
		tmp->r1 = NULL;
		tmp->r2 = NULL;
		clear = tmp;
		tmp = tmp->next;
		free(clear);
	}
	join = NULL;
}

void		clear_this_room(t_room **room, char *name)
{
	t_room 		*tmp;
	t_room 		*clear;

	tmp = *room;
	while (tmp && tmp->next)
	{
		if (ft_strcmp(tmp->next->name, name) == 0)
		{
			clear = tmp->next;
			tmp->next = clear->next;
			ft_strdel(&clear->name);
			free(clear);
		}
		tmp = tmp->next;
	}
	if (*room && ft_strcmp((*room)->name, name) == 0)
	{
		clear = *room;
		*room = (*room)->next;
		ft_strdel(&clear->name);
		free(clear);
	}
}
