/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:21:23 by atoulous          #+#    #+#             */
/*   Updated: 2016/04/23 13:04:58 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**g_map;
char	g_carac[3];
int		g_y;
int		g_x;

void	ft_print(void)
{
	int		i;

	i = 0;
	while (g_map[i])
	{
		ft_putstr(g_map[i]);
		i++;
	}
	i = 0;
	while (g_map[i])
		free(g_map[i++]);
	free(g_map);
}

int		ft_read_first(int fd)
{
	int		y;
	char	*tmp;
	char	buf;

	g_x = 0;
	y = 0;
	tmp = "\0";
	while ((read(fd, &buf, 1)) && buf != '\n')
		tmp = ft_strcat(tmp, buf);
	while (tmp[y])
		y++;
	g_carac[2] = tmp[--y];
	g_carac[1] = tmp[--y];
	g_carac[0] = tmp[--y];
	tmp[y] = '\0';
	if ((g_y = ft_atoi(tmp)) == 0)
		return (0);
	free(tmp);
	return (1);
}

int		ft_check_map(int y)
{
	int		i;

	while (--y)
		if (g_map[y][g_x] != '\n')
			return (0);
	while (++y < g_y)
	{
		i = 0;
		while (i < g_x)
		{
			if ((g_map[y][i] != g_carac[0]) && (g_map[y][i] != g_carac[1]))
				return (0);
			i++;
		}
	}
	return (1);
}

int		ft_read_second(int fd)
{
	int		y;
	char	*tmp;
	char	buf;

	y = 0;
	tmp = "\0";
	while ((read(fd, &buf, 1)) && buf != '\n')
	{
		if ((buf != g_carac[0]) && (buf != g_carac[1]))
			return (0);
		tmp = ft_strcat(tmp, buf);
		g_x++;
	}
	tmp = ft_strcat(tmp, buf);
	if (!(ft_create_map()))
		return (0);
	g_map[y++] = tmp;
	while ((read(fd, g_map[y], g_x + 1)) && g_map[y])
		y++;
	if (y != g_y)
		return (0);
	return (ft_check_map(y));
}
