/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:55:18 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/31 18:56:52 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_solv *solv, int state)
{
	t_pile	*tmp;

	if (solv->pile_a)
	{
		tmp = solv->pile_a;
		solv->pile_a = solv->pile_a->next;
		tmp->next = solv->pile_b;
		solv->pile_b = tmp;
		tmp = solv->pile_b;
		if (state)
			ft_getsol(solv, "pb");
	}
}

void	pa(t_solv *solv, int state)
{
	t_pile	*tmp;

	if (solv->pile_b)
	{
		tmp = solv->pile_b;
		solv->pile_b = solv->pile_b->next;
		tmp->next = solv->pile_a;
		solv->pile_a = tmp;
		if (state)
			ft_getsol(solv, "pa");
	}
}
