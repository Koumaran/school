/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 21:19:00 by jsivanes          #+#    #+#             */
/*   Updated: 2016/06/20 19:53:19 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FILE_H
# define MY_FILE_H

void			ft_add(int nb1, int nb2);
void			ft_sub(int nb1, int nb2);
void			ft_mult(int nb1, int nb2);
void			ft_div(int nb1, int nb2);
void			ft_mod(int nb1, int nb2);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(char *str);
int				ft_atoi(char *str);

typedef	struct	s_opp
{
	char		*str;
	void		(*f)(int, int);
}				t_opp;
#endif
