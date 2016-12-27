/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_lem2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:08:01 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/15 19:20:33 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		clear_lst2(t_list *del, t_list **way)
{
	t_list		*tmp;
	t_list		*tmp2;
	t_room		*room;

	tmp = *way;
	tmp2 = NULL;
	while (tmp)
	{
		if (tmp == del)
		{
			if (tmp2)
				tmp2->next = tmp->next;
			del = tmp;
			tmp = tmp->next;
			room = (t_room*)del->content;
			clear_room(&room);
			free(del);
		}
		else
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
	}
}

void			clear_lst(t_list *del, t_list **way)
{
	t_room		*room;

	if (way && *way)
	{
		if (*way == del)
		{
			del = *way;
			*way = (*way)->next;
			room = (t_room*)del->content;
			clear_room(&room);
			free(del);
		}
		else
			clear_lst2(del, way);
	}
}
