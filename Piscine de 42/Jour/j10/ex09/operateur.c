/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operateur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 20:52:28 by jsivanes          #+#    #+#             */
/*   Updated: 2016/01/11 20:50:29 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_file.h"

void	ft_add(int nb1, int nb2)
{
	ft_putnbr(nb1 + nb2);
}

void	ft_sub(int nb1, int nb2)
{
	ft_putnbr(nb1 - nb2);
}

void	ft_div(int nb1, int nb2)
{
	if (nb2 == 0)
		ft_putstr("Stop : division by zero\0");
	else
		ft_putnbr(nb1 / nb2);
}

void	ft_mul(int nb1, int nb2)
{
	ft_putnbr(nb1 * nb2);
}

void	ft_mod(int nb1, int nb2)
{
	if (nb2 == 0)
		ft_putstr("Stop : modulo by zero\0");
	else
		ft_putnbr(nb1 % nb2);
}
