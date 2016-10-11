/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 14:10:33 by jsivanes          #+#    #+#             */
/*   Updated: 2015/10/29 18:26:38 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_skip(char *str)
{
	int		end;
	int		i;
	int		skip;

	end = 0;
	skip = 0;
	i = 0;
	while (str[end] != '\0')
		end++;
	while (i < end)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == ' ')
		{
			skip++;
			if (str[i] == '+' || str[i] == '-')
				i = end;
			i++;
		}
		else
			i = end;
	}
	return (skip);
}

int		ft_atoi(char *str)
{
	int		i;
	int		nb;
	int		sign;

	nb = 0;
	sign = 0;
	i = ft_skip(str);
	if (str[i - 1] == '-')
		sign = -1;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (sign == -1)
		nb *= sign;
	return (nb);
}
