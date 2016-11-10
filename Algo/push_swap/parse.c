/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 19:21:36 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/09 16:09:45 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		get_extrem_box(t_box *box, t_nb *pile)
{
	box->max = ft_big_elem(pile);
	box->min = ft_small_elem(pile);
	box->len = get_len(pile, &box->midl);
}

t_flag		*add_flag_sw(char *str, t_flag *flag)
{
	t_flag		*tmp;

	tmp = flag;
	if (CHR(str, 'v') != NULL)
		tmp->v = 1;
	if (CHR(str, 'c') != NULL)
		tmp->c = 1;
	if (CHR(str, 'r') != NULL)
		tmp->r = 1;
	if (CHR(str, 'e') != NULL)
		tmp->e = 1;
	if (CHR(str, 'a') != NULL)
		tmp->a = 1;
	if (CHR(str, 'p') != NULL)
		tmp->push_check = 1;
	if (CHR(str, 'w') != NULL)
		tmp->w = 1;
	return (tmp);
}

int			check_if_num(char *str, t_flag *flag)
{
	int		i;

	i = (*str == '-') ? 1 : 0;
	if (ft_isdigit(str[i]))
	{
		while (str[i])
			if (!ft_isdigit(str[i++]))
				error_p("Only digit number are allowed", str, flag);
		return (1);
	}
	else if (i == 0 && ft_isalpha(str[i]))
		error_p("Only digit number are allowed", str, flag);
	else if (ft_isalpha(str[i]))
	{
		while (str[i])
		{
			if (!ft_isalpha(str[i]))
				error_p("Option can't have only alpha", str, flag);
			if (CHR("vcreapw", str[i++]) == NULL)
				error_p("A wrong option detected", str, flag);
		}
	}
	return (0);
}

int			parse_swap(t_flag *flag, char **av, t_box *box, int len)
{
	t_long		nb;
	int			i;
	char		**tab;

	while (*av)
	{
		tab = ft_strsplit(*av++, ' ');
		i = -1;
		while (tab[++i])
		{
			if (tab[i][0] == '-' && check_if_num(tab[i], flag) == 0)
				flag = add_flag_sw(tab[i], flag);
			else if (check_if_num(tab[i], flag))
			{
				nb = ft_atoi(tab[i]);
				if (nb < -2147483648 || nb > 2147483647)
					error_p("The number is not an Int", tab[i], flag);
				ft_list_push_back(&box->a, nb);
				len++;
			}
		}
		ft_memfree_2d(tab);
	}
	check_double(box->a, flag);
	return (len);
}
