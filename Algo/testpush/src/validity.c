/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 13:32:44 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/05 15:34:32 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_check_double(char **pile_a)
{
	int		i;
	int		j;

	i = 0;
	while (pile_a[i] != NULL)
	{
		j = 0;
		if (i == j)
			j++;
		while (pile_a[j])
		{
			if (!ft_strcmp(pile_a[i], pile_a[j]))
				return (0);
			j++;
			if (i == j)
				j++;
		}
		i++;
	}
	return (1);
}

int		ft_check_validity(int length, char **av)
{
	int i;

	i = 0;
	if (av[1][0] == '-' && ft_strchr("csnpwg", av[1][1]))
		i++;
	while (++i != length)
		if (!ft_strisdigit(av[i]))
			return (0);
	i = 0;
	while (++i != length)
		if (!ft_strisint(av[i]))
			return (0);
	return (1);
}
