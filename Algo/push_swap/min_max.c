/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 16:49:30 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/21 14:53:38 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_max(t_nb *tab)
{
	int		x;
	t_nb	*tmp;

	x = tab->nb;
	tmp = tab->next;
	while (tmp != tab)
	{
		if (x < tmp->nb)
			x = tmp->nb;
		tmp = tmp->next;
	}
	return (x);
}

int			ft_min2(t_nb *tab, int min)
{
	int		x;
	t_nb	*tmp;

	x = tab->nb;
	tmp = tab->next;
	while (tmp != tab)
	{
		if (tmp->nb != min && x > tmp->nb)
			x = tmp->nb;
		tmp = tmp->next;
	}
	return (x);
}

int			ft_min(t_nb *tab)
{
	int		x;
	t_nb	*tmp;

	x = tab->nb;
	tmp = tab->next;
	while (tmp != tab)
	{
		if (x > tmp->nb)
			x = tmp->nb;
		tmp = tmp->next;
	}
	return (x);
}

int			get_len(t_nb *a, int *midl)
{
	int		len;
	t_nb	*tmp;

	len = 1;
	tmp = a->next;
	while (tmp != a)
	{
		len++;
		tmp = tmp->next;
	}
	*midl = (len / 2) + (len % 2);
	return (len);
}

t_box		*init_box(t_box *box, t_nb *a)
{
	box->max = ft_max(a);
	box->min = ft_min(a);
	box->len = get_len(a, &box->midl);
	return (box);
}
