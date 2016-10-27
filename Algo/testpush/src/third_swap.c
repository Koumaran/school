/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:18:15 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/31 18:43:45 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_fourth_choice(t_solv *solv)
{
	pb(solv, 1);
	ft_rotate_well_a(solv, solv->smallest);
	pb(solv, 1);
	sb(solv, 1);
}

void		ft_last_choice(t_solv *solv, int smlst)
{
	if (solv->pile_a->nb == smlst)
		pb(solv, 1);
	else if (ft_is_nearest_begin_a(solv, smlst))
		ra(solv, 1);
	else
		rra(solv, 1);
}
