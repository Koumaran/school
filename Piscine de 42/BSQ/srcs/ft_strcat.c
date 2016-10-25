/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maplen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:16:30 by atoulous          #+#    #+#             */
/*   Updated: 2016/03/05 18:41:14 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *tmp, char buf)
{
	char	*str;
	int		i;

	i = 0;
	while (tmp[i])
		i++;
	str = malloc(sizeof(char*) * (i + 2));
	i = 0;
	while (tmp[i])
	{
		str[i] = tmp[i];
		i++;
	}
	str[i++] = buf;
	str[i] = '\0';
	return (str);
}
