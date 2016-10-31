/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 15:58:51 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/28 18:59:47 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			check_double(t_nb *a)
{
	t_nb	*tmp;
	t_nb	*tmp2;
	int		x;

	if (a == NULL)
		exit(1);
	x = a->nb;
	tmp = a->next;
	while (tmp != a)
	{
		tmp2 = tmp;
		while (tmp2 != a)
		{
			if (x == tmp2->nb)
				ft_error("\033[31mError");
			tmp2 = tmp2->next;
		}
		x = tmp->nb;
		tmp = tmp->next;
	}
}

int				check_good(t_nb *a)
{
	t_nb	*tmp;
	int		x;

	if (a == NULL)
		return (1);
	x = a->nb;
	tmp = a->next;
	while (tmp != a)
	{
		if (x > tmp->nb)
			return (0);
		x = tmp->nb;
		tmp = tmp->next;
	}
	return (1);
}

int				check_good_r(t_nb *a)
{
	t_nb	*tmp;
	int		x;

	if (a == NULL)
		return (1);
	x = a->nb;
	tmp = a->next;
	while (tmp != a)
	{
		if (x < tmp->nb)
			return (0);
		x = tmp->nb;
		tmp = tmp->next;
	}
	return (1);
}
