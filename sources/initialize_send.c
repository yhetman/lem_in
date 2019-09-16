/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_send.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:54:22 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 15:28:06 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_lst	*solve_jam(t_send *sender, t_lst *start_node, int flow, int i)
{
	t_lst		*traffic_jam;
	t_path		trajectory;

	traffic_jam = NULL;
	while (1)
	{
		while (i < flow && sender->ants[i] == 0)
			i++;
		while (start_node && ((t_dead_end*)(start_node)->content)->flow == 0)
			start_node = start_node->next;
		if (i == flow || !start_node)
			break ;
		trajectory.traffic = ((t_dead_end*)(start_node)->content);
		trajectory.post_code = i;
		ft_lst_last_in(&traffic_jam, ft_lstnew(&trajectory, sizeof(t_path)));
		i++;
		start_node = start_node->next;
	}
	return (traffic_jam);
}

static void		cut_off_deads(t_send *sender, t_lst *beg, int flow)
{
	int			i;

	i = -1;
	while (++i < flow && beg)
	{
		while (beg && (((t_dead_end*)(beg->content))->flow == 0))
			beg = beg->next;
		if (i == flow || !beg)
			break ;
		((!sender->ants[i] && ((t_dead_end*)(beg->content))->flow)
			? (((t_dead_end*)(beg->content))->flow = 0) : 0);
		((beg->next) ? beg = beg->next : 0);
	}
}

static int		check_overflow(t_send *sender, int flow)
{
	int			i;
	int			res;

	res = 0;
	i = -1;
	while (++i < flow)
	{
		if (sender->ants[i] > 0)
			res++;
	}
	return (res);
}

void			initialize_send(t_send *sender, t_lemin *lemin, t_lst **map)
{
	ft_bzero(sender, sizeof(t_send));
	sender->positions = ft_memalloc(sizeof(int) * (lemin->ants));
	sender->len_of_path = check_length_of_paths(map, lemin);
	sender->fastest = ft_min_arr(sender->len_of_path, lemin->flow);
	sender->ants = ft_memalloc(sizeof(int) * lemin->flow);
	count_ants_to_send(lemin, sender);
	sender->flow = check_overflow(sender, lemin->flow);
	cut_off_deads(sender, (map)[lemin->begin], lemin->flow);
	sender->traffic_jam = solve_jam(sender, map[lemin->begin], lemin->flow, 0);
}
