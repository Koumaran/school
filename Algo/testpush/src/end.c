/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:45:43 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/05 18:28:08 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_free_pile(t_pile **pile)
{
	if (*pile && (*pile)->next)
		ft_free_pile(&((*pile)->next));
	free(*pile);
	*pile = NULL;
}

static void	ft_print_nb_c(t_solv *solv)
{
	int i;
	int nb;

	i = -1;
	nb = 0;
	if (solv->opt & FT_NB_C)
	{
		ft_printf("\n%[g,B]T%s%s%s%[0]T",
			"[           ---------------          ]\n",
			"------------NOMBRE-DE-COUPS-----------\n",
			"[           ---------------          ]\n");
		while (solv->solution && solv->solution[++i])
			if (solv->solution[i] == ' ')
				nb++;
		if (solv->solution)
			nb++;
		ft_printf("Nombre de coups : %d\n", nb);
	}
}

void		ft_end_ps(t_solv *solv)
{
	ft_printf("%[g,B]T%s%s%s%[0]T%s\n",
			"[              --------              ]\n",
			"---------------SOLUTION---------------\n",
			"[              --------              ]\n",
			solv->solution);
	if (solv->opt & FT_SBS)
	{
		ft_printf("\n%[g,B]T%s%s%s%[0]T",
			"[             ----------             ]\n",
			"--------------ETAT-FINAL--------------\n",
			"[             ----------             ]\n");
		ft_print_pa(solv);
	}
	if (solv->opt & FT_PILE_A)
		ft_print_pa(solv);
	ft_print_nb_c(solv);
	ft_free_pile(&(solv->pile_a));
	ft_free_pile(&(solv->pile_b));
	free(solv->solution);
	free(solv);
}
