/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 13:43:11 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/23 16:13:58 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		get_position(t_nb *a, int nb)
{
	t_nb	*tmp;
	int		pos;

	pos = 2;
	tmp = a->next;
	while (tmp->nb != nb)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

static t_box	*get_min(t_box *box, char **str, t_flag *flag, t_nb **a)
{
	int		min;
	int		min2;
	int		position;

	min = ft_min(*a);
	min2 = ft_min2(*a, min);
	if ((*a)->nb == min)
		return (box);
	while ((*a)->nb != min)
	{
		position = get_position(*a, min);
		if (position == 2)
			sa(a, &box->b, flag, str);
		else if ((*a)->nb == min2 && box->len > 2)
			pb(a, &box->b, flag, str);
		else if (position <= box->midl)
			ra(a, &box->b, flag, str);
		else if (position > box->midl)
			rra(a, &box->b, flag, str);
	}
	return (box);
}

char			*swap_selection(t_box *box, t_flag *flag)
{
	char	*str;

	str = ft_strnew(0);
	while (!check_good(box->a) || box->b)
	{
		box = init_box(box, box->a);
		box = get_min(box, &str, flag, &box->a);
		if (!check_good(box->a))
		{
			pb(&box->a, &box->b, flag, &str);
			if (box->b && box->b->next != box->b)
			{
				if (box->b->nb < box->b->next->nb)
					sb(&box->a, &box->b, flag, &str);
			}
		}
		if (check_good(box->a) && box->b)
			pa(&box->a, &box->b, flag, &str);
	}
	return (str);
}
