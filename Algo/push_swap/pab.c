/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:06:23 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/29 12:18:06 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_nb		*push_list_to_head(t_nb *tab, t_nb *list)
{
	if (!tab)
	{
		list->next = list;
		list->previus = list;
		return (list);
	}
	list->next = tab;
	list->previus = tab->previus;
	tab->previus->next = list;
	tab->previus = list;
	return (list);
}

void			pa(t_box *box, t_flag *flag, t_string *string, int from)
{
	t_nb	*tmp;
	t_nb	*to_move;

	if (box->b)
	{
		tmp = box->b;
		to_move = box->b;
		if (tmp->next != tmp->b)
		{
			tmp = tmp->next;
			tmp->previus = to_move->previus;
			tmp2->previus->next = tmp;
		}
		else
			box->b = NULL;
		box->a = push_list_to_head(box->a, to_move);
		if (from == 1)
			ft_stringaddnl(string, "=pa", 3);
		if (flag && flag->v)
			print_option_sw(box->a, box->b, string);
	}
}

void			pb(t_box *box, t_flag *flag, t_string *string, int from)
{
	t_nb	*tmp;
	t_nb	*to_move;

	if (box->a)
	{
		if (from == 1)
			ft_stringaddnl(string, "=pb", 3);
		tmp = box->a;
		to_move = box->a;
		if (tmp->next != tmp)
		{
			tmp = tmp->next;
			tmp->previus = to_move->previus;
			to_move->previus->next = tmp;
		}
		else
			box->a = NULL;
		box->b = push_list_to_head(box->b, to_move);
		if (flag && flag->v)
			print_option_sw(box->a, box->b, string);
	}
}
