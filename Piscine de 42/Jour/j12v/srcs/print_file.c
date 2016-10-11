/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <maxpetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 12:25:09 by maxpetit          #+#    #+#             */
/*   Updated: 2016/02/03 12:12:16 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_file.h"

static	int		init_var(t_ucc **buff1, t_ucc **buff2)
{
	int	i;
	int	nb_char;

	i = 0;
	nb_char = get_set_nbchar(GET_NUMBER, 0);
	if (get_set_nbchar(GET_STATUS, 0) == AFTER_BEGENING)
		nb_char = SIZE_BUFF;
	*buff1 = (t_ucc*)malloc(sizeof(t_ucc) * nb_char);
	*buff2 = (t_ucc*)malloc(sizeof(t_ucc) * nb_char);
	if (!buff1 || !buff2)
		return (0);
	while (i < nb_char)
	{
		buff2[0][i] = '\0';
		i++;
	}
	return (1);
}

static	void	ft_end(t_ucc *buff_actif, t_ucc *buff_temp
		, int o_lu, int nb_tour)
{
	if (get_set_nbchar(GET_STATUS, 0) == BEFOR_ENDING)
	{
		if (nb_tour > 1)
			ft_putstr(buff_temp + o_lu, get_set_nbchar(GET_NUMBER, 0) - o_lu);
		ft_putstr(buff_actif, o_lu);
	}
	free(buff_actif);
	free(buff_temp);
}

static	void	init_ok_nb_char(int *ok, int *nb_char)
{
	*ok = 1;
	*nb_char = get_set_nbchar(GET_NUMBER, 0);
	if (get_set_nbchar(GET_NUMBER, 0) == 0)
	{
		if (get_set_nbchar(GET_STATUS, 0) == BEFOR_ENDING)
			*ok = 0;
		if (get_set_nbchar(GET_STATUS, 0) == AFTER_BEGENING)
			*nb_char = SIZE_BUFF;
	}
}

static	void	ft_print_file_the_real(int fd, int nb_tour, int oct_lu)
{
	t_ucc	*buff_actif;
	t_ucc	*buff_temp;
	int		ok;
	int		nb_char;

	init_ok_nb_char(&ok, &nb_char);
	if (!init_var(&buff_actif, &buff_temp))
		return ;
	if (get_set_nbchar(GET_STATUS, 0) == AFTER_BEGENING
			&& get_set_nbchar(GET_NUMBER, 0) != 0)
		read(fd, buff_temp, get_set_nbchar(GET_NUMBER, 0));
	oct_lu = nb_char;
	while (oct_lu == nb_char && ok)
	{
		ft_swap_str(&buff_temp, &buff_actif);
		oct_lu = read(fd, buff_actif, (size_t)nb_char);
		if (get_set_nbchar(GET_STATUS, 0) == AFTER_BEGENING)
			ft_putstr(buff_actif, oct_lu);
		nb_tour++;
		if (oct_lu == 0)
			ok = 0;
	}
	ft_end(buff_actif, buff_temp, oct_lu, nb_tour);
}

void			ft_print_file(int fd)
{
	ft_print_file_the_real(fd, 0, get_set_nbchar(GET_NUMBER, 0));
}
