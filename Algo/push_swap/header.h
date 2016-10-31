/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 18:58:21 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/28 19:29:06 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "libft.h"
# include "ft_printf.h"

# define CMP(e, f)		(ft_strcmp(e, f))

typedef struct			s_flag
{
	int					v;
	int					c;
	int					r;
	int					h;
}						t_flag;

typedef struct			s_nb
{
	int					nb;
	struct s_nb			*next;
	struct s_nb			*previus;
}						t_nb;

typedef struct			s_opp
{
	char				*name;
	void				(*get_op)(t_nb **a, t_nb **b, t_flag *flag, t_string *string);
}						t_opp;

typedef struct			s_box
{
	int					max;
	int					min;
	int					len;
	int					midl;
	struct s_nb			*a;
	struct s_nb			*b;
}						t_box;

t_box					parse_swap(t_flag *flag, char **av, t_box *box, int y);
t_nb					*ft_create_elem(int nbr);
void					ft_list_push_back(t_nb **begin, int nbr);
void					get_extrem_box(t_box *box, t_nb *a);
int						check_good(t_nb *a);
int						check_good_r(t_nb *a);
void					check_double(t_nb *a);
t_flag					*add_flag_sw(char *str, t_flag *flag);

int						operation(t_box *box, t_flag *flag, t_string *string);
void					swap_brute(t_box *box, t_flag *flag, t_string *string);
t_box					*do_op_on_b(t_box *box, t_flag *flag, t_string *string);
void					swap_brute_r(t_box *box, t_flag *flag, t_string *string);
t_box					*before_tri(t_box *box, t_flag *flag, t_string *string);
t_box					*before_tri_r(t_box *box, t_flag *flag, t_string *string);
void					swap_select(t_box *box, t_flag *flag, t_string *string);
void					swap_select_r(t_box *box, t_flag *flag, t_string *string);
void					rotate_well_b(t_box *box, t_flag *flag,
						t_string *string, int nb);
void					print_option_sw(t_nb *a, t_nb *b, t_string *string);

int						get_position(t_nb *pile, int nb);
int						ft_big_elem(t_nb *pile);
int						ft_small_elem(t_nb *pile);
int						get_positionnb(t_nb *a, int nb);
int						get_len(t_nb *a, int *midl);

char					*print_join(char **tab, int len);
void					print_v(char **tab, int c);
void					print_ps(char **tab, int c);

void					sa(t_nb **a, t_nb **b, t_flag *flag, t_string *string);
void					sb(t_nb **a, t_nb **b, t_flag *flag, t_string *string);
void					ss(t_nb **a, t_nb **b, t_flag *flag, t_string *string);
void					ra(t_nb **a, t_nb **b, t_flag *flag, t_string *string);
void					rb(t_nb **a, t_nb **b, t_flag *flag, t_string *string);
void					rr(t_nb **a, t_nb **b, t_flag *flag, t_string *string);
void					rra(t_nb **a, t_nb **b, t_flag *flag, t_string *string);
void					rrb(t_nb **a, t_nb **b, t_flag *flag, t_string *string);
void					rrr(t_nb **a, t_nb **b, t_flag *flag, t_string *string);
void					pa(t_nb **a, t_nb **b, t_flag *flag, t_string *string);
void					pb(t_nb **a, t_nb **b, t_flag *flag, t_string *string);

#endif
