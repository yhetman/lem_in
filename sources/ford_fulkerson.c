/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_fulkerson.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:31:32 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/31 21:44:49 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/lem_in.h"

static inline bool	edge_is_valid(t_dead_end *dead_end, t_dead_end **path, int src)
{
	if (!((path)[dead_end->depth]) && dead_end->depth != src && dead_end->flow < 1)
		return (true);
	else
		return (false);
}

void					bfs_step(t_dead_end ***path, t_lst **congestion, \
t_lst **graph, int src)
{
	t_lst	*current_vertex;
	t_dead_end	*dead_end;
	int		vertex_no;
	t_lst	*tmp;

	vertex_no = *(int*)(*congestion)->content;
	current_vertex = graph[vertex_no];
	if (DEBUG > 3)
		ft_printf("\tVisiting peak %d.\n", vertex_no);
	while (current_vertex)
	{
		dead_end = (t_dead_end*)current_vertex->content;
		if (edge_is_valid(dead_end, *path, src))
		{
			(*path)[dead_end->depth] = dead_end;
			ft_lst_last_in(congestion, ft_lstnew(&dead_end->depth, sizeof(int)));
			if (DEBUG > 3)
				ft_printf("\t\tEnqueued peak %d,\n", dead_end->depth);
		}
		current_vertex = current_vertex->next;
	}
	tmp = (*congestion)->next;
	ft_lstdelone(congestion, &ft_free_node);
	*congestion = tmp;
}

t_dead_end					**bfs(t_array_of_lists graph, int src, \
int depth, int size)
{
	t_dead_end	**path;
	t_lst	*congestion;

	path = ft_memalloc(sizeof(t_dead_end*) * size);
	congestion = ft_lstnew(&src, sizeof(int));
	if (DEBUG > 2)
		ft_putendl("DEBUG: Commencing breadth-first search.");
	while (congestion)
		bfs_step(&path, &congestion, graph, src);
	if (DEBUG > 2 && path[depth])
		ft_printf("DEBUG: BFS done. path[depth] flows from %d to %d.", \
path[depth]->src, path[depth]->depth);
	if (!path[depth])
	{
		ft_memdel((void**)&path);
		return (NULL);
	}
	return (path);
}

bool					flow_through_path(t_array_of_lists graph, \
		t_dead_end **path, int start, int end)
{
	t_dead_end	*dead_end;
	bool	super;

	super = false;
	dead_end = path[end];
	step_to_end(dead_end);
	if (dead_end->src == start)
		return (false);
	dead_end = path[dead_end->src];
	while (dead_end->src != start && !super)
	{
		step_to_end(dead_end);
		if ((super = peak_step(graph[dead_end->depth]) > 1))
			break ;
		dead_end = path[dead_end->src];
	}
	step_to_end(dead_end);
	return (super);
}

int						ford_fulkerson(t_array_of_lists graph, t_lemin *lemin, \
		int stop)
{
	t_dead_end	**path;
	int		ret;
	int		tmp;
	int		min;

	min = INT_MAX;
	ret = 0;
	while (stop != lemin->flow && (path = bfs(graph, \
					lemin->begin, lemin->finish, lemin->size_of_graph)))
	{
		if (flow_through_path(graph, path, lemin->begin, lemin->finish))
			ft_memdel((void**)&path);
		else
		{
			lemin->flow++;
			tmp = analysator(graph, lemin);
			if (tmp < min)
			{
				min = tmp;
				ret = lemin->flow;
			}
			ft_memdel((void**)&path);
		}
	}
	return (ret);
}
