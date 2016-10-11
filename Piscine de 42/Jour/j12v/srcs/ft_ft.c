/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <maxpetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 12:25:09 by maxpetit          #+#    #+#             */
/*   Updated: 2016/02/03 12:10:57 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"

void	ft_swap_str(unsigned char **str1, unsigned char **str2)
{
	unsigned	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_puterror(char *name_prg, char *name_file, char *str)
{
	(void)name_prg;
	write(2, "tail", 4);
	write(2, ": ", 2);
	if (name_file != 0)
	{
		write(2, name_file, ft_strlen(name_file));
		write(2, ": ", 2);
	}
	if (str)
		write(2, str, ft_strlen(str));
}

void	ft_putstr(unsigned char *str, int nb_char)
{
	write(1, str, nb_char);
}

char	*ft_strdump(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char*)malloc((sizeof(char) + 1) * ft_strlen(str));
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
