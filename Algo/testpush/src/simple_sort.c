/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 16:20:51 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/05 18:30:47 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_rotate_well_a(t_solv *solv, int to_sort)
{
	int event;

	event = to_sort;
	if (ft_is_nearest_begin_a(solv, to_sort))
		while (solv->pile_a->nb != to_sort)
			ra(solv, 1);
	else
		while (solv->pile_a->nb != to_sort)
			rra(solv, 1);
}

void		ft_rotate_well_b(t_solv *solv, int to_sort)
{
	int event;

	event = to_sort;
	if (ft_is_nearest_begin_b(solv, to_sort))
		while (solv->pile_b->nb != to_sort)
			rb(solv, 1);
	else
		while (solv->pile_b->nb != to_sort)
			rrb(solv, 1);
}

int			ft_get_smlst_to_swap(t_solv *solv)
{
	int		nb;
	int		pn;
	int		smaller;
	t_pile	*tmp;

	tmp = solv->pile_a;
	nb = solv->biggest;
	while (tmp)
	{
		pn = ft_get_pn(solv, tmp->nb, -1);
		smaller = ft_get_smaller_a(solv, tmp->nb);
		if (pn != smaller && tmp->nb < nb && nb != solv->smallest)
			nb = tmp->nb;
		tmp = tmp->next;
	}
	ft_printf("%d\n%d\n", nb, solv->smallest);
	return (nb);
}

int			ft_get_pn(t_solv *solv, int nb, int pn)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = solv->pile_a;
	tmp2 = tmp;
	while (tmp->nb != nb)
		tmp = tmp->next;
	if (tmp == solv->pile_a && pn == -1)
	{
		while (tmp->next)
			tmp = tmp->next;
		return (tmp->nb);
	}
	else if (!tmp->next && pn == 1)
		return (solv->pile_a->nb);
	else if (pn == 1)
		return (tmp->next->nb);
	else if (pn == -1)
		while (tmp2->next != tmp)
			tmp2 = tmp2->next;
	return (tmp2->nb);
}
