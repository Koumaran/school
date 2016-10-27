/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:55:32 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/05 17:37:34 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_solv *solv, int state)
{
	t_pile *tmp;

	if (solv->pile_a && solv->pile_a->next)
	{
		tmp = solv->pile_a->next;
		solv->pile_a->next = tmp->next;
		tmp->next = solv->pile_a;
		solv->pile_a = tmp;
		if (state)
			ft_getsol(solv, "sa");
	}
}

void	sb(t_solv *solv, int state)
{
	t_pile *tmp;

	if (solv->pile_b && solv->pile_b->next)
	{
		tmp = solv->pile_b->next;
		solv->pile_b->next = tmp->next;
		tmp->next = solv->pile_b;
		solv->pile_b = tmp;
		if (state)
			ft_getsol(solv, "sb");
	}
}

void	ss(t_solv *solv, int state)
{
	sa(solv, 0);
	sb(solv, 0);
	if (state)
		ft_getsol(solv, "ss");
}
