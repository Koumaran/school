/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 19:02:03 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/03 20:28:37 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	void	print_t_nb(t_nb *a, t_string *string)
{
	char		*str;
	t_nb		*tmp;

	str = ft_itoa(a->nb);
	ft_stringadd(string, str, ft_strlen(str));
	ft_stringaddc(string, ' ');
	ft_strdel(&str);
	tmp = a->next;
	while (tmp && tmp != a)
	{
		str = ft_putchar_str(ft_itoa(tmp->nb), ' ');
		ft_stringadd(string, str, ft_strlen(str));
		ft_strdel(&str);
		tmp = tmp->next;
	}
}

void			print_option_sw(t_nb *a, t_nb *b, t_string *string)
{
	ft_stringadd(string, "a : ", 4);
	if (a)
		print_t_nb(a, string);
	ft_stringadd(string, "\nb : ", 5);
	if (b)
		print_t_nb(b, string);
	ft_stringaddc(string, '\n');
}
