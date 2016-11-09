/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 11:42:07 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/03 21:21:50 by jsivanes         ###   ########.fr       */
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

int				main(int argc, char **argv)
{
	t_box	box;
	t_flag	flag;

	if (argc == 1)
	{
		ft_printf("Push Swap\nUse:\n\t./push_swap [-option] \"ARG\" or ARG\n");
		ft_printf("Option:\n\t-v: show operation step.\n\t-c: last string");
		ft_printf("in yellow.\n\t-r: reverse sort.\n\t-e: Show rigth error message\n");
		ft_printf("\t-p: Lunch checker at end.\n\t-w: show number of operation.\n");
		return (0);
	}
	ft_bzero(&box, sizeof(t_box));
	ft_bzero(&flag, sizeof(t_flag));
	parse_swap(&flag, ++argv, &box);
	push_swap(&box, &flag);
	if (flag.push_check)
	{
		if (flag.r)
		{
			if (!box.b && check_good_r(box.a))
				ft_putstr("\033[33mOK");
			else
				ft_error("\033[31mKO");
		}
		else
		{
			if (!box.b && check_good(box.a))
				ft_putstr("\033[33mOK");
			else
				ft_error("\033[31mKO");
		}
	}
	clear_box(&box, &flag);
	return (0);
}
