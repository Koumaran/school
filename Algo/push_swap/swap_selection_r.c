/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_selection_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 17:03:49 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/03 20:33:10 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		get_upper_mid(t_box *box, int mid)
{
	t_nb	*tmp;
	int		count;

	tmp = box->a->next;
	count = 0;
	if (box->a->nb > mid)
		count++;
	while (tmp != box->a)
	{
		if (tmp->nb > mid)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void			swap_select_r(t_box *box, t_flag *flag, t_string *string)
{
	int			mid;
	int			count;

	mid = box->max;
	while (box->a)
	{
		mid -= (box->len > 100) ? 35 : 15;
		count = get_upper_mid(box, mid);
		while (box->a && count)
			if (box->a->nb >= mid)
			{
				pb(box, flag, string);
				count--;
			}
			else
				ra(box, flag, string);
		box->len = get_len(box->a, &box->midl);
	}
	while (box->b)
	{
		rotate_well_b(box, flag, string, ft_small_elem(box->b));
		pa(box, flag, string);
	}
}
