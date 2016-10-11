/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <maxpetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 12:25:09 by maxpetit          #+#    #+#             */
/*   Updated: 2016/02/03 12:08:00 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FT_H
# define FT_FT_H

# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_atoi_verif.h"
# define BUFFER 1000

int		ft_strlen(char *str);
void	ft_swap_str(unsigned char **str1, unsigned char **str2);
void	ft_puterror(char *name_prg, char *name_file, char *str);
void	ft_putstr(unsigned char *str, int nb_char);
char	*ft_strdump(char *str);

#endif
