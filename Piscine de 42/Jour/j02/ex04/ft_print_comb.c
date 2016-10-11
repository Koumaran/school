/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 14:09:56 by jsivanes          #+#    #+#             */
/*   Updated: 2016/07/07 19:12:54 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_printnbr(char n[])
{
	ft_putchar(n[0]);
	ft_putchar(n[1]);
	ft_putchar(n[2]);
	if (n[0] != '7')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char numero[3];

	numero[0] = '0';
	numero[1] = '1';
	numero[2] = '2';
	while (numero[0] <= '7' && numero[1] <= '8' && numero[2] <= '9')
	{
		if (numero[0] != numero[1] && numero[1] != numero[2])
		{
			ft_printnbr(numero);
		}
		numero[2]++;
		while (numero[2] == '9' + 1)
		{
			numero[2] = numero[1]++ + 1;
			if (numero[1] == '8' + 1)
				numero[1] = numero[0]++ + 1;
		}
	}
}
