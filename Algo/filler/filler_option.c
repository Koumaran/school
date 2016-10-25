/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 17:52:59 by jsivanes          #+#    #+#             */
/*   Updated: 2016/09/20 14:56:32 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	opt_s(t_opt *opt, int y, int x)
{
	ft_putnbr_fd(y, opt->fd);
	ft_putchar_fd(' ', opt->fd);
	ft_putnbr_fd(x, opt->fd);
	ft_putchar_fd('\n', opt->fd);
}

void	get_optionfil(t_opt *opt, char *str)
{
	if (*str == 's')
	{
		opt->s = 1;
		if ((opt->fd = open("myfiller.trace", O_CREAT | O_WRONLY)) < 0)
			opt->fd = open("myfiller.trace", O_TRUNC | O_WRONLY);
	}
}
