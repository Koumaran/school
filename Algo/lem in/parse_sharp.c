/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sharp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:57:31 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/23 12:24:07 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_sharp(t_lem *lem, t_string *string, char *line)
{
	t_room		*room;

	if (ft_strcmp(line, "##start") == 0)
	{
		get_next_line(0, &line);
		ft_stringaddnl(string, line, ft_strlen(line));
		if (!(room = check_room(lem, line, 1)))
			return (0);
		lem->start = room;
		lem->start->ant = lem->nb_ant;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		get_next_line(0, &line);
		ft_stringaddnl(string, line, ft_strlen(line));
		if (!(room = check_room(lem, line, 0)))
			return (0);
		lem->end = room;;
	}
	return (1);
}
