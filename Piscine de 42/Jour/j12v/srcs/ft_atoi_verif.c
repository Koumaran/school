/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <maxpetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 12:25:09 by maxpetit          #+#    #+#             */
/*   Updated: 2016/02/24 15:32:37 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi_verif.h"

int				get_set_nbchar(int action, int input)
{
	static	int	nb_char = 0;
	static	int	status = 0;

	if (action == SET_STATUS)
		status = input;
	else if (action == SET_NUMBER)
		nb_char = input;
	else if (action == GET_STATUS)
		return (status);
	else if (action == GET_NUMBER)
		return (nb_char);
	return (0);
}

static	char	*init(char *str)
{
	int			i;

	i = 0;
	if (str[0] == '-' && str[1] >= '0' && str[1] <= '9')
	{
		get_set_nbchar(SET_STATUS, BEFOR_ENDING);
		i++;
	}
	else if (str[0] == '+' && str[1] >= '0' && str[1] <= '9')
	{
		get_set_nbchar(SET_STATUS, AFTER_BEGENING);
		i++;
	}
	else
	{
		get_set_nbchar(SET_STATUS, BEFOR_ENDING);
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		if (str[i] == '+')
			i++;
	}
	return (str + i);
}

void			verrif_number(int *oct_lu)
{
	int			nb_char;
	int			status;

	nb_char = get_set_nbchar(GET_NUMBER, 0);
	status = get_set_nbchar(GET_STATUS, 0);
	if (nb_char == 0 && status == AFTER_BEGENING)
	{
		get_set_nbchar(SET_NUMBER, SIZE_BUFF);
		*oct_lu = nb_char;
	}
}

void			ft_atoi_verif(char *str)
{
	int			i;
	int			nbr;

	i = 0;
	nbr = 0;
	str = init(str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	if (str[i] || i == 0)
		get_set_nbchar(SET_STATUS, WRONG_NUMBER);
	if (nbr < 0)
		nbr *= -1;
	get_set_nbchar(SET_NUMBER, nbr);
}
