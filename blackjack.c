/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackjack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 15:31:04 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/10 15:56:51 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	blackjack(char *str)
{
	int		nb;
	int		i;
	int		len;

	nb = 0;
	len = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			nb += *str - '0';
		else if (ft_strchr("TJDK", *str) != NULL)
			nb += 10;
		else 
		{
			i = 0;
			if (len == 0)
			{
				while (str[i])
				{
					if (str[i] == 'A')
						len++;
					i++;
				}
			}
		}
		str++;
	}
	if (len > 0)
	{
		while (len > 0)
		{
			if (len == 1 && nb + 11 <= 21)
				nb += 11;
			else
				nb += 1;
			len--;
		}
	}
	return (nb);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_putnbr(blackjack(av[1]));
	}
	return (0);
}
