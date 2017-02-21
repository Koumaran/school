/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 13:34:49 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/28 14:50:41 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		bonus_lemin(t_lem *lem, t_string *string, int step)
{
	if (lem->bonus_way)
		add_way_bonus(string, lem);
	if (lem->step)
		ft_printf_string(string, "Number of step: %d\n", step);
	if (lem->fd)
	{
		ft_putstr_fd(string->content, lem->fd);
		close(lem->fd);
	}
}

static t_join	*last_check(t_lem *lem)
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

static t_join	*check_param(t_lem *lem, t_string *string, int ret)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) <= 0 || !check_number(line) ||
			((lem->nb_ant = ft_getnbr(line)) < 1))
		return (NULL);
	ft_stringaddnl(string, line, ft_strlen(line));
	ft_strdel(&line);
	while (get_next_line(0, &line))
	{
		ft_stringaddnl(string, line, ft_strlen(line));
		if (ft_nb_of_char(line, '-') >= 1 && ft_nb_of_word(line, ' ') < 2)
			ret = check_connect(lem, line);
		else if (*line == '#')
			ret = get_sharp(lem, string, &line);
		else if (!check_room(lem, line, 0))
			ret = 0;
		if (ft_strlen(line) == 0)
			break ;
		ft_strdel(&line);
		if (ret == 0)
			return (NULL);
	}
	ft_strdel(&line);
	return (last_check(lem));
}

static void		clear_lemin(t_lem *lem, t_string *string)
{
	clear_join(&lem->join);
	ft_stringdelete(string);
	clear_room(&lem->room);
	clear_way(&lem->way);
}

int				main(void)
{
	t_lem		lem;
	t_string	string;
	t_join		*start_join;
	int			step;

	step = 0;
	ft_stringinit(&string);
	ft_bzero(&lem, sizeof(t_lem));
	if ((start_join = check_param(&lem, &string, 1)) == NULL)
		ft_error("error");
	resolve_lem(&lem, start_join, NULL);
	check_way(&lem.way);
	if (!lem.way)
		ft_error("error");
	clear_join(&start_join);
	ft_stringaddc(&string, '\n');
	if (lem.map && !lem.step)
		add_map(&lem, &string);
	else
		send_ants(&lem, &string, &step);
	bonus_lemin(&lem, &string, step);
	ft_printf("\n%s\n", string.content);
	clear_lemin(&lem, &string);
	return (0);
}
