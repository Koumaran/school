/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:26:53 by jsivanes          #+#    #+#             */
/*   Updated: 2016/04/22 17:40:14 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*tmp;

	tmp = NULL;
	if (size)
	{
		tmp = malloc(size);
		if (tmp)
			ft_bzero(tmp, size);
	}
	return (tmp);
}
