/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 10:34:06 by exam              #+#    #+#             */
/*   Updated: 2016/10/25 20:16:30 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		iscalc(char c);
int		isnum(char c);

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		do_operation(int *tab, char *str, int len_t)
{
	int 	nb;
	char	op;
	int		len;
	int		i;
	int		t;
	int		p;

	nb = *tab;	
	len = ft_strlen(str);
	i = -1;
	t = 1;
	while (++i < len)
	{
		p = 0;
		while (!iscalc(str[i]) && i < len)
		{
			if (isnum(str[i]))
			{
				p++;
				while (isnum(str[i]) && i < len)
					i++;
			}
			else
				i++;
		}
		op = (str[i] != '\0') ? str[i] : 'p';
		if ((!iscalc(op) && op != '\0') || (str[i + 1] && str[i + 1] != ' '))
			return (0);
		if (iscalc(op) && t >= len_t)
			return (0);
		if (p-- > 2)
		{
			t += p - 1;
			while (--p)
			{
				if (op == '+')
					tab[t] = (int)(tab[p] + tab[t]);
				else if (op == '-')
					tab[t] = (int)(tab[p] - tab[t]);
				else if (op == '*')
					tab[t] = tab[p] * tab[t];
				else if (op == '/')
				{
					if (tab[t] == 0)
						return (0);
					tab[t] = tab[p] / tab[t];
				}
				else if (op == '%')
				{
					if (tab[t] == 0)
						return (0);
					tab[t] = tab[p] % tab[t];
				}
				i += 2;
				op = str[i];
				if ((!iscalc(op) && op != '\0') || (str[i + 1] && str[i + 1] != ' '))
					return (0);
			}
		}
		if (op == '+')
			nb = nb + tab[t++];
		else if (op == '-')
			nb = nb - tab[t++];
		else if (op == '*')
			nb *= tab[t++];
		else if (op == '/')
		{
			if (tab[t] == 0)
				return (0);
			nb = nb / tab[t++];
		}
		else if (op == '%')
		{
			if (tab[t] == 0)
				return (0);
			nb %= tab[t++];
		}
	}
	if (t < len_t)
		return (0);
	printf("%d\n", nb);
	return (1);
}
