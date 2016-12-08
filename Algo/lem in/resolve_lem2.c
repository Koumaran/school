/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_lem2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:22:26 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/07 20:55:46 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		clear_lst(t_list *del, t_list **way)
{
	t_room		*room;
	t_list		*tmp;
	t_list		*tmp2;

	if (*way == del)
	{
		del = *way;
		*way = (*way)->next;
		room = (t_room*)del->content;
		clear_room(&room);
		free(del);
		return ;
	}
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
			tmp2 = tmp;
			tmp = tmp->next;
	}
}

t_list		*check_double_roomlst(t_list *lst, t_list *way)
{
	t_room		*r1;
	t_room		*r2;
	t_list		*tmp;
	int			len_r1;
	int			len_r2;

	tmp = way;
	while (tmp)
	{
		if (tmp != lst)
		{
			dprintf(1, "let compare room\n");
			r2 = (t_room*)tmp->content;
			len_r2 = r2->len;
			while (r2->next)
			{
				r1 = (t_room*)lst->content;
				len_r1 = r1->len;
				while (r1->next)
				{
					dprintf(1, "r1=>%s r2=>%s\n", r1->name, r2->name);
					if (ft_strcmp(r1->name, r2->name) == 0)
						if (len_r1 >= len_r2)
							return (lst);
					r1 = r1->next;
				}
				r2 = r2->next;
			}
		}
		else
			dprintf(1, "same list\n");
		tmp = tmp->next;
	}
	return (NULL);
}

void		check_way(t_list **way)
{
	t_list		*big_tmp;
	t_list		*tmp2;
	t_list		*del;
	t_room		*room;
	
	big_tmp = *way;
	tmp2 = NULL;
	if (big_tmp && big_tmp->next)
	{
		while (big_tmp)
		{
			dprintf(1, "begin get DEL\n");
			del = check_double_roomlst(big_tmp, *way);
			big_tmp = big_tmp->next;
			if (del)
			{
				room = (t_room*)del->content;
				dprintf(1, "DEl==>%s\n", room->name);
				clear_lst(del, way);
				dprintf(1, "DEL cleaned\n");
				big_tmp = *way;
			}
		}
	}
}
