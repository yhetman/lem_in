/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construstor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:21:21 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/09 18:24:04 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void         initialize_nodes(t_dead_end *edge, int src, int depth)
{
	edge->src = src;
	edge->depth = depth;
	edge->flow = 0;
	edge->reverse = NULL;
}

static void			linking_the_nodes(t_lst **nodes, int count, char *links)
{
	t_dead_end	tmp;
	int		i;

	i = -1;
	while (links[++i])
	{
		if (links[i] == LINKED)
		{
			initialize_nodes(&tmp, count, i);
			ft_lst_last_in(nodes, ft_lstnew(&tmp, sizeof(t_dead_end)));
		}
	}
}

static void			reverse_nodes(t_lst **map, int apex)
{
	t_lst	*normal;
	t_lst	*reversed;
	int		i;
	int		curr;

	i = -1;
	while (++i < apex)
	{
		normal = map[i];
		while (normal)
		{
			if (((t_dead_end*)(normal->content))->reverse == NULL)
			{
				curr = ((t_dead_end*)(normal->content))->depth;
				reversed = map[curr];
				while (((t_dead_end*)(reversed->content))->depth != i)
					reversed = reversed->next;
				((t_dead_end*)reversed->content)->reverse = (t_dead_end*)normal->content;
				((t_dead_end*)normal->content)->reverse = (t_dead_end*)reversed->content;
			}
			normal = normal->next;
		}
	}
}

t_array_of_lists	construstor(t_lemin *lemin)
{
	int			apex;
	char		**connections_matrix;
	t_array_of_lists	map;
	int			i;

	apex = lemin->size_of_graph;
	connections_matrix = lemin->pipes;
	map = ft_memalloc(sizeof(t_lst*) * (apex + 1));
	i = -1;
	while (++i < apex)
		linking_the_nodes(&map[i], i, connections_matrix[i]);
	reverse_nodes(map, apex);
	return (map);
}