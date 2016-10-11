/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 16:42:23 by jsivanes          #+#    #+#             */
/*   Updated: 2016/01/15 11:45:38 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		out;

	i = 0;
	out = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			out = 0;
		i++;
	}
	if (out == 0)
	{
		i = 0;
		out = 1;
		while (i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				out = 0;
			i++;
		}
	}
	return (out);
}
