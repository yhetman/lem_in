/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_length_of_paths.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:03:20 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/12 20:35:57 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		next_top(t_lst *node)
{
	t_dead_end	*bridge;

	bridge = (t_dead_end*)(node->content);
	while (bridge->flow != 1)
	{
		node = node->next;
		bridge = (t_dead_end*)(node->content);
	}
	return (bridge->depth);
}

static int		one_path_length(t_array_of_lists map, int n, int depth)
{
	int			length;
	t_lst		*node;

	length = 1;
	node = (map)[n];
	while (node != (map)[depth])
	{
		length++;
		node = (map)[next_top(node)];
	}
	return (length);
}

int				*check_length_of_paths(t_array_of_lists map, t_lemin *lemin)
{
	int			*len;
	int			i;
	t_lst		*from_beg;
	t_dead_end	*node;

	len = ft_memalloc(sizeof(int) * lemin->flow);
	i = 0;
	from_beg = map[lemin->begin];
	while (i < lemin->flow)
	{
		node = (t_dead_end*)from_beg->content;
		if (node->flow == 1)
		{
			len[i] = one_path_length(map, node->depth, lemin->finish);
			i++;
		}
		from_beg = from_beg->next;
	}
	return (len);
}
