/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 19:21:36 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/28 19:38:08 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		get_extrem_box(t_box *box, t_nb *pile)
{
	box->max = ft_big_elem(pile);
	box->min = ft_small_elem(pile);
	box->len = get_len(pile, &box->midl);
}

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
	while (*str)
	{
		if (CHR("-vcr", *str) == NULL)
			ft_error("\033[31mError");
		str++;
	}
	return (tmp);
}

t_box			parse_swap(t_flag *flag, char **av, t_box *box)
{
	t_long		nb;
	int		i;
	char	**tab;

	while (*av)
	{
		tab = ft_strsplit(*av++, ' ');
		i = -1;
		while (tab[++i])
		{
			if (!ft_strncmp(tab[i], "-v", 2) ||
					!ft_strncmp(tab[i], "-c", 2) || !ft_strncmp(tab[i], "-r", 2))
				flag = add_flag_sw(tab[i], flag);
			else
			{
				nb = ft_atoi(tab[i]);
				if (nb < -2147483648 || nb > 2147483647)
					ft_error("\033[31mError");
				ft_list_push_back(&box->a, nb);
			}
		}
		ft_memfree_2d(tab);
	}
	return (*box);
}
