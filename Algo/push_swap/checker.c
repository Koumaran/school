/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 18:47:38 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/03 21:27:51 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					main(int argc, char **argv)
{
	t_box		box;
	t_flag		flag;
	t_string	string;

	if (argc < 3)
	{
		ft_printf("Checker\nUse:\n\t./checker [option] \"1 2 3\" or 1 2 3\n");
		ft_printf("Option :\n\t-v: show operation step.\n\t-r: reverse sort.\n");
		ft_printf("\t-e: Show rigth error message.\n\t-a: Allow wrong operation\n");
		return (0);
	}
	ft_bzero(&box, sizeof(t_box));
	ft_bzero(&flag, sizeof(t_flag));
	parse_swap(&flag, ++argv, &box);
	if (operation(&box, &flag, &string))
	{
		clear_box(&box, &flag);
		ft_putstr("\033[32mOK\n\033[0m");
	}
	else if (flag.push_check == 1)
	{
		push_swap(&box, &flag);
		clear_box(&box, &flag);
	}
	else
		ft_error("\033[31mKO");
	return (0);
}
