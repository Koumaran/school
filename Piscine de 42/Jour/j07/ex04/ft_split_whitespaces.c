/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 17:14:44 by jsivanes          #+#    #+#             */
/*   Updated: 2015/11/05 19:56:17 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strcountword(char *str)
{
	int		i;
	int		mot;

	i = 0;
	mot = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
				i++;
			mot++;
		}
		else
			i++;
	}
	return (mot);
}

int		ft_nb_word(char *str, int j, int tab[])
{
	int		i;

	i = 0;
	while (str[j] != '\0')
	{
		if (str[j] != ' ' && str[j] != '\n' && str[j] != '\t')
		{
			i = j;
			while (str[j] != ' ' && str[j] != '\n' && str[j] != '\t' && str[j])
				j++;
			tab[0] = j - i;
			break ;
		}
		j++;
	}
	return (i);
}

char	**ft_split_whitespaces(char *str)
{
	char	**argv;
	int		i;
	int		j;
	int		v;
	int		tab[0];

	i = 0;
	j = 0;
	if (!(argv = (char**)malloc(sizeof(char**) * (ft_strcountword(str) + 1))))
		return (NULL);
	while (i < ft_strcountword(str))
	{
		v = 0;
		j = ft_nb_word(str, j, tab);
		if (!(argv[i] = (char*)malloc(sizeof(char*) * (tab[0] + 1))))
			return (NULL);
		while (v < tab[0])
		{
			argv[i][v++] = str[j++];
		}
		argv[i][v] = '\0';
		i++;
	}
	argv[ft_strcountword(str)] = NULL;
	return (argv);
}
