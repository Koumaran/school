#include "lemin.h"

void		add_way_bonus(t_string *string, t_lem *lem)
{
	t_room	*room;
	t_list	*tmp;
	int	i;

	tmp = lem->way;
	i = 1;
	while (tmp)
	{
		ft_printf_string(string, "\nChemin %d:\n{green}[%s]{eoc}---", i++, lem->start->name);
		room = (t_room*)tmp->content;
		while (room)
		{
			if (ft_strcmp(room->name, lem->end->name) == 0)
				ft_printf_string(string, "{red}[%s]{eoc}", room->name);
			else
				ft_printf_string(string, "[%s]", room->name);
			if (room->next)
				ft_stringadd(string, "---", 3);
			else
				ft_stringaddc(string, '\n');
			room = room->next;
		}
		tmp = tmp->next;
	}
}
