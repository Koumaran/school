#ifndef LEMIN_H
# define LEMIN_H

# include "libft/header/libft.h"
# include "libft/header/ft_printf.h"

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

#endif
