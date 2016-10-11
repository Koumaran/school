/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 17:13:02 by jsivanes          #+#    #+#             */
/*   Updated: 2015/11/05 12:06:09 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_words_tables(char **tab)
{
	int		i;
	int		v;

	i = 0;
	while (tab[i])
	{
		v = 0;
		while (tab[i][v])
		{
			ft_putchar(tab[i][v]);
			v++;
		}
		ft_putchar('\n');
		i++;
	}
}
