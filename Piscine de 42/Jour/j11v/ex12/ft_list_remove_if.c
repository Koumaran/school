/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:44:20 by jsivanes          #+#    #+#             */
/*   Updated: 2016/01/30 14:04:10 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "stdlib.h"

void	ft_delete_if(t_list **rabbit, void *data_ref, int (*cmp)())
{
	t_list	*turtle;

	while (*rabbit)
	{
		if ((*cmp)((*rabbit)->data, data_ref) == 0)
		{
			*rabbit = (*rabbit)->next;
			free(turtle->next);
			turtle->next = *rabbit;
		}
		else
		{
			turtle = *rabbit;
			*rabbit = (*rabbit)->next;
		}
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*rabbit;

	if (begin_list && *begin_list)
	{
		while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
		{
			rabbit = *begin_list;
			(*begin_list) = (*begin_list)->next;
			free(rabbit);
		}
		rabbit = *begin_list;
		ft_delete_if(&rabbit, data_ref, cmp);
	}
}
