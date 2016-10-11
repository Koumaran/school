/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:57:00 by jsivanes          #+#    #+#             */
/*   Updated: 2016/01/31 12:52:09 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list		*tmp;
	int			i;
	void		*x;

	i = 1;
	while (i)
	{
		tmp = *begin_list;
		i = 0;
		while (tmp->next)
		{
			if ((*cmp)(tmp->data, tmp->next->data) > 0)
			{
				i = 1;
				x = tmp->next->data;
				tmp->next->data = tmp->data;
				tmp->data = x;
			}
			tmp = tmp->next;
		}
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list		*list;
	t_list		*tmp;

	list = ft_create_elem(data);
	tmp = *begin_list;
	if (begin_list && *begin_list)
	{
		ft_list_sort(&tmp, cmp);
		if ((*cmp)(tmp->data, data) > 0)
		{
			list->next = tmp;
			*begin_list = list;
		}
		else
		{
			while ((*cmp)(tmp->next->data, data) < 0 && tmp->next)
				tmp = tmp->next;
			list->next = tmp->next;
			tmp->next = list;
		}
	}
}
