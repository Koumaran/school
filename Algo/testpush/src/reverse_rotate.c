/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:55:22 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/05 17:36:24 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_solv *solv, int state)
{
	t_pile	*tmp1;
	t_pile	*tmp2;

	if (solv->pile_a && solv->pile_a->next)
	{
		tmp2 = solv->pile_a;
		while (tmp2->next)
		{
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}
		tmp2->next = solv->pile_a;
		solv->pile_a = tmp2;
		tmp1->next = NULL;
		if (state)
			ft_getsol(solv, "rra");
	}
}

void	rrb(t_solv *solv, int state)
{
	t_pile	*tmp1;
	t_pile	*tmp2;

	if (solv->pile_b && solv->pile_b->next)
	{
		tmp2 = solv->pile_b;
		while (tmp2->next)
		{
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}
		tmp2->next = solv->pile_b;
		solv->pile_b = tmp2;
		tmp1->next = NULL;
		if (state)
			ft_getsol(solv, "rrb");
	}
}

void	rrr(t_solv *solv, int state)
{
	rra(solv, 0);
	rrb(solv, 0);
	if (state)
		ft_getsol(solv, "rrr");
}
