/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 18:18:27 by jsivanes          #+#    #+#             */
/*   Updated: 2015/11/02 18:18:36 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	j = i + 1;
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
					|| base[j] == '+' || base[j] == '-')
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	if (i <= 1)
		return (1);
	return (i);
}

int		stri_is_good(char value_str, char *base)
{
	int		u;
	int		y;

	u = 0;
	y = 0;
	while (base[u] != '\0')
	{
		if (base[u] == value_str)
			y++;
		u++;
	}
	if (y == 1)
		return (0);
	else
		return (1);
}

int		nb_de_la_base(char value_str, char *base)
{
	int		x;

	x = 0;
	while (base[x] != value_str)
		x++;
	return (x);
}

int		test_str(char *str, char *base)
{
	int		i;
	int		j;
	int		ok;

	ok = 0;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		ok = 0;
		while (base[j] != '\0' && ok == 0)
		{
			if (str[i] == base[j] || str[i] == '-' || str[i] == '+')
				ok++;
			j++;
		}
		if (ok == 0)
			return (1);
		i++;
		j = 0;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int		nb;
	int		i;
	int		sign;

	nb = 0;
	i = 0;
	sign = 1;
	if (ft_strlen_base(base) <= 1 || test_str(str, base) == 1)
		return (0);
	while ((str[i] == ' ') || (str[i] == '	'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (stri_is_good(str[i], base))
			return (nb * sign);
		nb = nb * ft_strlen_base(base) + (nb_de_la_base(str[i], base));
		i++;
	}
	return (nb * sign);
}
