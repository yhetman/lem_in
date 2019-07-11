/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:53:42 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/11 21:53:52 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	delete_rooms(void *data)
{
	t_room	*room;

	room = (t_room *)data;
	ft_strdel(&room->name);
	ft_lst_rec_free(room->paths);
	free(data);
	data = NULL;
	return ;
}

static void	delete_paths(void *data)
{
	t_path	*path;

	path = (t_path *)data;
	ft_strdel(&path->door1);
	ft_strdel(&path->door2);
	free(data);
	data = NULL;
	return ;
}

void		lemin_end(t_lemin *lemin)
{
	if (lemin)
	{
		if (lemin->room_list)
		{
			ft_lstforeach(lemin->room_list, delete_rooms);
			ft_lst_rec_free(lemin->room_list);
		}
		if (lemin->path_list)
		{
			ft_lstforeach(lemin->path_list, delete_paths);
			ft_lst_rec_free(lemin->path_list);
		}
		if (lemin->ant_list)
			ft_memdel((void **)&lemin->ant_list);
		ft_memdel((void **)&lemin);
	}
	return ;
}
