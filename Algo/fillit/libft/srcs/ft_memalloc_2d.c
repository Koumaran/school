/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_sqrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:25:08 by jsivanes          #+#    #+#             */
/*   Updated: 2016/03/18 17:22:07 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_memalloc_2d(size_t x, size_t y)
{
	void	**tmp;
	size_t	i;

	i = 0;
	if (!(tmp = (void**)malloc(sizeof(tmp) * y)))
		return (tmp);
	while (i < y)
		tmp[i++] = (void*)ft_memalloc(x);
	return (tmp);
}
