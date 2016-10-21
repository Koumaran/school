/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:06:37 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/13 21:05:27 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/header/libft.h"
# include "libft/header/ft_printf.h"

#include <stdio.h>
typedef struct		s_ant
{
	int				nb;
	char			*room;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_join
{
	char			*from;
	char			*to;
	struct s_join	*next;
}					t_join;

typedef struct		s_room
{
	char			*name;
	int				nb_ant;
	int				x;
	int				y;
	char			**connect;
	int				len;
	struct s_room	*next;
}					t_room;

typedef	struct		s_lem
{
	int				nb_room;
	int				nb_ant;
	int				nb_join;
	char			*start;
	char			*end;
	t_join			*join;
	t_ant			*ant;
	t_room			*room;
}					t_lem;

int				add_room(t_lem *lem, char **split);
int				create_connection(t_lem *lem, char *from, char *to);
int				get_sharp(t_lem *lem, t_string *string, char *line);
int				check_room(t_lem *lem, char *line);
int				check_room_name(t_lem *lem, char *str);
int				get_join(t_lem *lem);

#endif
