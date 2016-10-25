/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_brute_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 14:45:35 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/23 17:50:09 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_box		*before_tri(t_box *box, char **str, t_flag *flag)
{
	if (box->a->nb == box->max)
		ra(&box->a, &box->b, flag, str);
	else if (box->a->previus->nb == box->min)
		rra(&box->a, &box->b, flag, str);
	return (box);
}

t_box		*before_tri_r(t_box *box, char **str, t_flag *flag)
{
	if (box->a->nb == box->min)
		ra(&box->a, &box->b, flag, str);
	else if (box->a->previus->nb == box->max)
		rra(&box->a, &box->b, flag, str);
	return (box);
}
