/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:12:35 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/28 18:28:02 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_nb		*ft_create_elem(int nbr)
{
	t_nb	*a;

	a = ft_memalloc(sizeof(t_nb));
	if (a)
	{
		a->nb = nbr;
		a->next = a;
		a->previus = a;
	}
	return (a);
}

void		ft_list_push_back(t_nb **list, int nbr)
{
	t_nb	*tmp;

	tmp = *list;
	if (*list)
	{
		while (tmp->next != *list)
			tmp = tmp->next;
		tmp->next = ft_create_elem(nbr);
		tmp->next->previus = tmp;
		tmp->next->next = *list;
		(*list)->previus = tmp->next;
	}
	else
		*list = ft_create_elem(nbr);
}
