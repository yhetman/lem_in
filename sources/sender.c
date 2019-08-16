/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:50:59 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:38:12 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				count_steps(t_send *sender, int flow)
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

char			*check_room_name(t_lemin *lemin, int amount_of_rooms)
{
	t_room *tmp_rooms;

	tmp_rooms = lemin->amount_of_rooms;
	while (amount_of_rooms--)
		tmp_rooms = tmp_rooms->next;
	return (tmp_rooms->name);
}

int				next_peak(t_lst *peak)
{
	t_dead_end	*dead_end;

	dead_end = (t_dead_end*)(peak->content);
	while (dead_end->flow != 1)
	{
		peak = peak->next;
		dead_end = (t_dead_end*)(peak->content);
	}
	return (dead_end->depth);
}

static bool	send_one_ant(t_lst *vtx, t_lemin *lmn, int i, t_send *sendr)
{
	int		nvi;
	bool	on_start;

	on_start = (sendr->positions[i] == lmn->begin);
	if (lmn->flow > 1 && on_start)
	{
		nvi = another_way(sendr);
	}
	else
		nvi = next_peak(vtx);
	output_ants(i, check_room_name(lmn, nvi), \
			sendr->departed, lmn->ant_output);
	sendr->positions[i] = nvi;
	if (nvi == lmn->finish)
		return (true);
	else
		return (false);
}

void			send_ants(t_array_of_lists graph, t_lemin *lemin)
{
	int			i;
	t_send	sender;

	initialize_sending(&sender, lemin, graph);
	i = -1;
	while (++i < lemin->amount_of_ants)
		sender.positions[i] = lemin->begin;
	while (sender.arrived < lemin->amount_of_ants)
	{
		if (sender.departed < lemin->amount_of_ants)
			sender.departed += sender.flow;
		i = 0;
		while (i < sender.departed && i < lemin->amount_of_ants)
		{
			delete_dead_ends(&sender, (graph)[lemin->begin], lemin->flow);
			if (sender.positions[i] != lemin->finish)
				sender.arrived += send_one_ant(\
						graph[sender.positions[i]], lemin, i, &sender);
			i++;
		}
		ft_putchar('\n');
		if (DEBUG)
			output_ways(&sender, lemin->flow);
	}
	clean_sending(&sender);
}
