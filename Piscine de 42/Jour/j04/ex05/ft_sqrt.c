/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 20:51:32 by jsivanes          #+#    #+#             */
/*   Updated: 2015/10/25 13:28:19 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		racine;

	racine = 0;
	while (racine * racine < nb)
		racine++;
	if (racine * racine == nb)
		return (racine);
	else
		return (0);
}
