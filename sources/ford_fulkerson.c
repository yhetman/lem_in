/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_fulkerson.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:59:01 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/11 19:47:37 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		jam_appearing(t_lst *node)
{
	int			count;
	t_dead_end	*dead;

	count = 0;
	while (node)
	{
		dead = ((t_dead_end*)(node->content))->reverse;
		if (dead->flow == 1)
			count++;
		node = node->next;
	}
	return (count);
}

static bool			ants_to_one_path(t_array_of_lists map,
				t_dead_end **path, int start, int end)
{
	t_dead_end	*dead;
	bool		jam;

	jam = false;
	dead = path[end];
    dead->flow += 1;
    dead->reverse->flow -= 1;
	if (dead->src == start)
		return (false);
	dead = path[dead->src];
	while (dead->src != start && !jam)
	{
		dead->flow += 1;
        dead->reverse->flow -= 1;
		if ((jam = jam_appearing(map[dead->depth]) > 1))
			break ;
		dead = path[dead->src];
	}
	dead->flow += 1;
    dead->reverse->flow -= 1;
	return (jam);
}

static void					bfs_step(t_dead_end ***path, t_lst **traffic_jam, t_lst **map, int src)
{
	t_lst	*curr;
	t_dead_end	*dead;
	int		point;
	t_lst	*tmp;

	point = *(int*)(*traffic_jam)->content;
	curr = map[point];
	while (curr)
	{
		dead = (t_dead_end*)curr->content;
		if (!((*path)[dead->depth]) && dead->depth != src && dead->flow < 1)
		{
			(*path)[dead->depth] = dead;
			ft_lst_last_in(traffic_jam, ft_lstnew(&dead->depth, sizeof(int)));
		}
		curr = curr->next;
	}
	tmp = (*traffic_jam)->next;
	ft_lstdelone(traffic_jam, &ft_free_node);
	*traffic_jam = tmp;
}

static int          analitics(t_array_of_lists graph, t_lemin *lemin)
{
	int		*lengths;
	int		avg_len;
	int		result;

	lengths = check_length_of_paths(graph, lemin);
	avg_len = ft_arr_len(lengths, lemin->flow);
	result = ((lemin->ants - 1) / lemin->flow + avg_len);
	ft_lstdel(&lemin->len_of_path, &ft_free_node);
	ft_memdel((void**)&lengths);
	return (result);
}

static t_dead_end		**bfs(t_array_of_lists map, int src, int depth, int size)
{
	t_dead_end	**path;
	t_lst		*traffic_jam;

	path = ft_memalloc(sizeof(t_dead_end*) * size);
	traffic_jam = ft_lstnew(&src, sizeof(int));
	while (traffic_jam)
		bfs_step(&path, &traffic_jam, map, src);
	if (!path[depth])
	{
		ft_memdel((void**)&path);
		return (NULL);
	}
	return (path);
}

int                 ford_fulkerson(t_array_of_lists map, t_lemin *lemin, int stop)
{
	t_dead_end	**path;
	int		result;
	int		tmp;
	int		min;

	min = INT_MAX;
	result = 0;
	while (stop != lemin->flow && (path = bfs(map,
		lemin->begin, lemin->finish, lemin->size_of_graph)))
	{
		if (ants_to_one_path(map, path, lemin->begin, lemin->finish))
			ft_memdel((void**)&path);
		else
		{
			lemin->flow++;
			tmp = analitics(map, lemin);
			if (tmp < min)
			{
				min = tmp;
				result = lemin->flow;
			}
			ft_memdel((void**)&path);
		}
	}
	return (result);
}