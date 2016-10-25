/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:27:55 by jsivanes          #+#    #+#             */
/*   Updated: 2016/03/02 14:00:02 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str, char *name_file, int error)
{
	if (error == 2)
	{
		write(2, "cat: ", 5);
		write(2, name_file, ft_strlen(name_file));
		write(2, ": ", 2);
		write(2, str, ft_strlen(str));
	}
	if (error == 1)
		write(1, str, ft_strlen(str));
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
