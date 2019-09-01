/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:50:59 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/01 22:07:05 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


static int		count_steps(t_send *sender, int flow)
{
	int	i;
	int res;

	res = 0;
	i = -1;
	while (++i < flow)
	{
		if (sender->ants[i] > 0)
			res++;
	}
	return (res);
}

static t_lst		*without_congestion(t_send *sender, t_lst *beg_point, int flow)
{
	t_lst	*congestion;
	int		i;
	t_path	path;

	i = 0;
	congestion = NULL;
	while (true)
	{
		while (i < flow && sender->ants[i] == 0)
			i++;
		while (beg_point && ((t_dead_end*)(beg_point)->content)->flow == 0)
			beg_point = beg_point->next;
		if (i == flow || !beg_point)
			break ;
		path.traffic = ((t_dead_end*)(beg_point)->content);
		path.sender = i;
		ft_lst_last_in(&congestion, ft_lstnew(&path, sizeof(path)));
		i++;
		beg_point = beg_point->next;
	}
	return (congestion);
}

static void		initialize_sending(t_send *sender, t_lemin *lemin, t_lst **graph)
{
	ft_bzero(sender, sizeof(t_send));
	sender->positions = ft_memalloc(sizeof(int) * (lemin->amount_of_ants));
	sender->len_of_path = size_of_the_way(graph, lemin);
	sender->fastest = ft_min_arr(sender->len_of_path, lemin->flow);
	sender->ants = ft_memalloc(sizeof(int) * lemin->flow);
	amount_to_depart(lemin, sender);
	sender->flow = count_steps(sender, lemin->flow);
	delete_dead_ends(sender, (graph)[lemin->begin], lemin->flow);
	sender->congestion = without_congestion(sender, graph[lemin->begin], lemin->flow);
}

static void		clean_sending(t_send *sender)
{
	ft_memdel((void**)&sender->ants);
	ft_memdel((void**)&sender->len_of_path);
	ft_lstdel(&sender->congestion, &ft_free_node);
	ft_memdel((void**)&sender->positions);
}

void			send_ants(t_array_of_lists graph, t_lemin *lemin)
{
	int			i;
	t_send		sender;

	initialize_sending(&sender, lemin, graph);
	i = -1;
	while (++i < lemin->amount_of_ants)
		sender.positions[i] = lemin->begin;
	while (sender.arrived < lemin->amount_of_ants)
	{
		if (sender.departed < lemin->amount_of_ants)
			sender.departed += sender.flow;
		i = -1;
		while (++i < sender.departed && i < lemin->amount_of_ants)
		{
			delete_dead_ends(&sender, (graph)[lemin->begin], lemin->flow);
			if (sender.positions[i] != lemin->finish)
				sender.arrived += send_one_ant(graph[sender.positions[i]], lemin, i, &sender);
		}
		ft_putchar_fd('\n', STD_OUT);
	}
	clean_sending(&sender);
}
