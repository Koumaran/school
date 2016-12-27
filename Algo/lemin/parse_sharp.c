/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sharp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:57:31 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/26 21:58:10 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		get_bonus(t_string *string, t_lem *lem, char **line)
{
	if (ft_strcmp(*line, "##file") == 0)
	{
		ft_strdel(line);
		get_next_line(0, line);
		if (!*line)
			ft_error("Need a name for file");
		ft_stringaddnl(string, *line, ft_strlen(*line));
		if ((lem->fd = open(*line, O_CREAT | O_WRONLY)) < 0)
			lem->fd = open(*line, O_RDONLY | O_WRONLY | O_TRUNC);
		if (chmod(*line, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
			ft_error("error chmod");
	}
	else if (ft_strcmp(*line, "##way") == 0)
		lem->bonus_way = 1;
	else if (ft_strcmp(*line, "##step") == 0)
		lem->step = 1;
	else if (!ft_strcmp(*line, "##map"))
		lem->map = 1;
}

int				get_sharp(t_lem *lem, t_string *string, char **line)
{
	t_room		*room;

	if (ft_strcmp(*line, "##start") == 0)
	{
		ft_strdel(line);
		get_next_line(0, line);
		ft_stringaddnl(string, *line, ft_strlen(*line));
		if (!(room = check_room(lem, *line, 1)))
			return (0);
		lem->start = room;
	}
	else if (ft_strcmp(*line, "##end") == 0)
	{
		ft_strdel(line);
		get_next_line(0, line);
		ft_stringaddnl(string, *line, ft_strlen(*line));
		if (!(room = check_room(lem, *line, 0)))
			return (0);
		lem->end = room;
	}
	else
		get_bonus(string, lem, line);
	return (1);
}
