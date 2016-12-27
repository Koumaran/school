/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_lem2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:22:26 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/16 15:14:27 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				get_join2(t_join *to_pass, t_room *room, int ref)
{
	t_join		*tmp;

	tmp = to_pass;
	while (tmp)
	{
		if (ref == 1)
			if (!ft_strcmp(tmp->r2->name, room->name))
				return (1);
		if (ref == 2)
			if (!ft_strcmp(tmp->r1->name, room->name))
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int		check_double_roomlst2(t_room *r1, t_room *r2, int r2_len)
{
	t_room	*tmp;
	int		r1_len;

	tmp = r1;
	r1_len = r1->len;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->name, r2->name) == 0)
			if (r1_len >= r2_len)
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

static t_list	*check_double_roomlst(t_list *lst, t_list *way)
{
	t_room		*r2;
	t_list		*tmp;
	int			len_r2;

	tmp = way;
	while (tmp)
	{
		if (tmp != lst)
		{
			r2 = (t_room*)tmp->content;
			len_r2 = r2->len;
			while (r2->next)
			{
				if (check_double_roomlst2((t_room*)lst->content, r2, len_r2))
					return (lst);
				r2 = r2->next;
			}
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void			check_way(t_list **way)
{
	t_list		*tmp_way;
	t_list		*del;

	tmp_way = *way;
	if (tmp_way && tmp_way->next)
	{
		while (tmp_way)
		{
			del = check_double_roomlst(tmp_way, *way);
			tmp_way = tmp_way->next;
			if (del)
			{
				clear_lst(del, way);
				tmp_way = *way;
			}
		}
	}
}
