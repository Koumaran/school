/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:50:12 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/08 15:41:37 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	**ft_create_tet(int cube)
{
	char	**tet;
	int		i;
	int		j;

	if (!(tet = (char**)malloc(sizeof(char*) * cube + 1)))
		return (NULL);
	i = -1;
	while (++i < cube)
	{
		tet[i] = ft_strnew(cube + 1);
		j = -1;
		while (++j < cube)
			tet[i][j] = '.';
		tet[i][cube] = '\n';
	}
	tet[cube] = 0;
	return (tet);
}
