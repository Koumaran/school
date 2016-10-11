/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:30:47 by jsivanes          #+#    #+#             */
/*   Updated: 2016/01/19 12:03:01 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list		*this_list;
	t_list		*next_list;
	t_list		*last_list;

	this_list = *begin_list;
	last_list = NULL;
	while (this_list != NULL)
	{
		next_list = this_list->next;
		this_list->next = last_list;
		last_list = this_list;
		this_list = next_list;
	}
	*begin_list = last_list;
}
