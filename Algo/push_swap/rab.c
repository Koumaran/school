/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 17:41:36 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/28 18:49:37 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ra(t_box *box, t_flag *flag, t_string *string)
{
	if (box->a && box->a != box->a->next)
	{
		ft_stringaddnl(string, "=ra", 3);
		box->a = box->a->next;
		if (flag && flag->v)
			print_option_sw(box->a, box->b, string);
	}
}

void	rb(t_box *box, t_flag *flag, t_string *string)
{
	if (box->b && box->b->next != box->b)
	{
		ft_stringaddnl(string, "=rb", 3);
		box->b = box->b->next;
		if (flag && flag->v)
			print_option_sw(box->a, box->b, string);
	}
}

void	rr(t_box *box, t_flag *flag, t_string *string)
{
	ra(box, flag, string);
	rb(box, flag, string);
}
