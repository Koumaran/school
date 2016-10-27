/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:35:53 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/05 18:28:59 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_pile	*ft_init_a(char **av)
{
	int		i;
	t_pile	*first;
	t_pile	*tmp;

	i = -1;
	if (*av && **av == '-' && ft_strchr("cwsnpg", av[0][1]))
		av++;
	tmp = NULL;
	tmp = (t_pile *)malloc(sizeof(t_pile));
	first = tmp;
	tmp->nb = ft_atoi(av[++i]);
	tmp->next = NULL;
	while (av[++i])
	{
		tmp->next = (t_pile *)malloc(sizeof(t_pile) * 1);
		tmp = tmp->next;
		tmp->next = NULL;
		tmp->nb = ft_atoi(av[i]);
	}
	return (first);
}

static int		ft_get_opt(t_solv *solv, char **av)
{
	int i;

	i = 0;
	if (av[1] && av[1][0] == '-' && ft_strchr("cswnpg", av[1][1]))
	{
		while (av[1][++i] != '\0')
		{
			if (av[1][i] == 's')
				solv->opt |= FT_SBS;
			if (av[1][i] == 'n')
				solv->opt |= FT_NB_C;
			if (av[1][i] == 'c')
				solv->opt |= FT_COLORIZED | FT_SBS;
			if (av[1][i] == 'w')
				solv->opt |= FT_COLORIZED | FT_SBS | FT_WAIT;
			if (av[1][i] == 'p')
				solv->opt |= FT_PILE_A;
			if (av[1][i] == 'g')
				solv->opt |= FT_GAME | FT_SBS | FT_COLORIZED | FT_NB_C;
		}
		return (1);
	}
	return (0);
}

t_solv			*ft_initialisation(int ac, char **av)
{
	t_solv	*solv;
	int		i;

	solv = NULL;
	solv = (t_solv *)malloc(sizeof(t_solv) * 1);
	i = 0;
	if (solv)
		i = ft_get_opt(solv, av);
	if (!(i == 1 && av[2] == NULL) && solv)
	{
		solv->pile_a = ft_init_a(av + 1);
		solv->pile_b = NULL;
		solv->length = ac - 1 - i;
		solv->color = 0;
		return (solv);
	}
	if (solv)
		free(solv);
	solv = NULL;
	return (solv);
}
