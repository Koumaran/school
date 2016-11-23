#include "lemin.h"

t_join		*get_join(t_lem *lem, t_room *start, t_list *to_pass)
{
	t_join		*join;
	t_join		*tmp_j;
	t_list		*tmp;

	join = lem->join;
	while (join)
	{
		tmp = to_pass;
		if (join->r1 == start)
		{
			while (tmp)
			{
				tmp_j = (t_join*)tmp->content;
				dprintf(1, "groar=%s\n",tmp_j->r1->name);
				if (!ft_strcmp(tmp_j->r2->name, join->r2->name))
					break ;
				tmp = tmp->next;
			}
			if (!tmp)
				return (join);
		}
		if (join->r2 == start)
		{
			while (tmp)
			{
				tmp_j = (t_join*)tmp->content;
				if (!ft_strcmp(tmp_j->r1->name, join->r1->name))
					break ;
				tmp = tmp->next;
			}
			if (!tmp)
				return (join);
		}
		join = join->next;
	}
	return (NULL);
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

void		get_all_room(t_lem *lem, t_room **way_room, t_room *end)
{
	t_join		*join;
	t_room		*room;
	int			i;

	join = lem->join;
	room = *way_room;
	i = 0;
	while (join)
	{
		if (ft_strcmp(join->r1->name, room->name) == 0)
		{
			if (check_if_exist(*way_room, join->r2, lem->start))
				room = ft_pushback_room(way_room, NULL, join->r2);
		}
		else if (ft_strcmp(join->r2->name, room->name) == 0)
		{
			if (check_if_exist(*way_room, join->r1, lem->start))
				room = ft_pushback_room(way_room, NULL, join->r1);
		}
		if (ft_strcmp(room->name, end->name) == 0)
			break ;
		join = join->next;
	}
	if (ft_strcmp(room->name, end->name) != 0)
		clear_room(way_room);
}

int			resolve_lem(t_lem *lem, int nb_join)
{
	t_list		*way;
	t_list		*tmp_join;
	t_join		*join;
	t_room		*room;
	t_list		*tmp;
	t_join		*tmp_j;

	way = NULL;
	tmp_join = NULL;
	while (nb_join--)
	{
		room = NULL;
		if (!(join = get_join(lem, lem->start, tmp_join)))
			return (0);
		ft_lstadd_back(&tmp_join, ft_lstnew((void*)join, sizeof(t_join)));
		if (join->r1 == lem->start)
			ft_pushfront_room(&room, NULL, join->r2);
		if (join->r2 == lem->start)
			ft_pushfront_room(&room, NULL, join->r1);
		get_all_room(lem, &room, lem->end);
		if (room)
			ft_lstadd_back(&way, ft_lstnew((void*)room, sizeof(t_room)));
	}
	while (tmp_join)
	{
		tmp_j = (t_join*)tmp_join->content;
		dprintf(1, "join r1=%s, r2 =%s\n", tmp_j->r1->name, tmp_j->r2->name);
		tmp_join = tmp_join->next;
	}
	tmp = way;
	while (tmp)
	{
		room = (t_room*)tmp->content;
		ft_printf("name=%s\n", room->name);
		while (room)
		{
			dprintf(1, "tmp->room=%s join=%d\n", room->name, room->nb_join);
			room = room->next;
		}
		tmp = tmp->next;
	}
	return (1);
	//return (get_solution(lem, way));
}
