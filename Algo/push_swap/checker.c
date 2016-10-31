/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 18:47:38 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/29 12:04:45 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_nb			*parse_checker(t_flag *flag, char **av, t_box *box)
{
	t_long		nb;
	char	**tab;
	int		i;

	while (*av)
	{
		tab = ft_strsplit(*av++, ' ');
		i = -1;
		while (tab[++i])
		{
			if (!ft_strncmp(tab[i], "-v", 2) || !ft_strncmp(tab[i], "-c", 2) ||
					!ft_strncmp(tab[i], "-r", 2))
				flag = add_flag_sw(tab[i], flag);
			else
			{
				nb = ft_atoi(tab[i]);
				if (nb > 2147483647 || nb < -2147483648)
					ft_error("\033[31mError");
				ft_list_push_back(&box->a, (int)nb);
			}
		}
		ft_memfree_2d(tab);
	}
	check_double(box->a);
	return (box->a);
}

int					main(int argc, char **argv)
{
	t_box		box;
	t_flag		flag;
	t_string	string;

	if (argc < 3)
	{
		ft_printf("Checker\nUse:\n\t./checker [option] \"1 2 3\" or 1 2 3\n");
		ft_printf("Option :\n\t-v: show operation step.\n");
		ft_printf("\t-r: reverse sort.\n");
		return (0);
	}
	ft_bzero(&box, sizeof(t_box));
	ft_bzero(&flag, sizeof(t_flag));
	box.a = parse_checker(&flag, ++argv, &box);
	if (operation(&box, &flag, &string))
		ft_putstr("\033[32mOK\n\033[0m");
	else
		ft_error("\033[31mKO");
	while (1);
	return (0);
}
