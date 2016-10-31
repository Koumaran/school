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

void	rra(t_nb **a, t_nb **b, t_flag *flag, t_string *string)
{
	(void)b;
	if (a && *a && (*a)->previus != *b)
	{
		ft_stringaddnl(string, "=rra", 4);
		*a = (*a)->previus;
		if (flag && flag->v)
			print_option_sw(*a, *b, string);
	}
}

void	rrb(t_nb **a, t_nb **b, t_flag *flag, t_string *string)
{
	(void)a;
	if (b && *b && (*b)->previus != *b)
	{
		ft_stringaddnl(string, "=rrb", 4);
		*b = (*b)->previus;
		if (flag && flag->v)
			print_option_sw(*a, *b, string);
	}
}

void	rrr(t_nb **a, t_nb **b, t_flag *flag, t_string *string)
{
	rra(a, b, flag, string);
	rrb(a, b, flag, string);
}
