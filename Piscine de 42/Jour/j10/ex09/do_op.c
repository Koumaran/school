/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 20:43:37 by jsivanes          #+#    #+#             */
/*   Updated: 2016/01/14 13:40:16 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_file.h"
#include "ft_opp.h"
#include <stdio.h>

void	ft_usage(int nb1, int nb2)
{
	ft_putstr("error : only [ ");
	while (nb1 < nb2)
	{
		ft_putstr(gl_opptab[nb1++].str);
		ft_putchar(' ');
	}
	ft_putstr("] are accepted.");
}

void	ft_do_op(char *s1, char *op, char *s2)
{
	int		nb1;
	int		nb2;
	int		i;

	i = 0;
	nb1 = ft_atoi(s1);
	nb2 = ft_atoi(s2);
	while (i < 5 && gl_opptab[i].str[0] != op[0])
		i++;
	if (i < 5)
		gl_opptab[i].f(nb1, nb2);
	else
		gl_opptab[i].f(0, 5);
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
