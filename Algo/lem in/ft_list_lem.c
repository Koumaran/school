/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_lem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 13:34:26 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/17 15:15:22 by jsivanes         ###   ########.fr       */
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

t_room		*ft_pushfront_room(t_lem *lem, char **split)
{
	t_room		*tmp;
	t_room		*tmp2;

	tmp2 = new_room(split);
	if (lem->room)
	{
		tmp = lem->room;
		while (tmp)
		{
			if (tmp->name && ft_strcmp(tmp->name, tmp2->name) == 0)
				return (NULL);
			tmp = tmp->next;
		}
		tmp2->next = lem->room;
	}
	lem->room = tmp2;
	return (tmp2);
}

t_room		*add_room(t_lem *lem, char **split, int start)
{
	t_room		*tmp;
	t_room		*new;

	if (start == 1)
		return (ft_pushfront_room(lem, split));
	new = new_room(split);
	if (lem->room)
	{
		tmp = lem->room;
		if ((tmp->name && ft_strcmp(tmp->name, new->name) == 0) ||
				(tmp->x == new->x && tmp->y == new->y))
			return (NULL);
		while (tmp->next)
		{
			tmp = tmp->next;
			if ((tmp->name && ft_strcmp(tmp->name, new->name) == 0) ||
					(tmp->x == new->x && tmp->y == new->y))
				return (NULL);
		}
		tmp->next = new;
	}
	else
		lem->room = new;
	return (new);
}

t_join		*new_join(t_room *r1, t_room *r2)
{
	t_join		*join;

	if (!(join = (t_join *)malloc(sizeof(t_join))))
		return (NULL);
	join->r1 = r1;
	join->r2 = r2;
	join->next = NULL;
	return (join);
}

int		create_connection(t_lem *lem, t_room *r1, t_room *r2)
{
	t_join		*tmp;
	
	if (lem->join)
	{
		tmp = lem->join;
		if ((tmp->r1 == r1 && tmp->r2 == r2) || (tmp->r1 == r2 && tmp->r2 == r1))
			return (0);
		while (tmp->next)
		{
			tmp = tmp->next;
			if ((tmp->r1 == r1 && tmp->r2 == r2) || (tmp->r1 == r2 && tmp->r2 == r1))
				return (0);
		}
		tmp->next = new_join(r1, r2);
	}
	else
		lem->join = new_join(r1, r2);
	return (1);
}
