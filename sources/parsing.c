/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:07:17 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:37:51 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


bool				room_already_exists(t_room *map, char *room)
{
	while (map)
	{
		if (!ft_strcmp(map->name, room))
		{
			if (DEBUG > 1)
				ft_printf("DEBUG: \"%s\" already exists.\n", room);
			return (true);
		}
		map = map->next;
	}
	return (false);
}

static bool		add_room(t_lemin **lemin, char *input, char type)
{
	t_room *new;
	char	*name;
	t_coord coord;

	name = room_name(input);
	if (!name)
	{
		if (DEBUG > 1)
			ft_printf("DEBUG: \"%s\" invalid somehow.\n", input);
		ft_strdel(&name);
		return (false);
	}
	coord = get_coord(input);
	if (type == BEGIN || type == FINISH)
		if (!remember_begining_finish(*lemin, name, type))
			return (false);
	if ((*lemin)->amount_of_rooms && room_already_exists((*lemin)->amount_of_rooms, name))
	{
		ft_strdel(&name);
		return (false);
	}
	new = add_new_room(name, type, &coord, (*lemin)->amount_of_ants);
	new->next = (*lemin)->amount_of_rooms;
	(*lemin)->amount_of_rooms = new;
	return (true);
}

bool				remember_begining_finish(t_lemin *lemin, char *name, char type)
{
	if (type == FINISH)
	{
		if (lemin->finish_name)
		{
			ft_memdel((void**)&name);
			return (false);
		}
		lemin->finish_name = ft_strdup(name);
	}
	else if (type == BEGIN)
	{
		if (lemin->begin_name)
		{
			ft_memdel((void**)&name);
			return (false);
		}
		lemin->begin_name = ft_strdup(name);
	}
	return (true);
}

static inline void	parse_special(t_lst **ptr, char *type, char **str)
{
	if (!ft_strcmp(*str, "##start"))
		*type = BEGIN;
	else if (!ft_strcmp(*str, "##end"))
		*type = FINISH;
	(*ptr) = (*ptr)->next;
	*str = (char*)((*ptr)->content);
	while (*str[0] == '#')
	{
		(*ptr) = (*ptr)->next;
		*str = (char*)((*ptr)->content);
	}
}

void				remember_rooms(t_lst **ptr, t_lemin *lemin)
{
	char	type;
	char	*str;

	while (*ptr)
	{
		str = (char*)((*ptr)->content);
		if (!*str)
			return ;
		type = NORM;
		if (str[0] == '#')
		{
			if (str[1] != '#')
			{
				(*ptr) = (*ptr)->next;
				continue ;
			}
			else
				parse_special(ptr, &type, &str);
		}
		if (add_room(&lemin, str, type) == false)
			return ;
		(*ptr) = (*ptr)->next;
	}
}
