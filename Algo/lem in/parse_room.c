/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:06:35 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/22 13:58:11 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_number(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

t_room		*check_room_name(t_lem *lem, char *str)
{
	t_room		*tmp;

	tmp = lem->room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room		*check_room(t_lem *lem, char *line, int lvl)
{
	char	**split;
	t_room	*room;

	if (ft_nb_of_word(line, ' ') != 3)
		return (NULL);
	split = ft_strsplit(line, ' ');
	if (split[0][0] == 'L' || !check_number(split[1])
		|| !check_number(split[2]) || !(room = add_room(lem, split, lvl)))
		return (NULL);
	ft_memfree_2d(split);
	lem->nb_room += 1;
	return (room);
}

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
