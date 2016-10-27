/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 14:37:06 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/05 18:26:50 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ft_recognize_entry(t_solv *solv, char *rep)
{
	if (ft_strstr(rep, "sa"))
		sa(solv, 1);
	else if (ft_strstr(rep, "sb"))
		sb(solv, 1);
	else if (ft_strstr(rep, "ss"))
		ss(solv, 1);
	else if (ft_strstr(rep, "rra"))
		rra(solv, 1);
	else if (ft_strstr(rep, "rrb"))
		rrb(solv, 1);
	else if (ft_strstr(rep, "rrr"))
		rrr(solv, 1);
	else if (ft_strstr(rep, "ra"))
		ra(solv, 1);
	else if (ft_strstr(rep, "rb"))
		rb(solv, 1);
	else if (ft_strstr(rep, "rr"))
		rr(solv, 1);
	else if (ft_strstr(rep, "pa"))
		pa(solv, 1);
	else if (ft_strstr(rep, "pb"))
		pb(solv, 1);
}

void		ft_game(t_solv *solv)
{
	char	*rep;

	rep = NULL;
	ft_printf("%s\n%[b,B,U]T%s\n%[0]T", "valid operations :",
			"sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa, pb, exit");
	ft_print_pa(solv);
	ft_print_pb(solv);
	while (ft_is_sorted_asc(solv))
	{
		if (!(rep = ft_strnew(4)))
			break ;
		read(0, rep, 5);
		if (!ft_strstr(rep, "exit"))
			ft_recognize_entry(solv, rep);
		else
		{
			ft_printf("exit success\n");
			break ;
		}
	}
	solv->color = 0;
	ft_end_ps(solv);
}
