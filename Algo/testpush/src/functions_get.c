/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 15:45:35 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/30 17:11:36 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_get_extremes_a(t_solv *solv)
{
	t_pile	*tmp;

	tmp = solv->pile_a;
	solv->smallest = solv->pile_a->nb;
	solv->biggest = solv->pile_a->nb;
	while (tmp)
	{
		if (tmp->nb < solv->smallest)
			solv->smallest = tmp->nb;
		if (tmp->nb > solv->biggest)
			solv->biggest = tmp->nb;
		tmp = tmp->next;
	}
	tmp = solv->pile_a;
	while (tmp->next)
		tmp = tmp->next;
	solv->last = tmp->nb;
}

void	ft_get_extremes_b(t_solv *solv)
{
	t_pile	*tmp;

	tmp = solv->pile_b;
	solv->smallest = solv->pile_b->nb;
	while (tmp)
	{
		if (tmp->nb < solv->smallest)
			solv->smallest = tmp->nb;
		tmp = tmp->next;
	}
	tmp = solv->pile_b;
	solv->biggest = solv->pile_b->nb;
	while (tmp)
	{
		if (tmp->nb > solv->biggest)
			solv->biggest = tmp->nb;
		tmp = tmp->next;
	}
}

int		ft_get_smaller_b(t_solv *solv, int nb)
{
	int		smaller;
	t_pile	*tmp;

	tmp = solv->pile_b;
	smaller = solv->smallest;
	while (tmp)
	{
		if (tmp->nb > smaller && tmp->nb < nb)
			smaller = tmp->nb;
		tmp = tmp->next;
	}
	return (smaller);
}

int		ft_get_smaller_a(t_solv *solv, int nb)
{
	int		smaller;
	t_pile	*tmp;

	tmp = solv->pile_a;
	if (nb == solv->smallest)
		return (solv->biggest);
	smaller = solv->smallest;
	while (tmp)
	{
		if (tmp->nb > smaller && tmp->nb < nb)
			smaller = tmp->nb;
		tmp = tmp->next;
	}
	return (smaller);
}

int		ft_get_bigger_a(t_solv *solv, int nb)
{
	int		bigger;
	t_pile	*tmp;

	tmp = solv->pile_a;
	if (nb == solv->biggest)
		return (solv->smallest);
	bigger = solv->biggest;
	while (tmp)
	{
		if (tmp->nb < bigger && tmp->nb > nb)
			bigger = tmp->nb;
		tmp = tmp->next;
	}
	return (bigger);
}
