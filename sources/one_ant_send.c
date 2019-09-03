/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_ant_send.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 21:25:27 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/03 15:49:56 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static char	    *check_room_name(t_lemin *lemin, int amount_of_rooms)
{
	t_room *tmp_rooms;

	tmp_rooms = lemin->amount_of_rooms;
	while (amount_of_rooms--)
		tmp_rooms = tmp_rooms->next;
	return (tmp_rooms->name);
}


static int		next_peak(t_lst *peak)
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

int		    length_of_the_way(t_array_of_lists graph, int src, int depth)
{
	int		len;
	t_lst	*peak;

	len = 1;
	peak = (graph)[src];
	while (peak != (graph)[depth])
	{
		len++;
		peak = (graph)[next_peak(peak)];
	}
	return (len);
}

static int		another_way(t_send *sender)
{
	t_path	elem;
	t_lst	*ptr;

	ptr = sender->congestion->next;
	ft_memcpy(&elem, sender->congestion->content, sender->congestion->content_size);
	ft_lstdelone(&sender->congestion, &ft_free_node);
	sender->congestion = ptr;
	if (sender->ants[elem.sender] > 0)
	{
		sender->ants[elem.sender]--;
		ft_lst_last_in(&sender->congestion, ft_lstnew(&elem, sizeof(t_path)));
	}
	else
		sender->flow--;
	return (elem.traffic->depth);
}

bool		    send_one_ant(t_lst *peak, t_lemin *l, int i, t_send *s)
{
	int			way;
	bool		wait;

	wait = (s->positions[i] == l->begin);
	((l->flow > 1 && wait) ? (way = another_way(s)) : (way = next_peak(peak)));
    ft_printf("%s%d%c%s", "L", i + 1, '-', check_room_name(l, way));
    (i + 1 == s->departed) ? 0 : ft_putchar(' ');
	s->positions[i] = way;
	return ((way == l->finish) ? true : false);
}
