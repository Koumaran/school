/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 11:42:07 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/23 17:46:42 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char		*activate_swap(t_box *box, t_flag *flag)
{
	char	*tmp;

	box = init_box(box, box->a);
	tmp = NULL;
	if (flag->r == 1)
		box->str = (box->len < 10) ? swap_brute_r(box, flag) :
			swap_selection_r(box, flag);
	else
		box->str = (box->len < 10) ? swap_brute(box, flag) :
			swap_selection(box, flag);
	if (flag->v == 0)
	{
		tmp = print_join(ft_strsplit(box->str, '\n'), 0);
		ft_strdel(&box->str);
		box->str = tmp;
	}
	return (box->str);
}

static void		push_swap(t_box *box, t_flag *flag)
{
	char	*str;

	if (flag->r == 1 && check_good_r(box->a))
		exit(1);
	else if (!flag->r && check_good(box->a))
		exit(1);
	str = activate_swap(box, flag);
	if (flag->v)
		print_v(ft_strsplit(str, '='), flag->c);
	else
		print_ps(ft_strsplit(str, '='), flag->c);
	ft_strdel(&str);
}

static void		clear_box(t_box *box, t_flag *flag)
{
	t_nb	*tmp;
	t_nb	*tmp2;

	ft_bzero(flag, sizeof(t_flag));
	tmp = box->a->next;
	while (tmp != box->a)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	free(tmp);
	ft_bzero(box, sizeof(t_box));
}

int				main(int argc, char **argv)
{
	t_box	box;
	t_flag	flag;

	if (argc == 1)
		return (1);
	ft_bzero(&box, sizeof(t_box));
	ft_bzero(&flag, sizeof(t_flag));
	box = parse_swap(&flag, ++argv, &box, 0);
	if (flag.h == 1)
	{
		ft_printf("Push Swap\nUse:\n\t./push_swap [-option] \"ARG\" or ARG\n");
		ft_printf("Option:\n\t-v: show operation step.\n\t-c: last string");
		ft_printf("in yellow.\n\t-r: reverse sort.\n\t-h: show help.\n");
	}
	check_double(box.a);
	push_swap(&box, &flag);
	clear_box(&box, &flag);
	return (0);
}
