/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:06:37 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/11 15:21:59 by jsivanes         ###   ########.fr       */
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

typedef struct		s_room
{
	char			*name;
	int				nb_ant;
	int				x;
	int				y;
	char			**connect;
	struct s_room	*next;
}					t_room;

typedef	struct		s_lem
{
	int				nb_room;
	int				nb_ant;
	char			*start;
	char			*end;
	t_ant			*ant;
	t_room			*room;
}					t_lem;

int				add_room(t_lem *lem, char **split);
int				get_sharp(t_lem *lem, t_string *string, char *line);
int				check_room(t_lem *lem, char *line);
int				check_room_name(t_lem *lem, char *str);

#endif
