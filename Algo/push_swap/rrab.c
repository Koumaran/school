/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 17:52:49 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/28 18:51:53 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rra(t_box *box, t_flag *flag, t_string *string)
{
	if (box->a && box->a->previus != box->b)
	{
		ft_stringaddnl(string, "=rra", 4);
		box->a = box->a->previus;
		if (flag && flag->v)
			print_option_sw(box->a, box->b, string);
	}
}

void	rrb(t_box *box, t_flag *flag, t_string *string)
{
	if (box->b && box->b->previus != box->b)
	{
		ft_stringaddnl(string, "=rrb", 4);
		box->b = box->b->previus;
		if (flag && flag->v)
			print_option_sw(box->a, box->b, string);
	}
}

void	rrr(t_box *box, t_flag *flag, t_string *string)
{
	rra(box, flag, string);
	rrb(box, flag, string);
}
