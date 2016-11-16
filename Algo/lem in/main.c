/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 13:34:49 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/16 15:21:58 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_connect(t_lem *lem, char *line)
{
	char		**split;
	t_room		*r1;
	t_room		*r2;

	if (lem->nb_room < 2 || !(split = ft_strsplit(line, '-')))
		return (0);
	if (ft_strcmp(split[0], split[1]) == 0)
		return (0);
	if (!(r1 = check_room_name(lem, split[0])) || !(r2 = check_room_name(lem, split[1])))
		return (0);
	if (!create_connection(lem, r1, r2))
		return (0);
	lem->nb_join += 1;
	ft_memfree_2d(split);
	return (1);
}

int		last_check(t_lem *lem)
{
	if (lem->nb_room < 2 || !lem->nb_join)
		return (0);
	if (!lem->start || !lem->end)
		return (0);
	return (1);
}

int		check_param(t_lem *lem, t_string *string)
{
	char	*line;
	int		ret;
	
	line = NULL;
	ret = 1;
	if (get_next_line(0, &line) <= 0 || !(lem->nb_ant = ft_getnbr(line)))
		return (0);
	ft_stringaddnl(string, line, 1);
	ft_strdel(&line);
	while (get_next_line(0, &line))
	{
		ft_stringaddnl(string, line, ft_strlen(line));
		if (ft_nb_of_word(line, '-') == 2)
			ret = check_connect(lem, line);
		else if (*line == '#')
			ret = get_sharp(lem, string, line);
		else if (!check_room(lem, line, 0))
			ret = 0;
		if (ret == 0)
			return (0);
		ft_strdel(&line);
	}
	ret = last_check(lem);
	return (ret);
}

int		main()
{
	t_lem	lem;
	t_string	string;

	ft_stringinit(&string);
	ft_bzero(&lem, sizeof(t_lem));
	if (check_param(&lem, &string) == 0)
		ft_error("error");
	ft_putstr(string.content);
	dprintf(1, "nb_room=%d, nb_ant=%d\n", lem.nb_room, lem.nb_ant);
	return (0);
}
