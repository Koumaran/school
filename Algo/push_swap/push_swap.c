/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 11:42:07 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/09 16:03:05 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		add_checker(t_box *box, int rev)
{
	if (rev)
	{
		if (!box->b && check_good_r(box->a))
			ft_putendl("\033[32mOK");
		else
			ft_error("\033[31mKO");
	}
	else
	{
		if (!box->b && check_good(box->a))
			ft_putendl("\033[32mOK");
		else
			ft_error("\033[31mKO");
	}
}

int				main(int argc, char **argv)
{
	t_box	box;
	t_flag	flag;

	if (argc == 1)
	{
		ft_printf("Push Swap\nUse:\n\t./push_swap [-option] \"ARG\" or ARG\n");
		ft_printf("Option:\n\t-v: show operation step.\n\t-c: last string");
		ft_printf("in yellow.\n\t-r: reverse sort.\n\t-e: show rigth error ");
		ft_printf("message\n\t-p: check if in order.\n");
		ft_printf("\t-w: show number of operation.\n");
		return (0);
	}
	ft_bzero(&box, sizeof(t_box));
	ft_bzero(&flag, sizeof(t_flag));
	if (parse_swap(&flag, ++argv, &box, 0) < 2)
		exit(1);
	push_swap(&box, &flag);
	if (flag.push_check)
		add_checker(&box, flag.r);
	clear_box(&box, &flag);
	return (0);
}
