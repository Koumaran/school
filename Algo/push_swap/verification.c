/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 15:58:51 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/03 21:32:44 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_double(t_nb *a, t_flag *flag)
{
	t_nb	*tmp;
	t_nb	*tmp2;
	int		x;

	if (a == NULL)
		exit(1);
	x = a->nb;
	tmp = a->next;
	while (tmp != a)
	{
		tmp2 = tmp;
		while (tmp2 != a)
		{
			if (x == tmp2->nb)
				error_p("Found duplicate number", ft_itoa(x), flag);
			tmp2 = tmp2->next;
		}
		x = tmp->nb;
		tmp = tmp->next;
	}
}

int		check_good(t_nb *a)
{
	t_nb	*tmp;
	int		x;

	if (a == NULL)
		return (1);
	x = a->nb;
	tmp = a->next;
	while (tmp != a)
	{
		if (x > tmp->nb)
			return (0);
		x = tmp->nb;
		tmp = tmp->next;
	}
	return (1);
}

int		check_good_r(t_nb *a)
{
	t_nb	*tmp;
	int		x;

	if (a == NULL)
		return (1);
	x = a->nb;
	tmp = a->next;
	while (tmp != a)
	{
		if (x < tmp->nb)
			return (0);
		x = tmp->nb;
		tmp = tmp->next;
	}
	return (1);
}

void	clear_box(t_box *box, t_flag *flag)
{
	t_nb	*tmp;
	t_nb	*tmp2;

	ft_bzero(flag, sizeof(t_flag));
	tmp = box->a->next;
	while (tmp != box->a)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	free(tmp);
	ft_bzero(box, sizeof(t_box));
}

void	error_p(char *error_message, char *arg, t_flag *flag)
{
	if (flag->e == 1)
		ft_printf("{red}%s : %s\n", arg, error_message);
	else
		ft_printf("\033[31mError\n");
	exit(1);
}
