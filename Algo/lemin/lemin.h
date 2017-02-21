/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:06:37 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/28 14:50:54 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include "ft_printf.h"

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				nb_join;
	int				len;
	int				ant;
	struct s_room	*next;
}					t_room;

typedef struct		s_join
{
	t_room			*r1;
	t_room			*r2;
	struct s_join	*next;
}					t_join;

typedef struct		s_ant
{
	int				nb;
	t_room			*room;
	struct s_ant	*next;
}					t_ant;

typedef	struct		s_lem
{
	int				nb_room;
	int				nb_ant;
	int				nb_join;
	int				fd;
	int				bonus_way;
	int				step;
	int				map;
	t_room			*start;
	t_room			*end;
	t_join			*join;
	t_room			*room;
	t_list			*way;
}					t_lem;

int					check_connect(t_lem *lem, char *line);
char				**check_line(t_lem *lem, char *line, int len, int j);
int					get_sharp(t_lem *lem, t_string *string, char **line);
t_room				*check_room(t_lem *lem, char *line, int lvl);
int					check_number(char *str);
t_room				*check_room_name(t_lem *lem, char *str);
t_room				*ft_pushback_room(t_room **room, char **split, t_room *cpy);
t_room				*ft_pushfront_room(t_room **room, char **split, \
					t_room *cpy);
t_join				*new_join(t_room *r1, t_room *r2);
int					get_join2(t_join *to_pass, t_room *room, int ref);
void				ft_pushback_join(t_join **join, t_join *new_join);
void				resolve_lem(t_lem *lem, t_join *start_join, t_room *room);
void				check_way(t_list **way);
int					get_solution(t_lem *lem, t_list *way);
void				clear_room(t_room **way_room);
void				clear_this_room(t_room **room, char *name);
void				clear_join(t_join **join);
void				clear_ant(t_ant **ant);
void				clear_way(t_list **way);
void				clear_lst(t_list *del, t_list **way);
t_room				*new_room(char **split, t_room *src_room);
void				send_ants(t_lem *lem, t_string *string, int *step);
void				add_way_bonus(t_string *string, t_lem *lem);
void				add_map(t_lem *lem, t_string *string);

#endif
