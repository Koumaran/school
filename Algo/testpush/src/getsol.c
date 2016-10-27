/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getsol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 16:56:56 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/29 17:19:41 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_getsol(t_solv *solv, char *to_write)
{
	char *tmp;

	if (solv->opt & FT_SBS)
	{
		tmp = ft_strnew(10);
		solv->color = 0;
		ft_get_ope(solv, to_write);
		ft_printf("%[c,B]T%s :\n%[0]T", to_write);
		ft_print_pa(solv);
		ft_print_pb(solv);
		if (solv->opt & FT_WAIT)
			read(0, tmp, 10);
		if (ft_strnequ(tmp, "exit", 4) == 1)
			ft_end_ps(solv);
	}
	if (!solv->solution)
		solv->solution = ft_strdup(to_write);
	else
	{
		solv->solution = ft_strjoin_n_free(solv->solution, " ");
		solv->solution = ft_strjoin_n_free(solv->solution, to_write);
	}
}
