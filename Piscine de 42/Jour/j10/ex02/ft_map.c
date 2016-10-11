/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 12:41:22 by jsivanes          #+#    #+#             */
/*   Updated: 2016/01/14 12:44:49 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		i;
	int		*res;

	i = 0;
	if (!(res = (int *)malloc(sizeof(int) * (length + 1))))
		return (NULL);
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
