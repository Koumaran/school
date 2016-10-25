/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 18:55:34 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/17 13:52:40 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		sa(t_nb **a, t_nb **b, t_flag *flag, char **str)
{
	t_nb	*tmp_a;
	int		x;

	tmp_a = *a;
	(void)b;
	if (tmp_a && tmp_a->next != tmp_a)
	{
		*str = JN(*str, DP("=sa\n"));
		x = tmp_a->nb;
		tmp_a->nb = tmp_a->next->nb;
		tmp_a->next->nb = x;
		if (flag && flag->v)
			print_option_sw(*a, *b, str);
	}
}

void		sb(t_nb **a, t_nb **b, t_flag *flag, char **str)
{
	t_nb	*tmp_b;
	int		x;

	(void)a;
	tmp_b = *b;
	if (tmp_b && tmp_b->next != tmp_b)
	{
		*str = JN(*str, DP("=sb\n"));
		x = tmp_b->nb;
		tmp_b->nb = tmp_b->next->nb;
		tmp_b->next->nb = x;
		if (flag && flag->v)
			print_option_sw(*a, *b, str);
	}
}

void		ss(t_nb **a, t_nb **b, t_flag *flag, char **str)
{
	if (*a && (*a)->next != *a)
		sa(a, b, flag, str);
	if (*b && (*b)->next != *b)
		sb(a, b, flag, str);
}
