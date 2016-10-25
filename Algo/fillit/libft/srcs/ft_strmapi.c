/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:43:13 by jsivanes          #+#    #+#             */
/*   Updated: 2016/03/18 15:43:17 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*tmp;

	i = -1;
	if (!(tmp = (char*)ft_memalloc(ft_strlen(s) + 1)))
		return (tmp);
	if (!*s)
		return (tmp);
	while (s[++i])
		tmp[i] = f(i, s[i]);
	return (tmp);
}
