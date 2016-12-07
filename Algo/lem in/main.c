/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 13:34:49 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/07 19:22:06 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_join		*last_check(t_lem *lem)
{
	t_join		*join;
	t_join		*start;
	int			end;

	join = lem->join;
	start = NULL;
	end = 0;
	if (lem->nb_room < 2 || !lem->nb_join)
		return (0);
	if (!lem->start || !lem->end)
		return (0);
	while (join)
	{
		if (join->r1 == lem->start || join->r2 == lem->start)
			ft_pushback_join(&start, new_join(join->r1, join->r2));
		if (join->r1 == lem->end || join->r2 == lem->end)
			end++;
		join = join->next;
	}
	if (start && end > 0)
		return (start);
	return (NULL);
}

t_join		*check_param(t_lem *lem, t_string *string)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 1;
	if (get_next_line(0, &line) <= 0 || !check_number(line) ||
			((lem->nb_ant = ft_getnbr(line)) < 1))
		return (NULL);
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
		if (ft_strlen(line) == 0)
			break ;
		ft_strdel(&line);
		if (ret == 0)
			return (NULL);
	}
	return (last_check(lem));
}

int		main(void)
{
	t_lem		lem;
	t_string	string;
	t_join		*start_join;
	t_list		*way;

	ft_stringinit(&string);
	ft_bzero(&lem, sizeof(t_lem));
	if ((start_join = check_param(&lem, &string)) == NULL)
		ft_error("error");
	if ((way = resolve_lem(&lem, start_join)) == NULL)
		ft_error("error");
	clear_join(&start_join);
	ft_putstr(string.content);
	ft_stringdelete(&string);
	dprintf(1, "nb_room=%d, nb_ant=%d\n", lem.nb_room, lem.nb_ant);
	return (0);
}
