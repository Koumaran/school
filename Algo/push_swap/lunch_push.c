/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:16:42 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/09 15:17:26 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		activate_swap(t_box *box, t_flag *flag, t_string *string)
{
	char	*tmp;

	get_extrem_box(box, box->a);
	tmp = NULL;
	if (flag->r == 1)
		(box->len < 10) ? swap_brute_r(box, flag, string) :
			swap_select_r(box, flag, string);
	else
		(box->len < 10) ? swap_brute(box, flag, string) :
			swap_select(box, flag, string);
	if (flag->v == 0)
	{
		tmp = print_join(ft_strsplit(string->content, '\n'), 0);
		ft_stringdelete(string);
		string->content = tmp;
		string->size = ft_strlen(tmp);
	}
}

void			push_swap(t_box *box, t_flag *flag)
{
	t_string	string;

	if (flag->r == 1 && check_good_r(box->a))
		exit(1);
	else if (!flag->r && check_good(box->a))
		exit(1);
	ft_stringinit(&string);
	activate_swap(box, flag, &string);
	if (flag->v)
		print_v(ft_strsplit(string.content, '='), flag->c, flag->w);
	else
		print_ps(ft_strsplit(string.content, '='), flag->c, flag->w);
	ft_stringdelete(&string);
}
