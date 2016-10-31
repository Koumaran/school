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

void	ra(t_nb **a, t_nb **b, t_flag *flag, t_string *string)
{
	(void)b;
	if (a && *a && (*a)->next != *a)
	{
		ft_stringaddnl(string, "=ra", 3);
		*a = (*a)->next;
		if (flag && flag->v)
			print_option_sw(*a, *b, string);
	}
}

void	rb(t_nb **a, t_nb **b, t_flag *flag, t_string *string)
{
	(void)a;
	if (b && *b && (*b)->next != *b)
	{
		ft_stringaddnl(string, "=rb", 3);
		*b = (*b)->next;
		if (flag && flag->v)
			print_option_sw(*a, *b, string);
	}
}

void	rr(t_nb **a, t_nb **b, t_flag *flag, t_string *string)
{
	ra(a, b, flag, string);
	rb(a, b, flag, string);
}
