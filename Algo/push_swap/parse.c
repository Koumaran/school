/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 19:21:36 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/23 16:09:55 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_flag			*add_flag_sw(char *str, t_flag *flag)
{
	t_flag		*tmp;

	tmp = flag;
	if (CHR(str, 'v') != NULL)
		tmp->v = 1;
	if (CHR(str, 'c') != NULL)
		tmp->c = 1;
	if (CHR(str, 'r') != NULL)
		tmp->r = 1;
	if (CHR(str, 'h') != NULL)
		tmp->h = 1;
	while (*str)
	{
		if (CHR("-vcrh", *str) == NULL)
			ft_error("\033[31mError");
		str++;
	}
	return (tmp);
}

t_box			parse_swap(t_flag *flag, char **av, t_box *box, int y)
{
	int		nb;
	char	**tab;

	while (*av)
	{
		tab = ft_strsplit(*av++, ' ');
		while (*tab)
		{
			if (!ft_strncmp(*tab, "-v", 2) || !ft_strncmp(*tab, "-h", 2) ||
					!ft_strncmp(*tab, "-c", 2) || !ft_strncmp(*tab, "-r", 2))
				flag = add_flag_sw(*tab, flag);
			else
			{
				nb = ft_atoi(*tab);
				y = ft_strlen(*tab);
				if (CMP(ft_itoa(nb), *tab) ||
						(CMP(ft_itoa(nb), *tab) && y >= 10))
					ft_error("\033[31mError");
				ft_list_push_back(&box->a, nb);
			}
			free(*tab++);
		}
	}
	return (*box);
}
