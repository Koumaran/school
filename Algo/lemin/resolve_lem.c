/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_lem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 18:37:56 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/16 14:18:04 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_join	*get_join(t_lem *lem, t_room *room, t_join *to_pass)
{
	t_join		*join;

	join = lem->join;
	while (join)
	{
		if (join->r1 == room)
			if (!get_join2(to_pass, join->r2, 1))
				return (join);
		if (join->r2 == room)
			if (!get_join2(to_pass, join->r1, 2))
				return (join);
		join = join->next;
	}
	return (NULL);
}

static int		check_if_exist(t_room **room, t_room *get, t_room *start)
{
	t_room		*tmp;
	int			i;

	tmp = *room;
	if (ft_strcmp(get->name, start->name) == 0)
		return (0);
	i = 0;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, get->name) == 0)
			i++;
		tmp = tmp->next;
	}
	if (i > 1)
		return (0);
	return (1);
}

static int		check_if_end(t_room *room, t_room *end)
{
	t_room *tmp;

	tmp = room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, end->name) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int		get_child(t_lem *lem, t_room **room, \
		t_room *src_room, t_join **join_lst)
{
	t_join		*join;
	t_room		*tmp_room;

	while ((join = get_join(lem, src_room, *join_lst)) != NULL)
	{
		ft_pushback_join(join_lst, new_join(join->r1, join->r2));
		tmp_room = (join->r1 == src_room) ? join->r2 : join->r1;
		ft_pushback_room(room, NULL, tmp_room);
		(*room)->len++;
		if (check_if_exist(room, tmp_room, lem->start))
		{
			if (tmp_room != lem->end)
				if (get_child(lem, room, tmp_room, join_lst) == 0)
					clear_this_room(room, tmp_room->name);
		}
		else
			clear_this_room(room, tmp_room->name);
		if (check_if_end(*room, lem->end))
			return ((*room)->len);
	}
	return (0);
}

void			resolve_lem(t_lem *lem, t_join *start_join, t_room *tmp_room)
{
	t_join		*join_lst;
	t_join		*join;
	t_room		*room;

	join = start_join;
	while (join)
	{
		room = NULL;
		join_lst = NULL;
		ft_pushback_join(&join_lst, new_join(join->r1, join->r2));
		tmp_room = (join->r1 == lem->start) ? join->r2 : join->r1;
		ft_pushback_room(&room, NULL, tmp_room);
		room->len = 1;
		if (tmp_room != lem->end)
			if (tmp_room->nb_join < 2 ||\
					get_child(lem, &room, tmp_room, &join_lst) == 0)
				clear_room(&room);
		if (room)
		{
			ft_lstadd_back(&lem->way, ft_lstnew((void*)room, sizeof(t_room)));
			free(room);
		}
		join = join->next;
		clear_join(&join_lst);
	}
}
