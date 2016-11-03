/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 13:43:11 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/03 20:33:38 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			get_under_mid(t_box *box, int mid)
{
	t_nb	*tmp;
	int		count;

	tmp = box->a;
	count = 0;
	if (tmp->nb < mid)
		count++;
	tmp = tmp->next;
	while (tmp != box->a)
	{
		if (tmp->nb < mid)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void		rotate_well_b(t_box *box, t_flag *flag, t_string *string, int nb)
{
	int		pos;

	box->len = get_len(box->b, &box->midl);
	pos = get_position(box->b, nb);
	if (pos >= box->midl)
		while (box->b->nb != nb)
			rrb(box, flag, string);
	else
		while (box->b->nb != nb)
			rb(box, flag, string);
}

void		swap_select(t_box *box, t_flag *flag, t_string *string)
{
	int		mid;
	int		count;

	mid = box->min;
	while (box->a)
	{
		mid += (box->len > 100) ? 35 : 15;
		count = get_under_mid(box, mid);
		while (box->a && count)
		{
			if (box->a->nb <= mid)
			{
				pb(box, flag, string);
				count--;
			}
			else
				ra(box, flag, string);
		}
		box->len = get_len(box->a, &box->midl);
	}
	while (box->b)
	{
		rotate_well_b(box, flag, string, ft_big_elem(box->b));
		pa(box, flag, string);
	}
}
