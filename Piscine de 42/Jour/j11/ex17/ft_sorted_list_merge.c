/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:46:37 by jsivanes          #+#    #+#             */
/*   Updated: 2016/02/04 15:31:03 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "stdlib.h"

void	sort(t_list **list, int (*cmp)())
{
	int			swap;
	t_list		*tmp;
	void		*data_tmp;

	swap = 1;
	if (list && *list)
	{
		while (swap)
		{
			swap = 0;
			tmp = *list;
			while (tmp->next)
			{
				if (cmp(tmp->data, tmp->next->data) > 0)
				{
					data_tmp = tmp->data;
					tmp->data = tmp->next->data;
					tmp->next->data = data_tmp;
					swap = 1;
				}
				tmp = tmp->next;
			}
		}
	}
}

void	ft_list_add(t_list **begin_list, t_list *begin_list2, int (*cmp)())
{
	t_list		*list;
	t_list		*tmp;
	t_list		*tmp2;

	list = *begin_list;
	while (list->next && begin_list2)
	{
		while (list->next && (*cmp)(list->next->data, begin_list2->data) < 0)
			list = list->next;
		if (list->next && (*cmp)(list->next->data, begin_list2->data) > 0)
		{
			tmp = list->next;
			tmp2 = begin_list2->next;
			list->next = begin_list2;
			list->next->next = tmp;
			begin_list2 = tmp2;
		}
	}
	if (list->next == NULL && begin_list2)
		list->next = begin_list2;
}

void	ft_sorted_list_merge(t_list **begin_list1,\
		t_list *begin_list2, int (*cmp)())
{
	t_list		*list;
	t_list		*tmp;

	if (begin_list1 && *begin_list1 && begin_list2)
	{
		list = *begin_list1;
		sort(&list, cmp);
		sort(&begin_list2, cmp);
		if ((*cmp)(list->data, begin_list2->data) > 0)
		{
			tmp = begin_list2->next;
			begin_list2->next = list;
			list = begin_list2;
			begin_list2 = tmp;
		}
		ft_list_add(&list, begin_list2, cmp);
	}
	else if (begin_list1 && begin_list2)
	{
		sort(&begin_list2, cmp);
		*begin_list1 = begin_list2;
	}
}

int		main(int ac, char **av)
{
	t_list	*list;

}
