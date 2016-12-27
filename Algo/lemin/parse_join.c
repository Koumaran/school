/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:36:58 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/16 18:18:14 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room			*check_room_name(t_lem *lem, char *str)
{
	t_room		*tmp;

	tmp = lem->room;
	if (!str)
		return (NULL);
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_join			*new_join(t_room *r1, t_room *r2)
{
	t_join		*join;

	if (!(join = (t_join *)malloc(sizeof(t_join))))
		return (NULL);
	join->r1 = r1;
	join->r2 = r2;
	join->next = NULL;
	return (join);
}

void			ft_pushback_join(t_join **join_lst, t_join *new)
{
	t_join *tmp;

	if (join_lst && *join_lst)
	{
		tmp = *join_lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*join_lst = new;
}

static int		create_connection(t_lem *lem, t_room *r1, t_room *r2)
{
	t_join		*tmp;

	if (lem->join)
	{
		tmp = lem->join;
		if ((tmp->r1 == r1 && tmp->r2 == r2) ||\
				(tmp->r1 == r2 && tmp->r2 == r1))
			return (0);
		while (tmp->next)
		{
			tmp = tmp->next;
			if ((tmp->r1 == r1 && tmp->r2 == r2) ||\
					(tmp->r1 == r2 && tmp->r2 == r1))
				return (0);
		}
		tmp->next = new_join(r1, r2);
	}
	else
		lem->join = new_join(r1, r2);
	r1->nb_join++;
	r2->nb_join++;
	return (1);
}

int				check_connect(t_lem *lem, char *line)
{
	char		**split;
	t_room		*r1;
	t_room		*r2;

	if (lem->nb_room < 2)
		return (0);
	if (ft_nb_of_char(line, '-') >= 2)
	{
		if (!(split = check_line(lem, line, ft_strlen(line), 0)))
			return (0);
	}
	else if (!(split = ft_strsplit(line, '-')))
		return (0);
	if (ft_strcmp(split[0], split[1]) == 0)
		return (0);
	if (!(r1 = check_room_name(lem, split[0])) ||
			!(r2 = check_room_name(lem, split[1])))
		return (0);
	if (create_connection(lem, r1, r2))
		lem->nb_join += 1;
	ft_memfree_2d(split);
	return (1);
}
