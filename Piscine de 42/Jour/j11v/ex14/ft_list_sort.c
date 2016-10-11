/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:47:00 by jsivanes          #+#    #+#             */
/*   Updated: 2016/01/30 01:05:33 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list		*tmp;
	void		*safe;
	int			i;

	i = 1;
	if (begin_list && *begin_list)
	{
		while (i)
		{
			tmp = *begin_list;
			i = 0;
			while (tmp->next)
			{
				if ((*cmp)(tmp->data, tmp->next->data) > 0)
				{
					i = 1;
					safe = tmp->data;
					tmp->data = tmp->next->data;
					tmp->next->data = safe;
				}
				tmp = tmp->next;
			}
		}
	}
}
