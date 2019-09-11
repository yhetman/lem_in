/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_fulkerson.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:59:01 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/11 19:02:03 by yhetman          ###   ########.fr       */
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
		//if (DEBUG)
		//	ft_printf("\t...now looking at %d->%d. Flow %d.\n", dead->src, dead->depth, dead->flow);
		if (dead->flow == 1)
			count++;
		node = node->next;
	}
	return (count);
}

static void			reverse_step(t_dead_end *edge)
{
	edge->flow += 1;
	edge->reverse->flow -= 1;
}

static bool					ants_to_one_path(t_array_of_lists map,
				t_dead_end **path, int start, int end)
{
	t_dead_end	*dead;
	bool		jam;

	jam = false;
	dead = path[end];
	reverse_step(dead);
	if (dead->src == start)
		return (false);
	dead = path[dead->src];
	while (dead->src != start && !jam)
	{
		reverse_step(dead);
		if ((jam = jam_appearing(map[dead->depth]) > 1))
			break ;
		dead = path[dead->src];
	}
	reverse_step(dead);
	return (jam);
}

int						ford_fulkerson(t_array_of_lists map, t_lemin *lemin, int stop)
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
			tmp = print_path_analysis(map, lemin);
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