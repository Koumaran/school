/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 18:47:38 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/09 16:04:39 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int			show_helper(void)
{
	ft_printf("Checker\nUse:\n\t./checker [option] \"1 2 3\" or 1 2 3\n");
	ft_printf("Option :\n\t-v: show operation step.\n\t-r: reverse sort.");
	ft_printf("\n\t-e: Show rigth error message.\n\t-a: Allow wrong ");
	ft_printf("operation\n\t-p: Finish the swap if not in order\n");
	return (0);
}

int					main(int argc, char **argv)
{
	t_box		box;
	t_flag		flag;
	t_string	string;

	if (argc == 1)
		return (show_helper());
	ft_bzero(&box, sizeof(t_box));
	ft_bzero(&flag, sizeof(t_flag));
	if (parse_swap(&flag, ++argv, &box, 0) < 2)
		exit(1);
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
