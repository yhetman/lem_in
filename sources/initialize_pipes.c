/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:46:44 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 15:05:36 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	clean_pipes(char **split)
{
	char	**temp;
	char	**ptr;

	if (!split)
		return ;
	temp = split;
	ptr = split;
	while (*split)
	{
		temp = split + 1;
		ft_strdel(split);
		split = temp;
	}
	ft_memdel((void**)&ptr);
}

static int	numeration_of_rooms(char *name, t_room *amount_of_rooms)
{
	int		i;

	i = 0;
	while (amount_of_rooms)
	{
		if (!ft_strcmp(amount_of_rooms->name, name))
			return (i);
		amount_of_rooms = amount_of_rooms->next;
		i++;
	}
	return (-1);
}

static bool	parse_pipes(t_lst **ptr, char ***split, t_lemin *lemin)
{
	int		rooms_to_connect[2];

	if (ft_strcntchr(((char*)(*ptr)->content), &ft_isdash) > 1
			|| ft_strcntsplt(*split) != 2)
	{
		clean_pipes(*split);
		*ptr = (*ptr)->next;
		return (false);
	}
	rooms_to_connect[0] = numeration_of_rooms(*split[0],
			lemin->amount_of_rooms);
	if (rooms_to_connect[0] != -1)
		rooms_to_connect[1] = numeration_of_rooms((*split)[1],
				lemin->amount_of_rooms);
	if (rooms_to_connect[0] == -1 || rooms_to_connect[1] == -1)
	{
		clean_pipes(*split);
		return (false);
	}
	lemin->pipes[rooms_to_connect[0]][rooms_to_connect[1]] = LINKED;
	lemin->pipes[rooms_to_connect[1]][rooms_to_connect[0]] = LINKED;
	return (true);
}

void		initialize_pipes(t_lemin *lemin, t_lst **ptr)
{
	char	**split;

	while (*ptr)
	{
		if (((char*)(*ptr)->content)[0] == HASH)
		{
			(*ptr) = (*ptr)->next;
			continue ;
		}
		split = ft_strsplit((char *)(*ptr)->content, '-');
		if (!parse_pipes(ptr, &split, lemin))
			break ;
		*ptr = (*ptr)->next;
		clean_pipes(split);
	}
}
