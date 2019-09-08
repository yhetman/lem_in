/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:27:50 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/08 18:35:47 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static bool		coords_validation(char **name)
{
	while (IS_DIGIT(**name))
		(*name)--;
	if (**name == '-' || **name == '+')
		(*name)--;
	(*name)++;
	if (!IS_INT(*name))
		return (false);
	(*name)--;
	if (**name != ' ')
		return (false);
	return (true);
}

static bool			room_is_valid(char *name)
{
	if (name[0] == 'L' || name[0] == HASH)
		return (false);
	name += LEN(name) - 1;
	if (!coords_validation(&name))
		return (false);
	name--;
	if (!coords_validation(&name))
		return (false);
	return (true);
}

char				*find_the_links(char *input)
{
	size_t			i;
	char			*name;

	i = LEN(input);
	if (room_is_valid(input))
	{
		while (!IS_SPACE(input[i]))
			i--;
		i--;
		while (!IS_SPACE(input[i]))
			i--;
		name = ft_strnew(i);
		name = ft_strncpy(name, input, i);
		if (ft_strchr(name, '-'))
		{
			ft_strdel(&name);
			return (NULL);
		}
		else
			return (name);
	}
	else
		return (NULL);
}

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