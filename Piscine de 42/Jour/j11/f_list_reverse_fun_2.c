/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_list_reverse_fun_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:23:57 by jsivanes          #+#    #+#             */
/*   Updated: 2016/02/04 14:42:27 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_last(t_list *begin_list)
{
	if (begin_list->next)
		return (ft_list_last(begin_list->next));
	else
		return (begin_list);
}

void	ft_reverse_next(t_list *begin_list, t_list *end)
{
	t_list	*node;

	while (end != begin_list)
	{
		node = begin_list;
		while (node->next != end && node->next)
			node = node->next;
		end->next = node;
		end = node;
	}
	end->next = NULL;
}

void	ft_list_reverse_fun(t_list	*begin_list)
{
	t_list	*last;
	t_list	swap;
	t_list	node;

	if (begin_list)
		if (begin_list->next)
		{
			last = ft_list_last(begin_list);
			ft_reverse_next(begin_list, last);
			node = last;
			while (node->next->next)
				node = node->next;
			node->next = last;
			swap = *begin_list;
			*begin_list = *last;
			*last = swap;
		}
}
