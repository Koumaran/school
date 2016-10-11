/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 12:08:28 by jsivanes          #+#    #+#             */
/*   Updated: 2015/11/05 14:52:09 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strrev(char *str)
{
	int		i;
	char	x;
	int		j;

	j = 0;
	i = ft_strlen(str);
	while (j < i / 2)
	{
		x = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = x;
		j++;
	}
	return (str);
}

long int		ft_get_val(int size, char *nbr, char *base_from)
{
	int			i;
	int			j;
	int			sign;
	long int	val;

	i = -1;
	val = 0;
	sign = 1;
	if (nbr[0] == '-')
		sign = -1;
	while (nbr[++i])
	{
		j = 0;
		while (base_from[j] != nbr[i] && j < size)
			j++;
		if (base_from[j] == nbr[i])
		{
			val = val * size + j;
		}
	}
	return (val * sign);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			i;
	long int	val;
	long int	sign;
	char		*res;

	i = 0;
	val = ft_get_val(ft_strlen(base_from), nbr, base_from);
	sign = val;
	if (!(res = (char *)malloc(sizeof(char *) * (32 + 1))))
		return (NULL);
	if (val < 0)
		val = -val;
	while (val > 0)
	{
		res[i++] = base_to[(val % ft_strlen(base_to))];
		val = val / ft_strlen(base_to);
	}
	if (sign == 0)
		res[i++] = base_to[0];
	if (sign < 0)
		res[i++] = '-';
	res[i] = '\0';
	res = ft_strrev(res);
	return (res);
}
