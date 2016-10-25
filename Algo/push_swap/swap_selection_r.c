/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_selection_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 17:03:49 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/23 16:00:40 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_max2(t_nb *tab, int max)
{
	int		x;
	t_nb	*tmp;

	x = tab->nb;
	tmp = tab->next;
	while (tmp != tab)
	{
		if (tmp->nb != max && x < tmp->nb)
			x = tmp->nb;
		tmp = tmp->next;
	}
	return (x);
}

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

static t_box	*get_max(t_box *box, char **str, t_flag *flag, t_nb **a)
{
	t_nb	*tmp;
	int		max;
	int		max2;
	int		position;

	max = ft_max(*a);
	max2 = ft_max2(*a, max);
	tmp = (*a)->next;
	if ((*a)->nb == max)
		return (box);
	tmp = *a;
	while ((*a)->nb != max)
	{
		position = get_position(*a, max);
		if (position == 2)
			sa(a, &box->b, flag, str);
		else if ((*a)->nb == max2 && box->len > 2)
			pb(a, &box->b, flag, str);
		else if (position <= box->midl)
			ra(a, &box->b, flag, str);
		else if (position > box->midl)
			rra(a, &box->b, flag, str);
	}
	return (box);
}

char			*swap_selection_r(t_box *box, t_flag *flag)
{
	char	*str;

	str = ft_strnew(0);
	while (!check_good_r(box->a) || box->b)
	{
		box = init_box(box, box->a);
		box = get_max(box, &str, flag, &box->a);
		if (!check_good_r(box->a) && box->a->nb == box->max)
		{
			pb(&box->a, &box->b, flag, &str);
			if (box->b && box->b->next != box->b)
			{
				if (box->b->nb > box->b->next->nb)
					sb(&box->a, &box->b, flag, &str);
			}
		}
		if (check_good_r(box->a) && box->b)
			pa(&box->a, &box->b, flag, &str);
	}
	return (str);
}
