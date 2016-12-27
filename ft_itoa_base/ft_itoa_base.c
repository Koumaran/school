/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:27:43 by exam              #+#    #+#             */
/*   Updated: 2016/10/25 20:18:09 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*base_s;
	int		i;
	unsigned int	tmp;

	if (!value || base < 2)
	{
		str = (char*)malloc(sizeof(char) * 2);
		str[0] = '0';
		return (str);
	}
	base_s = "0123456789ABCDEF\0";
	tmp = (value < 0) ? (unsigned int)-value : (unsigned int)value;
	i = (value < 0 && base == 10) ? 2 : 1;
	while ((tmp /= base))
		i++;
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	tmp = (value < 0) ? (unsigned int)-value : (unsigned int)value;
	while (tmp)
	{
		str[--i] = base_s[tmp % base];
		tmp /= base;
	}
	if (i > 0)
		str[--i] = '-';
	return (str);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
	return (0);
}
