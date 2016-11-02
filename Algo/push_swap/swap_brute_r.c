/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_brute_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 11:40:20 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/28 19:07:12 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_box	*do_rrr(t_box *box, t_flag *flag, t_string *string, int *x)
{
	if (box->a->previus->nb > box->a->nb)
	{
		rra(box, flag, string);
		*x = 1;
	}
	if (box->b && box->b->next != box->b && *x == 1)
	{
		if (box->b->previus->nb < box->b->nb)
			rrb(box, flag, string);
	}
	return (box);
}

static t_box	*do_rr(t_box *box, t_flag *flag, t_string *string, int *x)
{
	if (box->a->nb == ft_small_elem(box->a))
	{
		ra(box, flag, string);
		*x = 1;
	}
	if (box->b && box->b->next != box->b && *x == 1)
	{
		if (box->b->nb > box->b->previus->nb)
			rb(box, flag, string);
	}
	return (do_rrr(box, flag, string, x));
}

static t_box	*do_ss(t_box *box, t_flag *flag, t_string *string, int *x)
{
	if (box->a->nb < box->a->next->nb)
	{
		sa(box, flag, string);
		*x = 1;
	}
	if (box->b && box->b->next != box->b && *x == 1)
	{
		if (box->b->nb > box->b->next->nb)
			sb(box, flag, string);
	}
	return (do_rr(box, flag, string, x));
}

static t_box	*do_op_on_b_r(t_box *box, t_flag *flag, t_string *string)
{
	if (box->b && box->b->next != box->b)
	{
		if (box->b->nb > box->b->next->nb)
			sb(box, flag, string);
		if (box->b->nb == ft_big_elem(box->b))
			rb(box, flag, string);
		if (box->b->previus->nb < box->b->nb)
			rrb(box, flag, string);
	}
	return (box);
}

void			swap_brute_r(t_box *box, t_flag *flag, t_string *string)
{
	int		x;

	box = before_tri_r(box, flag, string);
	while (!check_good_r(box->a) || box->b)
	{
		x = 0;
		box = do_ss(box, flag, string, &x);
		if (x == 0 && box->b)
			box = do_op_on_b_r(box, flag, string);
		if (x == 0 && !check_good_r(box->a))
		{
			pb(box, flag, string);
			x = 1;
		}
		if (box->b && x == 0)
			pa(box, flag, string);
	}
}
