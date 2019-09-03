/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_fulkerson.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:31:32 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/03 20:46:25 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/lem_in.h"

static void			step_to_end(t_dead_end *dead_end)
{
	dead_end->flow += 1;
	dead_end->reverse->flow -= 1;
}

static void			bfs_step(t_dead_end ***path, t_lst **congestion,
					t_lst **graph, int src)
{
	t_lst		*current_vertex;
	t_dead_end	*dead_end;
	int			vertex_no;
	t_lst		*tmp;

	vertex_no = *(int*)(*congestion)->content;
	current_vertex = graph[vertex_no];
	while (current_vertex)
	{
		dead_end = (t_dead_end*)current_vertex->content;
		if (!((*path)[dead_end->depth]) && dead_end->depth != src
		&& dead_end->flow < 1)
		{
			(*path)[dead_end->depth] = dead_end;
			ft_lst_last_in(congestion, ft_lstnew(&dead_end->depth, sizeof(int)));
		}
		current_vertex = current_vertex->next;
	}
	tmp = (*congestion)->next;
	ft_lstdelone(congestion, &ft_free_node);
	*congestion = tmp;
}

static t_dead_end		**bfs(t_array_of_lists graph, int src,
						int depth, int size)
{
	t_dead_end			**path;
	t_lst				*congestion;

	path = ft_memalloc(sizeof(t_dead_end*) * size);
	congestion = ft_lstnew(&src, sizeof(int));
	while (congestion)
		bfs_step(&path, &congestion, graph, src);
	if (!path[depth])
	{
		ft_memdel((void**)&path);
		return (NULL);
	}
	return (path);
}

static bool				flow_through_path(t_array_of_lists graph,
						t_dead_end **path, int start, int end)
{
	t_dead_end			*dead_end;
	bool				super;

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

int						ford_fulkerson(t_array_of_lists graph, t_lemin *lemin,int stop)
{
	t_dead_end			**path;
	int					ret;
	int					tmp;
	int					min;

	min = INT_MAX;
	ret = 0;
	while (stop != lemin->flow && (path = bfs(graph,
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
