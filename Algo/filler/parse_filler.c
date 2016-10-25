/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 17:17:52 by jsivanes          #+#    #+#             */
/*   Updated: 2016/09/20 14:56:33 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_map(t_fil *fil, t_opt *opt)
{
	char	*str;
	char	**split;
	int		i;

	i = -1;
	split = NULL;
	if (fil->map)
		ft_memfree_2d(fil->map);
	if ((fil->map = (char**)ft_memalloc_2d(fil->m_x, fil->m_y)) == NULL)
		ft_error("Error Malloc");
	while (++i <= fil->m_y)
	{
		get_next_line(0, &str);
		if (opt->s)
			ft_putendl_fd(str, opt->fd);
		if (i != 0)
		{
			split = ft_strsplit(str, ' ');
			fil->map[i - 1] = split[1];
		}
		ft_strdel(&str);
	}
}

void	get_cube(t_fil *fil, t_opt *opt)
{
	char	*str;
	int		i;

	i = -1;
	if (fil->cube)
		ft_memfree_2d(fil->cube);
	if ((fil->cube = (char**)ft_memalloc_2d(fil->c_x, fil->c_y)) == NULL)
		ft_error("Error Malloc");
	while (++i < fil->c_y)
	{
		get_next_line(0, &str);
		if (opt->s)
			ft_putendl_fd(str, opt->fd);
		fil->cube[i] = ft_strdup(str);
		ft_strdel(&str);
	}
	resolver_filler(fil, opt);
}
