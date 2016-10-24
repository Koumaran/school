/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_lem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 13:34:26 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/13 20:48:57 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*new_room(char	**str)
{
	t_room		*room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	ft_bzero(room, sizeof(t_room));
	room->name = ft_strdup(*str);
	room->x = ft_atoi(str[1]);
	room->y = ft_atoi(str[2]);
	room->next = NULL;
	return (room);
}

int		ft_pushfront_room(t_lem *lem, char **split)
{
	t_room		*tmp;
	t_room		*tmp2;

	if (lem->room)
	{
		tmp2 = new_room(split);
		tmp = lem->room;
		while (tmp)
		{
			if (tmp->name && ft_strcmp(tmp->name, tmp2->name) == 0)
				return (0);
			tmp = tmp->next;
		}
		tmp2->next = lem->room;
		lem->room = tmp2;
	}
	else
		lem->room = new_room(split);
	return (1);
}

int		add_room(t_lem *lem, char **split, int start)
{
	t_room		*tmp;
	t_room		*end;

	if (start == 1)
		return (ft_pushfront_room(lem, split));
	end = NULL;
	if (lem->room)
	{
		tmp = lem->room;
		if (tmp->name && ft_strcmp(tmp->name, *split) == 0)
			return (0);
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			if (tmp->name && ft_strcmp(tmp->name, *split) == 0)
				return (0);
			if (lem->end && ft_strcmp(tmp->next->name, lem->end) == 0)
			{
				end = tmp->next;
				tmp->next = NULL;
			}
		}
		tmp->next = new_room(split);
		if (end)
			tmp->next->next = end;
	}
	else
		lem->room = new_room(split);
	return (1);
}

t_join		*new_join(char *from, char *to)
{
	t_join		*join;

	if (!(join = (t_join *)malloc(sizeof(t_join))))
		return (NULL);
	join->from = ft_strdup(from);
	join->to = ft_strdup(to);
	join->next = NULL;
	return (join);
}

int		create_connection(t_lem *lem, char *from, char *to)
{
	t_join		*tmp;

	if (lem->join)
	{
		tmp = lem->join;
		if ((tmp->from && ft_strcmp(tmp->from, from) == 0) &&
				(tmp->to && ft_strcmp(tmp->to, to) == 0))
			return (0);
		if ((tmp->from && ft_strcmp(tmp->from, to) == 0) &&
				(tmp->to && ft_strcmp(tmp->to, from) == 0))
			return (0);
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			if ((tmp->from && ft_strcmp(tmp->from, from) == 0) &&
					(tmp->to && ft_strcmp(tmp->to, to) == 0))
				return (0);
			if ((tmp->from && ft_strcmp(tmp->from, to) == 0) &&
					(tmp->to && ft_strcmp(tmp->to, from) == 0))
				return (0);
		}
		tmp->next = new_join(from, to);
	}
	else
		lem->join = new_join(from, to);
	return (1);
}
