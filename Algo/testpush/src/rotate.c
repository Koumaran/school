/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:55:34 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/05 16:27:28 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_solv *solv, int state)
{
	t_pile *tmp1;
	t_pile *tmp2;

	if (!solv->pile_a || !solv->pile_a->next)
		return ;
	tmp1 = solv->pile_a;
	solv->pile_a = solv->pile_a->next;
	tmp2 = solv->pile_a;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp1;
	tmp1->next = NULL;
	if (state)
		ft_getsol(solv, "ra");
}

void	rb(t_solv *solv, int state)
{
	t_pile *tmp1;
	t_pile *tmp2;

	if (!solv->pile_b || !solv->pile_b->next)
		return ;
	tmp1 = solv->pile_b;
	solv->pile_b = solv->pile_b->next;
	tmp2 = solv->pile_b;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp1;
	tmp1->next = NULL;
	if (state)
		ft_getsol(solv, "rb");
}

void	rr(t_solv *solv, int state)
{
	ra(solv, 0);
	rb(solv, 0);
	if (state)
		ft_getsol(solv, "rr");
}
