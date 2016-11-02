/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 18:55:34 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/28 18:53:48 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		sa(t_box *box, t_flag *flag, t_string *string)
{
	t_nb	*tmp_a;
	int		x;

	tmp_a = box->a;
	if (tmp_a && tmp_a->next != tmp_a)
	{
		ft_stringaddnl(string, "=sa", 3);
		x = tmp_a->nb;
		tmp_a->nb = tmp_a->next->nb;
		tmp_a->next->nb = x;
		if (flag && flag->v)
			print_option_sw(box->a, box->b, string);
	}
}

void		sb(t_box *box, t_flag *flag, t_string *string)
{
	t_nb	*tmp_b;
	int		x;

	tmp_b = box->b;
	if (tmp_b && tmp_b->next != tmp_b)
	{
		ft_stringaddnl(string, "=sb", 3);
		x = tmp_b->nb;
		tmp_b->nb = tmp_b->next->nb;
		tmp_b->next->nb = x;
		if (flag && flag->v)
			print_option_sw(box->a, box->b, string);
	}
}

void		ss(t_box *box, t_flag *flag, t_string *string)
{
	sa(box, flag, string);
	sb(box, flag, string);
}
