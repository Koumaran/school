/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:06:37 by jsivanes          #+#    #+#             */
/*   Updated: 2016/12/10 20:57:45 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/header/libft.h"
# include "libft/header/ft_printf.h"

#include <stdio.h>
typedef struct		s_room
{
	char				*name;
	int				ant;
	int				x;
	int				y;
	int				nb_join;
	int				len;
	struct s_room			*next;
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
	t_room			*start;
	t_room			*end;
	t_join			*join;
	t_room			*room;
}					t_lem;

int				check_connect(t_lem *lem, char *line);
char			**check_line(t_lem *lem, char *line, int len);
int				get_sharp(t_lem *lem, t_string *string, char *line);
t_room			*check_room(t_lem *lem, char *line, int lvl);
int				check_number(char *str);
t_room			*check_room_name(t_lem *lem, char *str);
t_room			*ft_pushback_room(t_room **room, char **split, t_room *cpy);
t_room			*ft_pushfront_room(t_room **room, char **split, t_room *cpy);
t_join			*new_join(t_room *r1, t_room *r2);
void			ft_pushback_join(t_join **join, t_join *new_join);
t_list			*resolve_lem(t_lem *lem, t_join *start_join);
void			check_way(t_list **way);
int				get_solution(t_lem *lem, t_list *way);
void			clear_room(t_room **way_room);
void			clear_this_room(t_room **room, char *name);
void			clear_join(t_join **join);
void			clear_ant(t_ant **ant);
t_room			*new_room(char **split, t_room *src_room);
void			send_ants(t_lem *lem, t_list *way);

#endif
