/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 13:34:49 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/11 15:21:54 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_connect(t_lem *lem, t_string *str, char *line)
{
	char	**split;

	dprintf(1, "connect\n");
	if (ft_nb_of_word(line, '-') != 2 || !(split = ft_strsplit(line, '-')))
		return (0);
	if (!check_room_name(lem, split[0]) || !check_room_name(lem, split[1]))
		return (0);
	add_connection(split[0], split[1]);
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
		if (ft_strchr(line, '-') && *line != '-')
			ret = check_connect(lem, string, line);
		else if (*line == '#')
			ret = get_sharp(lem, string, line);
		else
			ret = check_room(lem, line);
		if (ret == 0)
			return (0);
		ft_strdel(&line);
	}
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
//	resolve_lemin(&lem);
	return (0);
}
