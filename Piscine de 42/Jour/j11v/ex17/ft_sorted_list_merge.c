/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:46:37 by jsivanes          #+#    #+#             */
/*   Updated: 2016/01/29 15:42:57 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "stdlib.h"

void	sort(t_list **list, int (*cmp)())
{
	int			swap;
	t_list			*tmp;
	void			*data_tmp;

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

void	ft_list_add(t_list **list, t_list *list2, int (*cmp)())
{
	t_list		*tmp;
	t_list		*tmp2;

	tmp = *list;
	tmp2 = list2->next;
	list2->next = tmp;
	tmp = list2;
	while (tmp2)
	{
		tmp2 = list2->next;
		while (tmp->next && (*cmp)(tmp->next->data, tmp2->data) > 0)
			tmp = tmp->next;
		list2 = tmp2;
		list2->next = tmp->next;
		tmp->next = list2;
	}

}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	*list;
	t_list	*list2;
	t_list	*tmp;
	int	changed;

	changed = 1;
	if (begin_list1 && *begin_list1 && begin_list2)
	{
		list = *begin_list1;
		list2 = begin_list2;
		sort(&list, cmp);
		sort(&list2, cmp);
		while (changed)
		{	
			changed = 0;
			if ((*cmp)(list->data, list2->data) > 0)
			{
				changed = 1;
				tmp = list2->next;
				list2->next = list;
				list = list2;
				list2 = tmp;
			}
			while (list->next && (*cmp)(list->next->data, list2->data) < 0)
				list = list->next;
			if (list->next && (*cmp)(list->next->data, list->data) > 0)
			{
				changed = 1;
				ft_list_add(	
			}
		}
	else if (begin_list1 && begin_list2)
	{
		sort(&begin_list2, cmp);	
		*begin_list1 = begin_list2;
	}
}

int		main(int ac, char **av)
{
	t_list		*list;
	t_list		*list2;
	t_list		*list3;
	t_list		*list4;
	t_list		*list5;
	int			(*cmp)();

	cmp = &ft_strcmp;
	if (ac > 1)
	{
		list = ft_list_push_params(ac, av);
		list2 = malloc(sizeof(t_list));
		list3 = malloc(sizeof(t_list));
		list4 = malloc(sizeof(t_list));
		list5 = malloc(sizeof(t_list));
		list3->next = NULL;
		list4->data = "gdsgsg";
		list2->data = "gfdg";
		list3->data = "00014";
		list5->data = "hzscs";
		list4->next = list3;
		list5->next = list4;
		list2->next = list5;
		ft_sorted_list_merge(&list, list2, cmp);
		ft_print(list);
	}
	return (0);
}
