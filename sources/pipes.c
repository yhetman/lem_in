/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:04:50 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 19:15:51 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void				fill_diagonal_types(t_lemin *lemin)
{
	t_room	*tmp;
	int		i;

	tmp = lemin->amount_of_rooms;
	i = 0;
	while (lemin->amount_of_rooms)
	{
		lemin->pipes[i][i] = lemin->amount_of_rooms->type;
		i++;
		lemin->amount_of_rooms = lemin->amount_of_rooms->next;
	}
	lemin->amount_of_rooms = tmp;
}

static inline bool	parse_pipes(t_lst **ptr, char ***split, t_lemin *lemin)
{
	int		rooms_to_connect[2];

	if (ft_strcntchr(((char*)(*ptr)->content), &ft_isdash) > 1
			|| amount_of_splits(*split) != 2)
	{
		clean_double_array(*split);
		*ptr = (*ptr)->next;
		return (false);
	}
	rooms_to_connect[0] = check_name_in_list(*split[0], lemin->amount_of_rooms);
	if (rooms_to_connect[0] != -1)
		rooms_to_connect[1] = check_name_in_list((*split)[1], lemin->amount_of_rooms);
	if (rooms_to_connect[0] == -1 || rooms_to_connect[1] == -1)
	{
		clean_double_array(*split);
		return (false);
	}
	lemin->pipes[rooms_to_connect[0]][rooms_to_connect[1]] = LINKED;
	lemin->pipes[rooms_to_connect[1]][rooms_to_connect[0]] = LINKED;
	return (true);
}

static void				fill_tab_pipes(t_lemin *lemin, t_lst **ptr)
{
	char	**split;

	while (*ptr)
	{
		if (((char*)(*ptr)->content)[0] == '#')
		{
			(*ptr) = (*ptr)->next;
			continue ;
		}
		split = ft_strsplit((char *)(*ptr)->content, '-');
		if (!parse_pipes(ptr, &split, lemin))
			break ;
		*ptr = (*ptr)->next;
		clean_double_array(split);
	}
}

static int				get_special_id(char **matrix, int to_find)
{
	int		i;

	i = 0;
	while (matrix[i][i] != to_find)
		i++;
	return (i);
}

bool					remember_pipes(t_lst **ptr, t_lemin *lemin)
{
	int		nb_rooms;
	int		i;
	bool	has_one_pipe;

	i = -1;
	has_one_pipe = false;
	nb_rooms = amount_of_rooms_in_list(lemin->amount_of_rooms);
	lemin->pipes = ft_memalloc(sizeof(char*) * (nb_rooms + 1));
	while (++i < nb_rooms)
	{
		lemin->pipes[i] = ft_memalloc(sizeof(char) * (nb_rooms + 1));
		ft_memset(lemin->pipes[i], NORM, sizeof(char) * (nb_rooms));
	}
	lemin->size_of_graph = nb_rooms;
	fill_diagonal_types(lemin);
	fill_tab_pipes(lemin, ptr);
	lemin->begin = get_special_id(lemin->pipes, BEGIN);
	lemin->finish = get_special_id(lemin->pipes, FINISH);
	while (--i >= 0 && !has_one_pipe)
		if (!has_one_pipe)
			has_one_pipe = !(!ft_strchr(lemin->pipes[i], LINKED));
	return (has_one_pipe);
}
