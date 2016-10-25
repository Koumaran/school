/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:43:51 by jsivanes          #+#    #+#             */
/*   Updated: 2016/09/20 14:40:22 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "ft_printf.h"

typedef struct		s_opt
{
	int				s;
	int				fd;
}					t_opt;

typedef	struct		s_piece
{
	int				x;
	int				y;
	int				i;
	int				j;
	int				pos_x;
	int				pos_y;
	int				a_x;
	int				a_y;
}					t_piece;

typedef struct		s_fil
{
	char			h;
	char			v;
	char			**map;
	char			**cube;
	int				h_y;
	int				v_y;
	int				blocked;
	int				m_x;
	int				m_y;
	int				c_x;
	int				c_y;
	int				orientation;
}					t_fil;

void				get_map(t_fil *fil, t_opt *opt);
void				get_cube(t_fil *fil, t_opt *opt);
void				resolver_filler(t_fil *fil, t_opt *opt);
void				resolver_filler_up(t_fil *fil, t_piece *piece, int m_vil);
void				resolver_filler_down(t_fil *fil, t_piece *piece, int m_vil);
int					add_midlup(t_fil *fil, t_piece *p);
int					add_midldown(t_fil *fil, t_piece *p);
void				get_optionfil(t_opt *opt, char *str);
void				opt_s(t_opt *opt, int y, int x);

#endif
