/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 17:52:49 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/17 13:30:07 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rra(t_nb **a, t_nb **b, t_flag *flag, char **str)
{
	(void)b;
	if (a && *a && (*a)->previus != *b)
	{
		*str = JN(*str, DP("=rra\n"));
		*a = (*a)->previus;
		if (flag && flag->v)
			print_option_sw(*a, *b, str);
	}
}

void	rrb(t_nb **a, t_nb **b, t_flag *flag, char **str)
{
	(void)a;
	if (b && *b && (*b)->previus != *b)
	{
		*str = JN(*str, DP("=rrb\n"));
		*b = (*b)->previus;
		if (flag && flag->v)
			print_option_sw(*a, *b, str);
	}
}

void	rrr(t_nb **a, t_nb **b, t_flag *flag, char **str)
{
	rra(a, b, flag, str);
	rrb(a, b, flag, str);
}
