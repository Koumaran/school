#include "lemin.h"

t_room		*resolve_lem(t_lem *lem, t_room *room, char *connect_name, int *nb)
{
	t_room		*tmp;
	t_room		*tmp2;
	char		*name;

	tmp = copy_room(room);
	tmp2 = tmp;
	name = connect_name;
	*nb += 1;
	while ((room = get_connect_room(lem->room, tmp2, name)) != NULL)
	{
		tmp->next = copy_room(room);
		tmp = tmp->next;
		*nb += 1;
		if (ft_strcmp(name, lem->end) == 0)
			return (tmp2);
		if (room->len == 0)
			return (NULL);
		if (romm->len > 1)
			tmp->next =

	}
		
}
