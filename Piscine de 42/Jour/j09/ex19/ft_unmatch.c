/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 12:12:05 by jsivanes          #+#    #+#             */
/*   Updated: 2015/10/23 13:18:42 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int length)
{
	int		num;
	int		i;
	int		i2;
	int		count;
	int		valeur;

	i = 0;
	while (i < length)
	{
		num = tab[i];
		i2 = 0;
		count = 0;
		while (i2 < length)
		{
			if (num == tab[i2])
				count += 1;
			i2++;
		}
		if (count & 1)
			valeur = num;
		i++;
	}
	return (valeur);
}
