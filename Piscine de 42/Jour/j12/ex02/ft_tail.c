/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:02:10 by jsivanes          #+#    #+#             */
/*   Updated: 2016/02/24 16:32:21 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tail(int argc, char **argv)
{
	int	nb;
	int	i;
	int	in;

	i = 3;
	in = 0;
	nb = ft_atoi(argv[2]);
	while (argv[i])
	{
		if (argc > 4)
		{
			if (in++)
				ft_putchar('\n');
			ft_putstr("==> ");
			ft_putstr(argv[i]);
			ft_putstr(" <==\n");
		}
		ft_display_tail(argv[i], nb, ft_sign(argv[2]));
		i++;
	}
}
