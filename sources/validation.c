/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:41:40 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/11 21:42:10 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	validate_rooms_name(t_list *rooms)
{
	int		ret;
	t_room	*tmp;

	ret = 0;
	if (rooms != 0)
	{
		while (rooms)
		{
			tmp = (t_room *)rooms->content;
			if (tmp->name[0] == '#' || tmp->name[0] == 'L' \
				|| ft_strchr(tmp->name, '-') != 0)
				break ;
			rooms = rooms->next;
		}
		ret = 1;
	}
	return (ret && !rooms);
}

static int	validate_rooms_flag(t_list *rooms, t_list *paths)
{
	int		start;
	int		end;
	t_room	*tmp;

	start = 0;
	end = 0;
	if (rooms != 0 || paths != 0)
	{
		while (rooms)
		{
			tmp = (t_room *)rooms->content;
			if (tmp->flag == STARTROOM)
				start += 1;
			if (tmp->flag == ENDROOM)
				end += 1;
			rooms = rooms->next;
		}
	}
	return (start == 1 && end == 1);
}


static inline int	validate_paths(t_room *rooms, t_list *paths)
{
	return ((rooms != 0 && paths != 0) && find_room(rooms, ENDROOM) >= 0);
}

int			lemin_validate(t_lemin *lemin)
{
	return (validate_paths(get_room_flag(STARTROOM, lemin->room_list),
			lemin->path_list) && validate_rooms_flag(lemin->room_list,
			lemin->path_list) && validate_rooms_name(lemin->room_list));
}
