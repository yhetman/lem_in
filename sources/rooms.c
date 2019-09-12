/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:27:50 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/12 20:29:35 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void			validation(t_lst **list, char *type, char **str)
{
	if (!ft_strcmp(*str, START))
		*type = BEGIN;
	else if (!ft_strcmp(*str, END))
		*type = FINISH;
	(*list) = (*list)->next;
	*str = (char*)((*list)->content);
	while (*str[0] == HASH)
	{
		(*list) = (*list)->next;
		*str = (char*)((*list)->content);
	}
}

void				remember_rooms(t_lst **list, t_lemin *lemin)
{
	char			type;
	char			*str;

	while (*list)
	{
		str = (char*)((*list)->content);
		if (!*str)
			return ;
		type = NORM;
		if (str[0] == HASH)
		{
			if (str[1] != HASH)
			{
				(*list) = (*list)->next;
				continue ;
			}
			else
				validation(list, &type, &str);
		}
		if (is_valid_room(&lemin, str, type) == false)
			return ;
		(*list) = (*list)->next;
	}
}
