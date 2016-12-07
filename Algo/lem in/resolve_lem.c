#include "lemin.h"

t_join		*get_join(t_lem *lem, t_room *room, t_join *to_pass)
{
	t_join		*join;
	t_join		*tmp;

	join = lem->join;
	while (join)
	{
		tmp = to_pass;
		if (join->r1 == room)
		{
			while (tmp)
			{
				if (!ft_strcmp(tmp->r2->name, join->r2->name))
					break ;
				tmp = tmp->next;
			}
			if (!tmp)
				return (join);
		}
		if (join->r2 == room)
		{
			while (tmp)
			{
				if (!ft_strcmp(tmp->r1->name, join->r1->name))
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

int			check_if_exist(t_room **room, t_room *get, t_room *start)
{
	t_room		*tmp;
	int			i;

	tmp = *room;
	if (ft_strcmp(get->name, start->name) == 0)
		return (0);
	i = 0;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, get->name) == 0)
			i++;
		tmp = tmp->next;
	}
	if (i > 1)
		return (0);
	return (1);
}

int			check_if_end(t_room *room, t_room *end)
{
	t_room *tmp;

	tmp = room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, end->name) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			get_child(t_lem *lem, t_room **room, t_room *src_room, t_join **join_lst)
{
	t_join		*join;
	t_room		*tmp_room;

	while ((join = get_join(lem, src_room, *join_lst)) != NULL)
	{
		ft_pushback_join(join_lst, new_join(join->r1, join->r2));
		tmp_room = (join->r1 == src_room) ? join->r2 : join->r1;
		ft_pushback_room(room, NULL, tmp_room);
		(*room)->len++;
		dprintf(1, "src=%s =>child name=%s join r1=%s r2=%s\n", src_room->name, tmp_room->name, join->r1->name, join->r2->name);
		if (check_if_exist(room, tmp_room, lem->start))
		{
			dprintf(1, "child 2 name=%s\n", tmp_room->name);
			if (tmp_room != lem->end)
				if (get_child(lem, room, tmp_room, join_lst) == 0)
				{
					clear_this_room(room, tmp_room->name);
					(*room)->len--;
				}
			dprintf(1, "child 2 paased\n");
		}
		else
		{
			clear_this_room(room, tmp_room->name);
			(*room)->len--;
		}
		if (check_if_end(*room, lem->end))
			return (1);
	}
	return (0);
}

int			resolve_lem(t_lem *lem, t_join *start_join)
{
	t_list		*way;
	t_join		*join_lst;
	t_join		*join;
	t_room		*room;
	t_room		*tmp_room;
	t_list		*tmp;

	way = NULL;
	join = start_join;
	while (join)
	{
		room = NULL;
		join_lst = NULL;
		ft_pushback_join(&join_lst, new_join(join->r1, join->r2));
		tmp_room = (join->r1 == lem->start) ? join->r2 : join->r1;
		ft_pushback_room(&room, NULL, tmp_room);
		dprintf(1, "begin name=%s\n", tmp_room->name);
		room->len = 1;
		if (tmp_room != lem->end)
			if (tmp_room->nb_join < 2 || get_child(lem, &room, tmp_room, &join_lst) == 0)
			{
				dprintf(1, "a effacer\n");
				clear_room(&room);
			}
		if (room)
			ft_lstadd_back(&way, ft_lstnew((void*)room, sizeof(t_room)));
		join = join->next;
	}
	while (join_lst)
	{
		dprintf(1, "join r1=%s, r2 =%s\n", join_lst->r1->name, join_lst->r2->name);
		join_lst = join_lst->next;
	}
	tmp = way;
	while (tmp)
	{
		room = (t_room*)tmp->content;
		dprintf(1, "room_len = %d\n", room->len);
		while (room)
		{
			dprintf(1, "room_name=%s join=%d\n", room->name, room->nb_join);
			room = room->next;
		}
		tmp = tmp->next;
	}
	if (!way)
		return (0);
	return (1);
	//return (get_solution(lem, way));
}
