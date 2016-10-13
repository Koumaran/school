/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 19:31:37 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/13 21:05:25 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char		**join_to_room(t_lem *lem, char *name, int *len)
{
	t_join		*join;
	int			i;
	char		**connect;

	join = lem->join;
	while (join)
	{
		if (ft_strcmp(join->from, name) == 0 || ft_strcmp(join->to, name) == 0)
			*len += 1;
		join = join->next;
	}
	if (!*len || !(connect = (char**)malloc(sizeof(char*) * *len + 1)))
		return (NULL);
	join = lem->join;
	i = 0;
	while (join && i < *len)
	{
		if (ft_strcmp(join->from, name) == 0)
			connect[i++] = join->to;
		else if (ft_strcmp(join->to, name) == 0)
			connect[i++] = join->from;
		join = join->next;
	}
	return (connect);
}

void	check_join(t_lem *lem, char **name)
{
	t_room		*room;
	t_room		*tmp;
	int			nb;
	int			i;

	room = lem->room;
	nb = 0;
	while (room && ft_strcmp(room->name, *name) != 0)
		room = room->next;
	tmp = room;
	i = -1;
	while (++i < tmp->len)
	{
		tmp = 
	}
}

int		get_join(t_lem *lem)
{
	t_room		*room;
	int			len;
	char		*name;

	room = lem->room;
	while (room)
	{
		room->connect = join_to_room(lem, room->name, &room->len);
		room = room->next;
	}
	name = lem->start;
	check_join(lem, &name);
	if (ft_strcmp(name, lem->end) != 0)
		return (0);
	return (1);
}
