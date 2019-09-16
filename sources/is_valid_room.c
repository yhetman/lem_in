/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:33:26 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 15:33:16 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static bool		check_name_in_list(t_room *map, char *room)
{
	while (map)
	{
		if (!ft_strcmp(map->name, room))
			return (true);
		map = map->next;
	}
	return (false);
}

static bool		find_start_and_end(t_lemin *lemin,
				char *name, char type)
{
	if (type == FINISH)
	{
		if (lemin->end_name)
		{
			ft_strdel(&name);
			return (false);
		}
		lemin->end_name = ft_strdup(name);
	}
	else if (type == BEGIN)
	{
		if (lemin->start_name)
		{
			ft_strdel(&name);
			return (false);
		}
		lemin->start_name = ft_strdup(name);
	}
	return (true);
}

static void		free_splitted(char **split)
{
	char		**temp;
	char		**back;

	if (!split)
		return ;
	temp = split;
	back = split;
	while (*split)
	{
		temp = split + 1;
		ft_strdel(split);
		split = temp;
	}
	ft_memdel((void**)&back);
}

static t_coord	remember_coords(char *input)
{
	int			i;
	char		**splitted;
	t_coord		coord;

	ft_bzero((void*)&coord, sizeof(t_coord));
	splitted = ft_strsplit(input, ' ');
	i = 0;
	while (splitted[i])
		i++;
	if (i > 3)
	{
		coord.x = ft_atoi(splitted[i - 3]);
		coord.y = ft_atoi(splitted[i - 2]);
	}
	free_splitted(splitted);
	return (coord);
}

bool			is_valid_room(t_lemin **lemin, char *input, char type)
{
	t_room		*new;
	char		*room_name;
	t_coord		coord;

	room_name = find_the_links(input);
	if (!room_name)
	{
		ft_strdel(&room_name);
		return (false);
	}
	coord = remember_coords(input);
	if (type == BEGIN || type == FINISH)
		if (!find_start_and_end(*lemin, room_name, type))
			return (false);
	if ((*lemin)->amount_of_rooms
		&& check_name_in_list((*lemin)->amount_of_rooms, room_name))
	{
		ft_strdel(&room_name);
		return (false);
	}
	new = initialize_room(room_name, type, &coord, (*lemin)->ants);
	new->next = (*lemin)->amount_of_rooms;
	(*lemin)->amount_of_rooms = new;
	return (true);
}
