/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:03:54 by jsivanes          #+#    #+#             */
/*   Updated: 2016/04/19 17:54:34 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int		ft_posofx(char *map, int *pos_end)
{
	int		i;
	int		tmp;
	int		pos;

	i = -1;
	pos = 0;
	tmp = 42;
	while (map[++i])
	{
		if (map[i] >= 'A' && map[i] <= 'Z')
		{
			if (pos < tmp)
				tmp = pos;
			if (pos > *pos_end)
				*pos_end = pos;
		}
		pos++;
		if (map[i] == '\n')
			pos = 0;
	}
	return (tmp);
}

static char		*ft_push_left(char *map, int i, int pos, int pos_end)
{
	int		y;
	char	*tmp;
	int		n;

	y = 0;
	n = 0;
	tmp = ft_strnew(ft_strlen(map));
	while (n <= 3)
	{
		while (i + pos <= pos_end)
		{
			if (map[i + pos] >= 'A' && map[i + pos] <= 'Z')
				n++;
			tmp[y++] = map[i++ + pos];
		}
		while (map[i] != '\n' && map[i])
			i++;
		if (map[i] == '\n' && map[i])
			tmp[y++] = map[i++];
		pos_end += 5;
	}
	tmp[y - 1] = '\0';
	free(map);
	return (tmp);
}

static int		ft_check_tetris(char *map, char letter)
{
	int		touch;
	int		i;

	touch = 0;
	i = -1;
	while (map[++i])
	{
		if (map[i] == letter)
		{
			touch += (map[i - 5] == letter) ? 1 : 0;
			touch += (map[i - 1] == letter) ? 1 : 0;
			touch += (map[i + 1] == letter) ? 1 : 0;
			touch += (map[i + 5] == letter) ? 1 : 0;
		}
	}
	if (touch < 6)
		return (0);
	return (1);
}

static char		*get_word_map(char const *s, char letter)
{
	char	*tmp;
	int		n;

	if (!(tmp = ft_strnew(20)))
		return (NULL);
	n = -1;
	while (++n < 20)
	{
		tmp[n] = s[n];
		if (tmp[n] == '#')
			tmp[n] = letter;
	}
	return (tmp);
}

char			**init_map(char *s, int j, int cube)
{
	char	**map;
	int		n;
	char	letter;
	int		pos_end;

	letter = 'A';
	if (!(map = (char **)malloc(sizeof(char *) * cube + 1)))
		return (NULL);
	while (++j < cube)
	{
		map[j] = ft_push_top(get_word_map(s, letter), letter, 0, 0);
		if (!ft_check_tetris(map[j], letter++))
			return (NULL);
		pos_end = 0;
		map[j] = ft_push_left(map[j], 0, ft_posofx(map[j], &pos_end), pos_end);
		n = 0;
		while (n < 4 && *s)
			if (*s++ == '\n')
				n++;
		s++;
	}
	map[cube] = 0;
	return (map);
}
