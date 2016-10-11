/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <maxpetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 12:25:09 by maxpetit          #+#    #+#             */
/*   Updated: 2016/02/03 12:07:30 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATOI_VERIF_H
# define FT_ATOI_VERIF_H

# define WRONG_NUMBER -1
# define AFTER_BEGENING 1
# define BEFOR_ENDING 2
# define SET_STATUS	1
# define SET_NUMBER	2
# define GET_STATUS	3
# define GET_NUMBER 4
# include "ft_ft.h"
# include "print_file.h"

int		get_set_nbchar(int action, int input);
void	ft_atoi_verif(char *str);
void	verrif_number(int *oct_lu);

#endif
