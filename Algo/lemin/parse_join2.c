/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_join2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:57:19 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/16 18:22:09 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char		**check_line2(t_room *r1, t_room *r2, char *line, int j)
{
	if (r1 && r2)
	{
		line[j] = '+';
		return (ft_strsplit(line, '+'));
	}
	return (NULL);
}

char			**check_line(t_lem *lem, char *line, int len, int j)
{
	char	*str;
	int		i;
	t_room	*r1;
	t_room	*r2;

	i = -1;
	r1 = NULL;
	while (++i < len)
	{
		if (line[i] == '-' || i + 1 == len)
		{
			i = (i + 1 == len) ? len : i;
			str = ft_strsub(line, j, i - j);
			if (!r1 && (r1 = check_room_name(lem, str)))
				j = i + 1;
			else if (r1 && !(r2 = check_room_name(lem, str)) && i == len)
			{
				i = ft_strlen(r1->name);
				r1 = NULL;
				j = 0;
			}
			ft_strdel(&str);
		}
	}
	return (check_line2(r1, r2, line, j - 1));
}
