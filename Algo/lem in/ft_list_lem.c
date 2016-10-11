/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_lem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 13:34:26 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/11 15:06:32 by jsivanes         ###   ########.fr       */
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

int		add_room(t_lem *lem, char **split)
{
	t_room		*tmp;

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
		}
		tmp->next = new_room(split);
	}
	else
		lem->room = new_room(split);
	return (1);
}
