/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:14:01 by jsivanes          #+#    #+#             */
/*   Updated: 2016/02/24 16:14:08 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	g_add;
int	g_option;
int	g_end;

int	main(int argc, char **argv)
{
	g_add = 0;
	if (!(ft_strcmp(argv[1], "-C")))
		g_option = 1;
	else
		g_option = 0;
	g_end = argc - 1 - g_option;
	hexdump(argv);
	return (0);
}
