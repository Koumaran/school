/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:29:13 by jsivanes          #+#    #+#             */
/*   Updated: 2016/01/30 13:11:46 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*list;

	i = 0;
	list = begin_list;
	if (list)
	{
		while (list)
		{
			if (i == nbr)
				return (list);
			else
				list = list->next;
			i++;
		}
	}
	return (NULL);
}
