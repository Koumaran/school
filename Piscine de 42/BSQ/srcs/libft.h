/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:13:03 by atoulous          #+#    #+#             */
/*   Updated: 2016/04/23 13:05:12 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# include <stdio.h>

int		main(int ac, char **av);
int		ft_create_map(void);
void	ft_putstr(char *str);
int		ft_read_first(int fd);
int		ft_read_second(int fd);
char	*ft_strcat(char *tmp, char buf);
int		ft_atoi(char *str);
void	ft_print(void);
void	ft_resolve(int pos_x, int pos_y);

#endif
