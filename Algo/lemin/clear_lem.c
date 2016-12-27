/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_lem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:32:37 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/15 18:37:21 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		clear_way(t_list **way)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_room	*room;

	if (way && *way)
	{
		tmp = *way;
		while (tmp)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			room = (t_room*)tmp2->content;
			clear_room(&room);
			free(tmp2);
		}
		*way = NULL;
	}
}

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
	t_room		*tmp;
	t_room		*clear;

	tmp = *room;
	while (tmp && tmp->next)
	{
		if (ft_strcmp(tmp->next->name, name) == 0)
		{
			clear = tmp->next;
			tmp->next = clear->next;
			ft_strdel(&clear->name);
			free(clear);
			(*room)->len--;
		}
		tmp = tmp->next;
	}
	if (*room && ft_strcmp((*room)->name, name) == 0)
	{
		clear = *room;
		(*room)->next->len = (*room)->len;
		*room = (*room)->next;
		ft_strdel(&clear->name);
		free(clear);
		(*room)->len--;
	}
}
