/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_lem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:32:37 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/23 11:46:05 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
