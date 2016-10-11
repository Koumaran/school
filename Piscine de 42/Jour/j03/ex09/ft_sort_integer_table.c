/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:46:40 by jsivanes          #+#    #+#             */
/*   Updated: 2015/10/24 15:16:40 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *tab, int size, int stop)
{
	int		a;

	while (stop < size)
	{
		if (tab[stop] > tab[stop + 1])
		{
			a = tab[stop];
			tab[stop] = tab[stop + 1];
			tab[stop + 1] = a;
		}
		stop++;
		ft_swap(tab, size, stop);
	}
}

void	ft_sort_integer_table(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size - 1)
	{
		ft_swap(tab, size, 0);
		i++;
	}
}
