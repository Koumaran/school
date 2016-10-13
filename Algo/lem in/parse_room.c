/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:06:35 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/13 18:13:03 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		check_number(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int		check_room_name(t_lem *lem, char *str)
{
	t_room		*tmp;

	tmp = lem->room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		check_room(t_lem *lem, char *line)
{
	char	**split;

	if (ft_nb_of_word(line, ' ') != 3)
		return (0);
	split = ft_strsplit(line, ' ');
	if (split[0][0] == 'L' || !check_number(split[1])
		|| !check_number(split[2]) || !add_room(lem, split))
		return (0);
	ft_memfree_2d(split);
	lem->nb_room += 1;
	return (1);
}

int		get_sharp(t_lem *lem, t_string *string, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		get_next_line(0, &line);
		ft_stringaddnl(string, line, ft_strlen(line));
		if (!check_room(lem, line))
			return (0);
		lem->start = ft_strsub(line, 0, ft_strchri(line, ' '));
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		get_next_line(0, &line);
		ft_stringaddnl(string, line, ft_strlen(line));
		if (!check_room(lem, line))
			return (0);
		lem->end = ft_strsub(line, 0, ft_strchri(line, ' '));
	}
	return (1);
}
