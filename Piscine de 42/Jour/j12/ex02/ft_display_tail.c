/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:08:38 by jsivanes          #+#    #+#             */
/*   Updated: 2016/02/24 16:33:28 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			filelen(char *str)
{
	char	tmp;
	int		i;
	int		fd;

	i = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &tmp, 1))
		i++;
	close(fd);
	return (i);
}

void		ft_display_tail(char *str, int nb, char sign)
{
	char	txt;
	int		fd;
	int		len;
	int		i;

	i = 0;
	len = filelen(str);
	fd = open(str, O_RDONLY);
	while (read(fd, &txt, 1))
	{
		if (sign == '+')
		{
			if (i >= nb - 1)
				ft_putchar(txt);
		}
		else
		{
			if (i >= len - nb)
				ft_putchar(txt);
		}
		i++;
	}
	close(fd);
}
