/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_brute_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 14:45:35 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/28 18:54:51 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_box		*before_tri(t_box *box, t_flag *flag, t_string *string)
{
	if (box->a->nb == box->max)
		ra(box, flag, string);
	else if (box->a->previus->nb == box->min)
		rra(box, flag, string);
	return (box);
}

t_box		*before_tri_r(t_box *box, t_flag *flag, t_string *string)
{
	if (box->a->nb == box->min)
		ra(box, flag, string);
	else if (box->a->previus->nb == box->max)
		rra(box, flag, string);
	return (box);
}
