/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 17:41:36 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/17 13:29:33 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ra(t_nb **a, t_nb **b, t_flag *flag, char **str)
{
	(void)b;
	if (a && *a && (*a)->next != *a)
	{
		*str = JN(*str, DP("=ra\n"));
		*a = (*a)->next;
		if (flag && flag->v)
			print_option_sw(*a, *b, str);
	}
}

void	rb(t_nb **a, t_nb **b, t_flag *flag, char **str)
{
	(void)a;
	if (b && *b && (*b)->next != *b)
	{
		*str = JN(*str, DP("=rb\n"));
		*b = (*b)->next;
		if (flag && flag->v)
			print_option_sw(*a, *b, str);
	}
}

void	rr(t_nb **a, t_nb **b, t_flag *flag, char **str)
{
	ra(a, b, flag, str);
	rb(a, b, flag, str);
}
