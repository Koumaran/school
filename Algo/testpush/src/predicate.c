/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:22:03 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/05 16:29:59 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_is_half_sorted(t_solv *solv)
{
	int		nb;
	int		pn[2];
	int		bigger;
	int		smaller;
	t_pile	*tmp;

	nb = 0;
	tmp = solv->pile_a;
	if (solv->pile_b)
		return (0);
	while (tmp->next)
	{
		pn[0] = ft_get_pn(solv, tmp->nb, -1);
		pn[1] = ft_get_pn(solv, tmp->nb, 1);
		smaller = ft_get_smaller_a(solv, tmp->nb);
		bigger = ft_get_bigger_a(solv, tmp->nb);
		if (pn[0] != smaller || pn[1] != bigger)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		ft_is_sorted_asc(t_solv *solv)
{
	t_pile	*tmp;
	int		asc;
	int		length;

	tmp = solv->pile_a;
	asc = 0;
	length = solv->length - 1;
	while (tmp && tmp->next)
	{
		if (tmp->nb < tmp->next->nb)
			asc++;
		tmp = tmp->next;
	}
	if (asc != length)
		return (solv->length - asc - 1);
	return (0);
}

int		ft_is_rev_sorted(t_solv *solv)
{
	t_pile	*tmp;
	int		asc;

	tmp = solv->pile_a;
	asc = 0;
	while (tmp->next)
	{
		if (tmp->nb < tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		ft_is_nearest_begin_a(t_solv *solv, int nb)
{
	t_pile	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = solv->pile_a;
	while (tmp->nb != nb)
	{
		tmp = tmp->next;
		i++;
		j++;
	}
	while (tmp)
	{
		j++;
		tmp = tmp->next;
	}
	return (j / 2 > i ? 1 : 0);
}

int		ft_is_nearest_begin_b(t_solv *solv, int nb)
{
	t_pile	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = solv->pile_b;
	while (tmp && tmp->nb != nb)
	{
		tmp = tmp->next;
		i++;
		j++;
	}
	while (tmp)
	{
		j++;
		tmp = tmp->next;
	}
	return (j / 2 > i ? 1 : 0);
}
