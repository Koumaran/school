/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:28:16 by jsivanes          #+#    #+#             */
/*   Updated: 2016/01/25 15:43:53 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

static void		ft_free(t_list *list)
{
	if (list->next != NULL)
		ft_free(list->next);
	free(list);
}

void			ft_list_clear(t_list **begin_list)
{
	if (begin_list && *begin_list)
	{
		ft_free(*begin_list);
		*begin_list = NULL;
	}
}
