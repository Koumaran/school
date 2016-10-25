/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_brute_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 11:40:20 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/17 16:52:08 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_box	*do_rrr(t_box *box, int *x, char **str, t_flag *flag)
{
	if (box->a->previus->nb > box->a->nb)
	{
		rra(&box->a, &box->b, flag, str);
		*x = 1;
	}
	if (box->b && box->b->next != box->b && *x == 1)
	{
		if (box->b->previus->nb < box->b->nb)
			rrb(&box->a, &box->b, flag, str);
	}
	return (box);
}

static t_box	*do_rr(t_box *box, int *x, char **str, t_flag *flag)
{
	if (box->a->nb == ft_min(box->a))
	{
		ra(&box->a, &box->b, flag, str);
		*x = 1;
	}
	if (box->b && box->b->next != box->b && *x == 1)
	{
		if (box->b->nb > box->b->previus->nb)
			rb(&box->a, &box->b, flag, str);
	}
	return (do_rrr(box, x, str, flag));
}

static t_box	*do_ss(t_box *box, int *x, char **str, t_flag *flag)
{
	if (box->a->nb < box->a->next->nb)
	{
		sa(&box->a, &box->b, flag, str);
		*x = 1;
	}
	if (box->b && box->b->next != box->b && *x == 1)
	{
		if (box->b->nb > box->b->next->nb)
			sb(&box->a, &box->b, flag, str);
	}
	return (do_rr(box, x, str, flag));
}

static t_box	*do_op_on_b_r(t_box *box, char **str, t_flag *flag)
{
	if (box->b && box->b->next != box->b)
	{
		if (box->b->nb > box->b->next->nb)
			sb(&box->a, &box->b, flag, str);
		if (box->b->nb == ft_max(box->b))
			rb(&box->a, &box->b, flag, str);
		if (box->b->previus->nb < box->b->nb)
			rrb(&box->a, &box->b, flag, str);
	}
	return (box);
}

char			*swap_brute_r(t_box *box, t_flag *flag)
{
	char	*str;
	int		x;

	str = ft_strnew(0);
	box = before_tri_r(box, &str, flag);
	while (!check_good_r(box->a) || box->b)
	{
		x = 0;
		box = do_ss(box, &x, &str, flag);
		if (x == 0 && box->b)
			box = do_op_on_b_r(box, &str, flag);
		if (x == 0 && !check_good_r(box->a))
		{
			pb(&box->a, &box->b, flag, &str);
			x = 1;
		}
		if (box->b && x == 0)
			pa(&box->a, &box->b, flag, &str);
	}
	return (str);
}
