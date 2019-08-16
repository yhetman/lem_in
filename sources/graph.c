/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:46:50 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:42:25 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static inline void	fill_edge(t_dead_end *dead_end, int src, int depth)
{
	dead_end->src = src;
	dead_end->depth = depth;
	dead_end->flow = 0;
	dead_end->reverse = NULL;
}

static void			add_connections_to_graph(t_lst **peak, 
					int vtx_nb, char *links)
{
	t_dead_end	tmp;
	int		i;

	i = 0;
	while (links[i])
	{
		if (links[i] == LINKED)
		{
			fill_edge(&tmp, vtx_nb, i);
			ft_lstadd(peak, ft_lstnew(&tmp, sizeof(t_dead_end)));
		}
		i++;
	}
}

static void			hook_up_rev_edges(t_lst **graph, int vertices)
{
	t_lst	*list;
	t_lst	*to_top;
	int		i;
	int		deads;

	i = 0;
	while (i < vertices)
	{
		list = graph[i];
		while (list)
		{
			if (((t_dead_end*)(list->content))->reverse == NULL)
			{
				deads = ((t_dead_end*)(list->content))->depth;
				to_top = graph[deads];
				while (((t_dead_end*)(to_top->content))->depth != i)
					to_top = to_top->next;
				((t_dead_end*)to_top->content)->reverse = (t_dead_end*)list->content;
				((t_dead_end*)list->content)->reverse = (t_dead_end*)to_top->content;
			}
			list = list->next;
		}
		i++;
	}
}

t_array_of_lists			construct_this_sht(t_lemin *lemin)
{
	int			vertices;
	char		**connections_matrix;
	t_array_of_lists	graph;
	int			i;

	vertices = lemin->size_of_graph;
	connections_matrix = lemin->pipes;
	graph = ft_memalloc(sizeof(t_lst*) * (vertices + 1));
	i = 0;
	while (i < vertices)
	{
		add_connections_to_graph(&graph[i], i, connections_matrix[i]);
		i++;
	}
	hook_up_rev_edges(graph, vertices);
	return (graph);
}
