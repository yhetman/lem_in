/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:27:50 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 19:16:38 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static bool	check_room_coordinate(char **name)
{
	while (ft_isdigit(**name))
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

static bool	room_is_valid(char *name)
{
	if (name[0] == 'L' || name[0] == '#')
		return (false);
	name += ft_strlen(name) - 1;
	if (!check_room_coordinate(&name))
		return (false);
	name--;
	if (!check_room_coordinate(&name))
		return (false);
	return (true);
}

t_room			*add_new_room(char *name_ptr, char type, t_coord *coord, \
int ant_amount)
{
	t_room	*new;

	new = ft_memalloc(sizeof(t_room));
	new->coord.x = coord->x;
	new->coord.y = coord->y;
	new->name = name_ptr;
	new->type = type;
	if (type == BEGIN)
		new->ant_amount = ant_amount;
	else
		new->ant_amount = 0;
	new->next = NULL;
	return (new);
}

char			*room_name(char *input)
{
	size_t	i;
	char	*name;

	i = ft_strlen(input);
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

int				check_name_in_list(char *name, t_room *amount_of_rooms)
{
	int	i;

	i = 0;
	while (amount_of_rooms)
	{
		if (!ft_strcmp(amount_of_rooms->name, name))
			return (i);
		i++;
		amount_of_rooms = amount_of_rooms->next;
	}
	return (-1);
}
