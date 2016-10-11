/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:46:12 by jsivanes          #+#    #+#             */
/*   Updated: 2016/01/31 12:42:47 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list		*list;

	if (begin_list1 && *begin_list1 && begin_list2)
	{
		list = *begin_list1;
		while (list->next)
			list = list->next;
		list->next = begin_list2;
	}
	else if (begin_list1 && begin_list2)
		*begin_list1 = begin_list2;
}
