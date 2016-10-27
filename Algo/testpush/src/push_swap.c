/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 13:13:40 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/05 18:51:54 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rev_sort(t_solv *solv)
{
	while (solv->pile_a)
	{
		pb(solv, 1);
		rb(solv, 1);
	}
	while (solv->pile_b)
		pa(solv, 1);
}

static void	ft_solve(t_solv *solv)
{
	int		ret;

	ret = 0;
	if (solv->pile_a->next && (ret = ft_is_sorted_asc(solv)))
	{
		if (ft_is_rev_sorted(solv))
			rev_sort(solv);
		else if (solv->length > 100)
			second_sort(solv);
		else
			ft_first_sort(solv);
		solv->color = 0;
		ft_end_ps(solv);
	}
	else
		ft_printf("\n");
}

int			main(int ac, char **av)
{
	t_solv	*solv;

	solv = NULL;
	if (ac < 2 || ft_check_validity(ac, av) == 0 ||
		!(solv = ft_initialisation(ac, av)) || ft_check_double(av) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	solv->solution = NULL;
	if (solv->opt & FT_GAME)
		ft_game(solv);
	else
		ft_solve(solv);
	return (1);
}
