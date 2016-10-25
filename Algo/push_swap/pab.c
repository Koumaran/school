/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:06:23 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/17 16:04:32 by jsivanes         ###   ########.fr       */
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

void			pa(t_nb **a, t_nb **b, t_flag *flag, char **str)
{
	t_nb	*tmp;

	if (b && *b)
	{
		*str = JN(*str, DP("=pa\n"));
		tmp = *b;
		if ((*b)->next != *b)
		{
			*b = (*b)->next;
			(*b)->previus = tmp->previus;
			tmp->previus->next = *b;
		}
		else
			*b = NULL;
		*a = push_list_to_head(*a, tmp);
		if (flag && flag->v)
			print_option_sw(*a, *b, str);
	}
}

void			pb(t_nb **a, t_nb **b, t_flag *flag, char **str)
{
	t_nb	*tmp;

	if (a && *a)
	{
		*str = JN(*str, DP("=pb\n"));
		tmp = *a;
		if ((*a)->next != *a)
		{
			*a = (*a)->next;
			(*a)->previus = tmp->previus;
			tmp->previus->next = *a;
		}
		else
			*a = NULL;
		*b = push_list_to_head(*b, tmp);
		if (flag && flag->v)
			print_option_sw(*a, *b, str);
	}
}
