#include "lemin.h"

t_join		*get_join(t_lem *lem, t_room *start, t_join *to_pass)
{
	t_join		*join;

	join = lem->join;
	while (join)
	{
		if (join->r1 == start && join != to_pass)
			return (join);
		if (join->r2 == start && join != to_pass)
			return (join);
		join = join->next;
	}
	return (NULL);
}

void		clear_room(t_room **way_room)
{
	t_room		*room;
	t_room		*tmp;

	room = *way_room;
	while (room)
	{
		ft_strdel(&room->name);
		tmp = room;
		room = room->next;
		free(tmp);
	}
	*way_room = NULL;
}

t_room		*copy_room(t_room *room)
{
	t_room		*tmp;

	tmp = (t_room*)ft_memalloc(sizeof(t_room));
	tmp->name = ft_strdup(room->name);
	tmp->ant = room->ant;
	tmp->x = room->x;
	tmp->y = room->y;
	tmp->next = NULL;
	return (tmp);
}

int			check_if_exist(t_room *room, t_room *get, t_room *start)
{
	t_room		*tmp;

	tmp = room;
	if (get == start)
		return (0);
	while (tmp)
	{
		if (ft_strcmp(tmp->name, get->name) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		get_all_room(t_lem *lem, t_room *way_room, t_room *end)
{
	t_room		*room;
	t_join		*join;

	room = way_room;
	join = lem->join;
	while (join)
	{
		if (join->r1 == room)
		{
			if (check_if_exist(way_room, join->r2, lem->start))
			{
				room->next = copy_room(join->r2);
				room = room->next;
			}
		}
		else if (join->r2 == room)
		{
			if (check_if_exist(way_room, join->r1, lem->start))
			{
				room->next = copy_room(join->r1);
				room = room->next;
			}
		}
		if (ft_strcmp(room->name, end->name) == 0)
			break ;
		join = join->next;
	}
	if (ft_strcmp(room->name, end->name) != 0)
		clear_room(&way_room);
}

int			resolve_lem(t_lem *lem, int nb_join)
{
	t_list		*way;
	t_join		*join;
	t_room		*room;

	way = NULL;
	while (nb_join--)
	{
		if (!(join = get_join(lem, lem->start, join)))
			return (0);
		if (join->r1 == lem->start)
			room = copy_room(join->r2);
		if (join->r2 == lem->start)
			room = copy_room(join->r1);
		get_all_room(lem, room, lem->end);
		if (room)
			ft_lstadd_back(&way, ft_lstnew((void*)room, sizeof(t_room)));
	}
	dprintf(1, "begin\n");
	return (get_solution(lem, way));
}
