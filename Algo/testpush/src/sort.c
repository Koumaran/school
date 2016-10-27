/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 11:34:40 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/05 18:47:51 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_count_under_mid(t_solv *solv, int mid)
{
	t_pile	*tmp;
	int		count;

	count = 0;
	tmp = solv->pile_a;
	while (tmp)
	{
		if (tmp->nb < mid)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

static void	third_sort(t_solv *solv)
{
	int		event;
	int		to_get;

	while (solv->pile_b)
	{
		ft_get_extremes_b(solv);
		event = solv->biggest;
		while (solv->pile_b)
		{
			to_get = ft_get_smaller_b(solv, event);
			ft_rotate_well_b(solv, event);
			pa(solv, 1);
			event = to_get;
		}
	}
}

void		second_sort(t_solv *solv)
{
	int		mid;
	int		count;

	ft_get_extremes_a(solv);
	mid = solv->smallest;
	while (solv->pile_a)
	{
		mid += 75;
		count = ft_count_under_mid(solv, mid);
		while (solv->pile_a && count)
			if (solv->pile_a->nb <= mid)
			{
				pb(solv, 1);
				count--;
			}
			else
				ra(solv, 1);
	}
	third_sort(solv);
}

static int	ft_is_semi_sorted(t_solv *solv)
{
	t_pile	*tmp;
	int		asc;
	int		des;

	tmp = solv->pile_a;
	asc = 0;
	des = 0;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		ft_first_sort(t_solv *solv)
{
	t_pile	*tmp;

	tmp = solv->pile_a;
	while (solv->pile_a && !ft_is_semi_sorted(solv) && solv->pile_a->next)
	{
		ft_get_extremes_a(solv);
		if (ft_simple_swap(solv))
			;
		else if (ft_sec_swap(solv))
			;
		else if (solv->pile_a->nb == ft_get_bigger_a(solv, solv->smallest))
			ft_fourth_choice(solv);
		else
			ft_last_choice(solv, solv->smallest);
		if (ft_is_half_sorted(solv))
			ft_rotate_well_a(solv, solv->smallest);
	}
	while (solv->pile_b)
		pa(solv, 1);
}
