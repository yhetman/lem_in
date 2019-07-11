/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:42:35 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/11 21:43:40 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*get_room_name(char *name, t_list *list)
{
	int		done;
	t_room	*tmp;

	done = 0;
	while (list && !done)
	{
		tmp = (t_room *)list->content;
		done = ft_strequ(name, tmp->name);
		list = list->next;
	}
	return (done ? tmp : NULL);
}

void		lemin_start(t_lemin *lemin)
{
	t_room	*room;
	t_path	*path;
	t_list	*tmp_room;
	t_list	*tmp_path;

	tmp_room = lemin->room_list;
	while (tmp_room != 0)
	{
		room = (t_room *)tmp_room->content;
		tmp_path = lemin->path_list;
		while (tmp_path != 0)
		{
			path = (t_path *)tmp_path->content;
			if (ft_strequ(path->door1, room->name))
				room->paths = ft_lstpush(room->paths, \
						get_room_name(path->door2, lemin->room_list));
			if (ft_strequ(path->door2, room->name))
				room->paths = ft_lstpush(room->paths, \
						get_room_name(path->door1, lemin->room_list));
			tmp_path = tmp_path->next;
		}
		tmp_room = tmp_room->next;
	}
	return ;
}
