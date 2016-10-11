/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:53:19 by jsivanes          #+#    #+#             */
/*   Updated: 2016/01/30 01:10:48 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list		*ft_list_at(t_list *begin_list, int nbr)
{
	t_list		*list;
	int			i;

	list = begin_list;
	i = 0;
	while (list && i < nbr)
	{
		list = list->next;
		i++;
	}
	if (i == nbr)
		return (list);
	else
		return (NULL);
}

int			ft_list_size(t_list *begin_list)
{
	t_list		*list;
	int			i;

	list = begin_list;
	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void		ft_list_swap(t_list **list1, t_list **list2)
{
	void		*save;

	save = (*list1)->data;
	(*list1)->data = (*list2)->data;
	(*list2)->data = save;
}

void		ft_list_reverse_fun(t_list *begin_list)
{
	t_list		*tmp1;
	t_list		*tmp2;
	int			i;
	int			j;
	int			size;

	size = ft_list_size(begin_list);
	i = 0;
	j = size - 1;
	while (i != j & i < size / 2)
	{
		tmp1 = ft_list_at(begin_list, i);
		tmp2 = ft_list_at(begin_list, j);
		ft_list_swap(&tmp1, &tmp2);
		i++;
		j--;
	}
}
