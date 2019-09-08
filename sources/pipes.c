/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:40:59 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/08 18:46:25 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void     fill_diagonal_types(t_lemin *lemin)
{
	int	        i;
    t_room      *tmp;

	tmp = lemin->amount_of_rooms;
	i = 0;
	while (lemin->amount_of_rooms)
	{
		lemin->pipes[i][i] = lemin->amount_of_rooms->type;
		lemin->amount_of_rooms = lemin->amount_of_rooms->next;
		i++;
	}
	lemin->amount_of_rooms = tmp;
}

static void		fill_tab_pipes(t_lemin *lemin, t_lst **ptr)
{
	char        **split;

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

static int      find_right_rooms(char **matrix, int aim)
{
	int         i;

	i = 0;
	while (matrix[i][i] != aim)
		i++;
	return (i);
}

static int      amount_of_rooms(t_room *amount_of_rooms)
{
	int         i;

	i = 0;
	while (amount_of_rooms && ++i)
		amount_of_rooms = amount_of_rooms->next;
	return (i);
}

bool			remember_pipes(t_lst **list, t_lemin *lemin)
{
	int		    nb_rooms;
	int		    i;
	bool	    has_one_pipe;

	i = -1;
	has_one_pipe = false;
	nb_rooms = amount_of_rooms(lemin->amount_of_rooms);
	lemin->pipes = ft_memalloc(sizeof(char*) * (nb_rooms + 1));
	while (++i < nb_rooms)
	{
		lemin->pipes[i] = ft_memalloc(sizeof(char) * (nb_rooms + 1));
		ft_memset(lemin->pipes[i], NORM, sizeof(char) * (nb_rooms));
	}
	lemin->size_of_graph = nb_rooms;
	fill_diagonal_types(lemin);
	fill_tab_pipes(lemin, list);
	lemin->begin = find_right_rooms(lemin->pipes, BEGIN);
	lemin->finish = find_right_rooms(lemin->pipes, FINISH);
	while (--i >= 0 && !has_one_pipe)
		if (!has_one_pipe)
			has_one_pipe = !(!ft_strchr(lemin->pipes[i], LINKED));
	return (has_one_pipe);
}