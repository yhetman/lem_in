/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 07:55:45 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/03 20:30:20 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		amount_of_rooms_in_list(t_room *amount_of_rooms)
{
	int	i;

	i = 0;
	while (amount_of_rooms && ++i)
		amount_of_rooms = amount_of_rooms->next;
	return (i);
}

int		amount_of_splits(char **split)
{
	int		i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int		*size_of_the_way(t_array_of_lists graph, t_lemin *lemin)
{
	int		*app;
	int		i;
	t_lst	*edges_from_start;
	t_dead_end	*dead_end;

	app = ft_memalloc(sizeof(int) * lemin->flow);
	i = 0;
	edges_from_start = graph[lemin->begin];
	while (i < lemin->flow)
	{
		dead_end = (t_dead_end*)edges_from_start->content;
		if (dead_end->flow == 1)
			app[i++] = length_of_the_way(graph, dead_end->depth, lemin->finish);
		edges_from_start = edges_from_start->next;
	}
	return (app);
}

void	delete_dead_ends(t_send *sender, t_lst *start, int flow)
{
	int		i;

	i = 0;
	while (i < flow && start)
	{
		while (start && (((t_dead_end*)(start->content))->flow == 0))
			start = start->next;
		if (i == flow || !start)
			break ;
		if (!sender->ants[i] && ((t_dead_end*)(start->content))->flow)
			((t_dead_end*)(start->content))->flow = 0;
		i++;
		if (start->next)
			start = start->next;
	}
}

int	analysator(t_array_of_lists graph, t_lemin *lemin)
{
	int		*lengths;
	int		avg_len;
	int		ret;

	lengths = size_of_the_way(graph, lemin);
	avg_len = ft_arr_len(lengths, lemin->flow);
	ret = (lemin->amount_of_ants - 1 / lemin->flow + avg_len);
	ft_lstdel(&lemin->len_of_path, &ft_free_node);
	ft_memdel((void**)&lengths);
	return (ret);
}