/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:47:39 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/06 17:26:10 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		get_map_puzzle(t_fil *fil, t_opt *opt, char *str)
{
	char	**tab;

	tab = NULL;
	if (ft_strncmp(str, "Plateau", 7) == 0)
	{
		if (opt->s)
			ft_putendl_fd(str, opt->fd);
		tab = ft_strsplit(str, ' ');
		fil->m_y = ft_atoi(tab[1]);
		fil->m_x = ft_atoi(tab[2]);
		get_map(fil, opt);
	}
	else if (ft_strncmp(str, "Piece", 5) == 0)
	{
		if (opt->s)
			ft_putendl_fd(str, opt->fd);
		tab = ft_strsplit(str, ' ');
		fil->c_y = ft_atoi(tab[1]);
		fil->c_x = ft_atoi(tab[2]);
		get_cube(fil, opt);
	}
	if (tab != NULL)
		ft_memfree_2d(tab);
}

static void		get_player(t_fil *fil, t_opt *opt)
{
	char	*str;

	str = NULL;
	while (get_next_line(0, &str))
	{
		if (ft_strncmp(str, "$$$ exec p1 : [", 15) == 0)
		{
			fil->h = 'O';
			fil->v = 'x';
			if (opt->s)
				ft_putendl_fd(str, opt->fd);
		}
		else if (ft_strncmp(str, "$$$ exec p2 : [", 15) == 0)
		{
			fil->h = 'X';
			fil->v = 'o';
			if (opt->s)
				ft_putendl_fd(str, opt->fd);
		}
		get_map_puzzle(fil, opt, str);
		ft_strdel(&str);
	}
	if (str != NULL)
		ft_strdel(&str);
}

int				main(int ac, char **av)
{
	t_fil	fil;
	t_opt	opt;

	ft_bzero(&fil, sizeof(t_fil));
	ft_bzero(&opt, sizeof(t_opt));
	if (ac == 2)
		get_optionfil(&opt, av[1]);
	fil.orientation = -1;
	fil.h_y = -1;
	get_player(&fil, &opt);
	if (fil.map)
		ft_memfree_2d(fil.map);
	if (fil.cube)
		ft_memfree_2d(fil.cube);
	if (opt.s)
		close(opt.fd);
	return (0);
}
