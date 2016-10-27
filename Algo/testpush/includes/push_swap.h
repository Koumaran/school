/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 13:13:37 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/06 10:44:18 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct		s_pile
{
	int				nb;
	struct s_pile	*next;
}					t_pile;

typedef struct		s_solv
{
	unsigned char	color;
	unsigned char	opt;
	int				length;
	t_pile			*pile_a;
	t_pile			*pile_b;
	char			*solution;
	int				last;
	int				smallest;
	int				biggest;
}					t_solv;

# define FT_COLORIZED	0x1
# define FT_SBS			0x2
# define FT_NB_C		0x4
# define FT_WAIT		0x8
# define FT_PILE_A		0x10
# define FT_GAME		0x20

# define FT_FA			0x1
# define FT_FB			0x2
# define FT_SA			0x4
# define FT_SB			0x8
# define FT_LA			0x10
# define FT_LB			0x20

int					ft_check_validity(int length, char **pile_a);
int					ft_check_double(char **pile_a);

void				sa(t_solv *solv, int state);
void				sb(t_solv *solv, int state);
void				ss(t_solv *solv, int state);

void				pa(t_solv *solv, int state);
void				pb(t_solv *solv, int state);

void				ra(t_solv *solv, int state);
void				rb(t_solv *solv, int state);
void				rr(t_solv *solv, int state);

void				rra(t_solv *solv, int state);
void				rrb(t_solv *solv, int state);
void				rrr(t_solv *solv, int state);

/*
** Predicats
*/

int					ft_is_sorted_asc(t_solv *solv);
int					ft_is_half_sorted(t_solv *solv);
int					ft_is_nearest_begin_a(t_solv *solv, int nb);
int					ft_is_nearest_begin_b(t_solv *solv, int nb);
int					ft_is_rev_sorted(t_solv *solv);

/*
** Functions get
*/

void				ft_get_extremes_a(t_solv *solv);
void				ft_get_extremes_b(t_solv *solv);
int					ft_get_bgst_to_swap(t_solv *solv);
int					ft_get_smlst_to_swap(t_solv *solv);
void				ft_getsol(t_solv *solv, char *to_write);
void				ft_get_ope(t_solv *solv, char *ope);
int					ft_get_smaller_a(t_solv *solv, int nb);
int					ft_get_smaller_b(t_solv *solv, int nb);
int					ft_get_bigger_a(t_solv *solv, int nb);
int					ft_get_pn(t_solv *solv, int nb, int pn);

/*
** Print functions
*/

void				ft_print_pa(t_solv *solv);
void				ft_print_pb(t_solv *solv);

/*
** Sorting functions
*/

void				ft_sort(t_solv *solv);
void				ft_rotate_well_a(t_solv *solv, int to_sort);
void				ft_rotate_well_b(t_solv *solv, int to_sort);
void				ft_end_ps(t_solv *solv);
void				ft_first_sort(t_solv *solv);
void				second_sort(t_solv *solv);
int					ft_simple_swap(t_solv *solv);
int					ft_sec_swap(t_solv *solv);
int					ft_third_swap(t_solv *solv);
void				ft_rotate_to_push(t_solv *solv, int nb, int opt);
void				ft_last_choice(t_solv *solv, int smlst);
void				ft_fourth_choice(t_solv *solv);

t_solv				*ft_initialisation(int ac, char **av);

void				ft_end_ps(t_solv *solv);
void				ft_game(t_solv *solv);

#endif
