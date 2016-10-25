/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:42:58 by jsivanes          #+#    #+#             */
/*   Updated: 2016/03/18 15:43:03 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	i = -1;
	if (!(tmp = (char*)ft_memalloc(ft_strlen(s) + 1)))
		return (tmp);
	if (!s)
		return (tmp);
	while (s[++i])
		tmp[i] = f(s[i]);
	return (tmp);
}
