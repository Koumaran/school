/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:31:12 by jsivanes          #+#    #+#             */
/*   Updated: 2016/02/24 16:31:14 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>

int		ft_atoi(char *str);
char	ft_sign(char *str);
void	ft_display_tail(char *str, int nb, char sign);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_tail(int argc, char **argv);

#endif
