/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 18:58:21 by jsivanes          #+#    #+#             */
/*   Updated: 2016/08/23 17:39:50 by jsivanes         ###   ########.fr       */
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
	void				(*get_op)(t_nb **a, t_nb **b, t_flag *flag, char **str);
}						t_opp;

typedef struct			s_box
{
	int					max;
	int					min;
	int					len;
	int					midl;
	char				*str;
	char				*str1;
	struct s_nb			*a;
	struct s_nb			*a1;
	struct s_nb			*b;
}						t_box;

t_box					parse_swap(t_flag *flag, char **av, t_box *box, int y);
t_nb					*ft_create_elem(int nbr);
void					ft_list_push_back(t_nb **begin, int nbr);
int						check_good(t_nb *a);
int						check_good_r(t_nb *a);
void					check_double(t_nb *a);
t_flag					*add_flag_sw(char *str, t_flag *flag);

int						operation(t_nb **a, t_nb *b, t_flag *flag, char *str);
t_box					*do_op_on_b(t_box *box, char **str, t_flag *flag);
char					*swap_brute(t_box *box, t_flag *flag);
char					*swap_brute_r(t_box *box, t_flag *flag);
t_box					*before_tri(t_box *box, char **str, t_flag *flag);
t_box					*before_tri_r(t_box *box, char **str, t_flag *flag);
char					*swap_selection(t_box *box, t_flag *flag);
char					*swap_selection_r(t_box *box, t_flag *flag);
void					print_option_sw(t_nb *a, t_nb *b, char **str);

int						ft_max(t_nb *tab);
int						ft_min(t_nb *tab);
int						ft_min2(t_nb *tab, int min);
int						get_positionnb(t_nb *a, int nb);
int						get_len(t_nb *a, int *midl);
t_box					*init_box(t_box *box, t_nb *a);

char					*print_join(char **tab, int len);
void					print_v(char **tab, int c);
void					print_ps(char **tab, int c);

void					sa(t_nb **a, t_nb **b, t_flag *flag, char **str);
void					sb(t_nb **a, t_nb **b, t_flag *flag, char **str);
void					ss(t_nb **a, t_nb **b, t_flag *flag, char **str);
void					ra(t_nb **a, t_nb **b, t_flag *flag, char **str);
void					rb(t_nb **a, t_nb **b, t_flag *flag, char **str);
void					rr(t_nb **a, t_nb **b, t_flag *flag, char **str);
void					rra(t_nb **a, t_nb **b, t_flag *flag, char **str);
void					rrb(t_nb **a, t_nb **b, t_flag *flag, char **str);
void					rrr(t_nb **a, t_nb **b, t_flag *flag, char **str);
void					pa(t_nb **a, t_nb **b, t_flag *flag, char **str);
void					pb(t_nb **a, t_nb **b, t_flag *flag, char **str);

#endif
