/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 15:41:19 by jsivanes          #+#    #+#             */
/*   Updated: 2015/10/28 10:55:58 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check(int queen[], int col)
{
	int		i;

	i = 0;
	while (++i <= col)
	{
		if (queen[col - i] == queen[col])
			return (0);
		if (queen[col - i] == queen[col] + i)
			return (0);
		if (queen[col - i] == queen[col] - i)
			return (0);
	}
	return (1);
}

int		ft_puzzle(int queen[], int col)
{
	int		r;

	r = 0;
	queen[col] = 0;
	while (queen[col] <= 7)
	{
		if (ft_check(queen, col))
		{
			if (col == 7)
				r++;
			else
				r += ft_puzzle(queen, col + 1);
		}
		queen[col]++;
	}
	return (r);
}

int		ft_eight_queens_puzzle(void)
{
	int		queen[8];

	return (ft_puzzle(queen, 0));
}
