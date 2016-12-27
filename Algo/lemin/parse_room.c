/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:06:35 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/15 19:24:47 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*new_room(char **split, t_room *src_room)
{
	t_room		*room;

	room = NULL;
	if (split && *split)
	{
		if (!(room = (t_room*)ft_memalloc(sizeof(t_room))))
			return (NULL);
		room->name = ft_strdup(*split);
		room->x = ft_atoi(split[1]);
		room->y = ft_atoi(split[2]);
	}
	if (src_room)
	{
		if (!(room = (t_room*)ft_memalloc(sizeof(t_room))))
			return (NULL);
		room->name = ft_strdup(src_room->name);
		room->x = src_room->x;
		room->y = src_room->y;
		room->nb_join = src_room->nb_join;
	}
	return (room);
}

t_room		*ft_pushfront_room(t_room **room, char **split, t_room *src_room)
{
	t_room		*tmp;
	t_room		*new;

	new = new_room(split, src_room);
	if (*room && new)
	{
		tmp = *room;
		while (tmp)
		{
			if (tmp->name && ft_strcmp(tmp->name, new->name) == 0)
				return (NULL);
			tmp = tmp->next;
		}
		new->next = *room;
		*room = new;
	}
	else if (new)
		*room = new;
	return (new);
}

t_room		*ft_pushback_room(t_room **room, char **split, t_room *src_room)
{
	t_room		*tmp;
	t_room		*new;

	new = new_room(split, src_room);
	if (*room)
	{
		tmp = *room;
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
		*room = new;
	return (new);
}

t_room		*check_room(t_lem *lem, char *line, int start)
{
	char	**split;
	t_room	*room;

	if (ft_nb_of_word(line, ' ') != 3)
		return (NULL);
	split = ft_strsplit(line, ' ');
	if (split[0][0] == 'L' || !check_number(split[1])
		|| !check_number(split[2]))
		return (NULL);
	if (start == 1)
		room = ft_pushfront_room(&lem->room, split, NULL);
	else
		room = ft_pushback_room(&lem->room, split, NULL);
	ft_memfree_2d(split);
	lem->nb_room += (room) ? 1 : 0;
	return (room);
}
