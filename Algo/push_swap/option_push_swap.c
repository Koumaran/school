/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 19:02:03 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/17 15:00:08 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	char	*print_t_nb(t_nb *a, char *s)
{
	char		*str;
	t_nb		*tmp;

	str = ft_itoa(a->nb);
	s = ft_strjoin_safe(s, str);
	s = ft_putchar_str(s, ' ');
	tmp = a->next;
	while (tmp && tmp != a)
	{
		str = ft_putchar_str(ft_itoa(tmp->nb), ' ');
		s = ft_strjoin_safe(s, str);
		tmp = tmp->next;
	}
	return (s);
}

void			print_option_sw(t_nb *a, t_nb *b, char **str)
{
	char	*s;

	s = ft_strjoin_safe(*str, DP("a : "));
	if (a)
		s = print_t_nb(a, s);
	s = ft_strjoin_safe(s, DP("\nb : "));
	if (b)
		s = print_t_nb(b, s);
	*str = ft_putchar_str(s, '\n');
}
