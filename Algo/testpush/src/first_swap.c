/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:16:40 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/05 18:27:39 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_simple_swap_tests(t_solv *solv, t_pile *tmp, t_pile *tmp2)
{
	int ok;

	ok = 0;
	if (tmp->next && tmp->next->nb == solv->biggest)
		ok = 1;
	else if (tmp->next && tmp2->nb == ft_get_bigger_a(solv, tmp->nb))
		ok = 2;
	else if (tmp2->nb == ft_get_bigger_a(solv, tmp->nb))
		ok = 2;
	return (ok);
}

int			ft_simple_swap(t_solv *solv)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	int		ok;

	ok = 0;
	tmp = solv->pile_a;
	tmp2 = tmp;
	while (tmp2->next)
		tmp2 = tmp2->next;
	while (tmp->nb != solv->smallest && (tmp2 = tmp))
		tmp = tmp->next;
	ok = ft_simple_swap_tests(solv, tmp, tmp2);
	if (ok == 1)
	{
		ft_rotate_well_a(solv, tmp->nb);
		sa(solv, 1);
	}
	if (ok == 2)
	{
		ft_rotate_well_a(solv, ft_get_bigger_a(solv, tmp->nb));
		sa(solv, 1);
	}
	return (ok);
}

int			ft_sec_swap(t_solv *solv)
{
	t_pile *tmp;
	t_pile *tmp2;

	tmp = solv->pile_a;
	tmp2 = solv->pile_a;
	while (tmp2->next)
		tmp2 = tmp2->next;
	while (tmp)
	{
		if (tmp2->nb == ft_get_smaller_a(solv, ft_get_pn(solv, tmp->nb, 1)))
		{
			if (tmp->nb == ft_get_bigger_a(solv, ft_get_pn(solv, tmp->nb, 1)))
			{
				ft_rotate_well_a(solv, tmp->nb);
				sa(solv, 1);
				return (1);
			}
		}
		tmp2 = tmp;
		tmp = tmp->next;
	}
	return (0);
}
