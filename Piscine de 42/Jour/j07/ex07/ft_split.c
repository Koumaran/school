/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 15:46:52 by jsivanes          #+#    #+#             */
/*   Updated: 2015/11/05 16:06:15 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strcountword(char *str, char *set)
{
	int		i;
	int		j;
	int		mot;

	i = 0;
	mot = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != set[j] && set[j])
			j++;
		if (j == ft_strlen(set))
		{
			while (j == ft_strlen(set) && str[i])
			{
				j = 0;
				i++;
				while (str[i] != set[j] && set[j])
					j++;
			}
			mot++;
		}
		i++;
	}
	return (mot);
}

int		ft_nb_word(char *str, char *set, int j, int tab[])
{
	int		i;
	int		k;

	i = 0;
	while (str[j] != '\0')
	{
		k = 0;
		while (str[j] != set[k] && set[k])
			k++;
		if (k == ft_strlen(set))
		{
			i = j;
			while (k == ft_strlen(set) && str[j])
			{
				k = 0;
				j++;
				while (str[j] != set[k] && set[k])
					k++;
			}
			tab[0] = j - i;
			break ;
		}
		j++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**argv;
	int		i;
	int		j;
	int		v;
	int		tab[0];

	i = -1;
	j = 0;
	if (!(argv = (char**)malloc(sizeof(char**)
					* (ft_strcountword(str, charset) + 1))))
		return (NULL);
	while (++i < ft_strcountword(str, charset))
	{
		v = 0;
		j = ft_nb_word(str, charset, j, tab);
		if (!(argv[i] = (char*)malloc(sizeof(char*) * (tab[0] + 1))))
			return (NULL);
		while (v < tab[0])
		{
			argv[i][v++] = str[j++];
		}
		argv[i][v] = '\0';
	}
	argv[ft_strcountword(str, charset)] = NULL;
	return (argv);
}
