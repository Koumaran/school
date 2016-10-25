/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:35:55 by jsivanes          #+#    #+#             */
/*   Updated: 2016/04/22 19:20:14 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s)
{
	char	*tmp;

	if (!s)
		return (NULL);
	if (!(tmp = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	return (tmp = ft_strcpy(tmp, s));
}
