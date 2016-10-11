/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 20:43:37 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/17 19:47:22 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_file.h"
#include <stdio.h>

void	ft_do_op(char *s1, char *op, char *s2)
{
	int		nb1;
	int		nb2;
	int		i;
	t_opp	opp_tab[5];

	opp_tab[0].str = "+";
	opp_tab[0].f = &ft_add;
	opp_tab[1].str = "-";
	opp_tab[1].f = &ft_sub;
	opp_tab[2].str = "*";
	opp_tab[2].f = &ft_mult;
	opp_tab[3].str = "/";
	opp_tab[3].f = &ft_div;
	opp_tab[4].str = "%";
	opp_tab[4].f = &ft_mod;
	i = 0;
	nb1 = ft_atoi(s1);
	nb2 = ft_atoi(s2);
	while (i < 5 && opp_tab[i].str[0] != op[0])
		i++;
	if (i < 5)
		opp_tab[i].f(nb1, nb2);
	else
		ft_putnbr(0);
}

int		main(int ac, char **av)
{
	if (ac == 4)
	{
		ft_do_op(av[1], av[2], av[3]);
		ft_putchar('\n');
	}
	return (0);
}
