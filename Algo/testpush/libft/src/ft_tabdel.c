/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:45:40 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/15 13:17:41 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_tabdel(void **todel)
{
	size_t		i;

	i = -1;
	if (todel)
	{
		while ((unsigned char *)todel[++i])
		{
			if (todel[i])
				free(todel[i]);
			todel[i] = NULL;
		}
		free(todel);
		todel = NULL;
	}
}
