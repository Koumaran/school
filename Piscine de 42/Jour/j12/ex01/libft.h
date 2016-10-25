/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:30:02 by jsivanes          #+#    #+#             */
/*   Updated: 2016/03/02 14:00:30 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

int		ft_strlen(char *str);
void	ft_putnbr(int nb);
void	ft_putstr(char *str, char *name_file, int error);
void	ft_display_file(int fd);
void	ft_open(int ac, char **av, int i);
void	ft_putchar(char c);
void	ft_putnbr(int nb);

#endif
