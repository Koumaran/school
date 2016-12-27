/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 10:08:37 by exam              #+#    #+#             */
/*   Updated: 2016/10/25 20:16:29 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		do_operation(int *tab, char *str, int len_t);

int		isnum(char c)
{
	if (c == '\0')
		return (0);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		iscalc(char c)
{
	if (c == '\0')
		return (0);
	if (c == '+')
		return (1);
	if (c == '-')
		return (1);
	if (c == '*')
		return (1);
	if (c == '/')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

int		do_calcule(char *str)
{
	int		i;
	int		j;
	int		len;
	int		*tab;

	i = -1;
	len = 0;
	if (!isnum(*str))
		return (0);
	while (str[++i])
	{
		if (isnum(str[i]))
		{
			len++;
			while (isnum(str[i]))
				i++;
		}
	}
	tab = (int*)malloc(sizeof(int) * len + 1);
	i = 0;
	j = -1;
	while (++j < len)
	{
		if (isnum(str[i]))
		{
			tab[j] = atoi(str + i);
			while (isnum(str[i]))
				i++;
		}
		while (str[i] && !isnum(str[i]))
			i++;
	}
	return (do_operation(tab, str, len));
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\n");
		return (0);
	}
	if (!do_calcule(av[1]))
		printf("Error\n");
	return (0);
}
