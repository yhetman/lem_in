/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:01:08 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/11 22:13:35 by yhetman          ###   ########.fr       */
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

static bool     room_is_valid(char *name)
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

char			*find_the_links(char *input)
{
	size_t      i;
	char	    *name;

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
