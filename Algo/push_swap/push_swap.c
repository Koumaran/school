/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 11:42:07 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/28 19:37:51 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		activate_swap(t_box *box, t_flag *flag, t_string *string)
{
	char	*tmp;
	char	**split;

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
		tmp = print_join((split = ft_strsplit(string->content, '\n')), 0);
		ft_stringdelete(string);
		string->content = tmp;
		string->size = ft_strlen(tmp);
		ft_memfree_2d(split);
	}
}

static void		push_swap(t_box *box, t_flag *flag)
{
	t_string	string;
	char		**split;

	if (flag->r == 1 && check_good_r(box->a))
		exit(1);
	else if (!flag->r && check_good(box->a))
		exit(1);
	ft_stringinit(&string);
	activate_swap(box, flag, &string);
	split = ft_strsplit(string.content, '=');
	if (flag->v)
		print_v(split, flag->c);
	else
		print_ps(split, flag->c);
	ft_stringdelete(&string);
	ft_memfree_2d(split);
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
	{
		ft_printf("Push Swap\nUse:\n\t./push_swap [-option] \"ARG\" or ARG\n");
		ft_printf("Option:\n\t-v: show operation step.\n\t-c: last string");
		ft_printf("in yellow.\n\t-r: reverse sort.\n");
		return (0);
	}
	ft_bzero(&box, sizeof(t_box));
	ft_bzero(&flag, sizeof(t_flag));
	box = parse_swap(&flag, ++argv, &box);
	check_double(box.a);
	push_swap(&box, &flag);
	clear_box(&box, &flag);
	return (0);
}
