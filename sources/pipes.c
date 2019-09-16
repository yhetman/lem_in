/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:40:59 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 15:51:27 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void			diagonal_neighbour(t_lemin *lemin, t_room *tmp, int i)
{
	tmp = lemin->amount_of_rooms;
	while (lemin->amount_of_rooms)
	{
		lemin->pipes[i][i] = lemin->amount_of_rooms->type;
		lemin->amount_of_rooms = lemin->amount_of_rooms->next;
		i++;
	}
	lemin->amount_of_rooms = tmp;
}

static inline int	find_right_rooms(char **matrix, int aim, int i)
{
	while (matrix[i][i] != aim)
		i++;
	return (i);
}

static inline int	amount_of_rooms(t_room *amount_of_rooms, int index)
{
	while (amount_of_rooms && ++index)
		amount_of_rooms = amount_of_rooms->next;
	return (index);
}

bool				remember_pipes(t_lst **list, t_lemin *lemin)
{
	int				nb_rooms;
	int				i;
	bool			has_one_pipe;

	i = -1;
	has_one_pipe = false;
	nb_rooms = amount_of_rooms(lemin->amount_of_rooms, 0);
	lemin->pipes = ft_memalloc(sizeof(char*) * (nb_rooms + 1));
	while (++i < nb_rooms)
	{
		lemin->pipes[i] = ft_memalloc(sizeof(char) * (nb_rooms + 1));
		ft_memset(lemin->pipes[i], NORM, sizeof(char) * (nb_rooms));
	}
	lemin->size_of_graph = nb_rooms;
	diagonal_neighbour(lemin, NULL, 0);
	initialize_pipes(lemin, list);
	lemin->begin = find_right_rooms(lemin->pipes, BEGIN, 0);
	lemin->finish = find_right_rooms(lemin->pipes, FINISH, 0);
	while (--i >= 0 && !has_one_pipe)
		if (!has_one_pipe)
			has_one_pipe = !(!ft_strchr(lemin->pipes[i], LINKED));
	return (has_one_pipe);
}
