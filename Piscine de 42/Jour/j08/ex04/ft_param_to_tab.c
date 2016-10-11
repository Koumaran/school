/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 16:27:37 by jsivanes          #+#    #+#             */
/*   Updated: 2015/11/05 17:08:26 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

char					*ft_strdup(char *str)
{
	char	*ptr;
	char	*res;

	ptr = str;
	while (*ptr)
		++ptr;
	if (!(res = (char *)malloc(ptr - str)))
		return (0);
	ptr = str - 1;
	while (*(++ptr))
		res[ptr - str] = *ptr;
	return (res);
}

int						ft_strlen(char *str)
{
	char	*cpy;

	cpy = str;
	while (*cpy)
		++cpy;
	return (cpy - str);
}

struct s_stock_par		*ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*res;
	int				i;

	res = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1));
	i = -1;
	while (++i < ac)
	{
		res[i].str = av[i];
		res[i].copy = ft_strdup(av[i]);
		res[i].size_param = ft_strlen(av[i]);
		res[i].tab = ft_split_whitespaces(av[i]);
	}
	res[ac].str = 0;
	return (res);
}
