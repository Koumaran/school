/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 18:47:38 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/17 16:47:20 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_nb			*parse_checker(t_flag *flag, char **av, t_box *box, int y)
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
	check_double(box->a);
	return (box->a);
}

int					main(int argc, char **argv)
{
	t_box	box;
	t_flag	flag;

	if (argc == 1)
		return (1);
	ft_bzero(&box, sizeof(t_box));
	ft_bzero(&flag, sizeof(t_flag));
	box.a = parse_checker(&flag, ++argv, &box, 0);
	if (flag.h == 1)
	{
		ft_printf("Checker\nUse:\n\t./checker [option] ARG or INT\n");
		ft_printf("Option :\n\t-v: show operation step.\n");
		ft_printf("\t-r: reverse sort.\n\t-h: show help.\n");
	}
	if (operation(&box.a, NULL, &flag, NULL))
		ft_putstr("\033[32mOK\n\033[0m");
	else
		ft_error("\033[31mKO");
	return (0);
}
