/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_end_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:30:46 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/24 17:43:31 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_print_pa(t_solv *solv)
{
	t_pile	*tmp;
	int		nb_p;

	nb_p = 0;
	tmp = solv->pile_a;
	ft_printf("A : [ ");
	while (tmp)
	{
		if (solv->opt & FT_COLORIZED && nb_p == 0 && solv->color & FT_FA)
			ft_printf("%[g,B]T%d%[0]T ", tmp->nb);
		else if (solv->opt & FT_COLORIZED && nb_p == 1 &&
				solv->color & FT_SA)
			ft_printf("%[g,B]T%d%[0]T ", tmp->nb);
		else if (solv->opt & FT_COLORIZED && tmp->next == NULL &&
					solv->color & FT_LA)
			ft_printf("%[g,B]T%d%[0]T ", tmp->nb);
		else
			ft_printf("%d ", tmp->nb);
		nb_p++;
		tmp = tmp->next;
	}
	ft_printf("]\n");
}

void		ft_print_pb(t_solv *solv)
{
	t_pile	*tmp;
	int		nb_p;

	nb_p = 0;
	tmp = solv->pile_b;
	ft_printf("B : [ ");
	while (tmp)
	{
		if (solv->opt & FT_COLORIZED && nb_p == 0 && solv->color & FT_FB)
			ft_printf("%[g,B]T%d%[0]T ", tmp->nb);
		else if (solv->opt & FT_COLORIZED && nb_p == 1 &&
				solv->color & FT_SB)
			ft_printf("%[g,B]T%d%[0]T ", tmp->nb);
		else if (solv->opt & FT_COLORIZED && tmp->next == NULL &&
					solv->color & FT_LB)
			ft_printf("%[g,B]T%d%[0]T ", tmp->nb);
		else
			ft_printf("%d ", tmp->nb);
		nb_p++;
		tmp = tmp->next;
	}
	ft_printf("]\n");
}

static void	ft_get_ope_next(t_solv *solv, char *ope)
{
	if (ope[0] == 'r')
	{
		if (ope[2] == 'a' || ope[2] == 'r')
			solv->color = FT_FA;
		if (ope[2] == 'b' || ope[2] == 'r')
			solv->color = FT_FB;
	}
	else if (ope[0] == 'p')
	{
		if (ope[1] == 'a')
			solv->color = FT_FA;
		else if (ope[1] == 'b')
			solv->color = FT_FB;
	}
	else
		solv->color = 0;
}

void		ft_get_ope(t_solv *solv, char *ope)
{
	if (ope[0] == 's')
	{
		if (ope[1] == 'a' || ope[1] == 's')
			solv->color = FT_FA | FT_SA;
		if (ope[1] == 'b' || ope[1] == 's')
			solv->color = FT_FB | FT_SB;
	}
	else if (ope[0] == 'r' && ope[1] != 'r')
	{
		if (ope[1] == 'a' || ope[1] == 'r')
			solv->color = FT_LA;
		if (ope[1] == 'b' || ope[1] == 'r')
			solv->color = FT_LB;
	}
	else
	{
		ft_get_ope_next(solv, ope);
	}
}
