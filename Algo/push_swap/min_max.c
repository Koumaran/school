/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 16:49:30 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/03 21:29:59 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		get_position(t_nb *pile, int nb)
{
	t_nb	*tmp;
	int		pos;

	tmp = pile;
	pos = 1;
	while (tmp->nb != nb)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int		ft_big_elem(t_nb *pile)
{
	int		x;
	t_nb	*tmp;

	x = pile->nb;
	tmp = pile->next;
	while (tmp != pile)
	{
		if (x < tmp->nb)
			x = tmp->nb;
		tmp = tmp->next;
	}
	return (x);
}

int		ft_small_elem(t_nb *pile)
{
	int		x;
	t_nb	*tmp;

	x = pile->nb;
	tmp = pile->next;
	while (tmp != pile)
	{
		if (x > tmp->nb)
			x = tmp->nb;
		tmp = tmp->next;
	}
	return (x);
}

int		get_len(t_nb *a, int *midl)
{
	int		len;
	t_nb	*tmp;

	if (a == NULL)
		return (0);
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
