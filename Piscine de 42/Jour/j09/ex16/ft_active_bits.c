/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 10:17:29 by jsivanes          #+#    #+#             */
/*   Updated: 2015/10/23 10:35:54 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	int		count;

	count = 0;
	while (value)
	{
		value = (value) & (value - 1);
		count++;
	}
	return (count);
}
