/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 19:22:17 by jsivanes          #+#    #+#             */
/*   Updated: 2015/10/20 13:16:25 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_putnbr(int n)
{
	if (n < 10)
	{
		ft_putchar('0');
		ft_putchar(n + '0');
	}
	else
	{
		ft_putchar(n / 10 + '0');
		ft_putchar(n % 10 + '0');
	}
	return (0);
}

void	ft_print_comb2(void)
{
	int		c1;
	int		c2;

	c1 = 0;
	c2 = 0;
	while (c1 < 99)
	{
		c2 = c1 + 1;
		while (c2 < 100)
		{
			ft_putnbr(c1);
			ft_putchar(' ');
			ft_putnbr(c2++);
			if (c1 < 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
		c1++;
	}
}
