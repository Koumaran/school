/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 10:40:02 by exam              #+#    #+#             */
/*   Updated: 2016/10/24 20:33:09 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	brainfuck(char *str)
{
	int		i;
	char	*tab;
	char	*var = NULL;
	int		o;
	
	i = -1;
	tab = (char*)malloc(sizeof(char) * 2049);
	while (++i < 2049)
		tab[i] = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '>')
			tab++;
		else if (str[i] == '<')
			tab--;
		else if (str[i] == '+')
			*tab += 1;
		else if (str[i] == '-')
			*tab -= 1;
		else if (str[i] == '.')
			write (1, &(*tab), 1);
		else if (str[i] == '[')
		{
			o = 1;
			if (*tab == 0)
				while (str[++i] && o)
				{
					if (str[i] == '[')
						o++;
					if (str[i] == ']')
						o--;
				}
		}
		else if (str[i] == ']')
		{
			o = 1;
			if (*tab != 0)
				while (--i > -1 && o)
				{
					if (str[i] == ']')
						o++;
					if (str[i] == '[')
						o--;
				}
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		brainfuck(av[1]);
	}
	return (0);
}
