/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 12:33:20 by atoulous          #+#    #+#             */
/*   Updated: 2016/03/06 17:12:03 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**g_map;
int		g_y;
int		g_x;

int		ft_create_map(void)
{
	int		y;

	y = 0;
	if (!(g_map = (char**)malloc(sizeof(char*) * (g_y + 2))))
		return (0);
	while (y < g_y + 1)
	{
		if (!(g_map[y] = (char*)malloc(sizeof(char) * (g_x + 1))))
			return (0);
		y++;
	}
	g_map[y] = 0;
	return (1);
}
