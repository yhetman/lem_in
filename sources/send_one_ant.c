/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_one_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:53:56 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/11 22:17:27 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int				next_node(t_lst *node)
{
	t_dead_end	*dead;

	dead = (t_dead_end*)(node->content);
	while (dead->flow != 1)
	{
		node = node->next;
		dead = (t_dead_end*)(node->content);
	}
	return (dead->depth);
}

static int      alternative_way(t_send *sender)
{
	t_path      elem;
	t_lst       *ptr;

	ptr = sender->traffic_jam->next;
	ft_memcpy(&elem, sender->traffic_jam->content, sender->traffic_jam->content_size);
	ft_lstdelone(&sender->traffic_jam, &ft_free_node);
	sender->traffic_jam = ptr;
	if (sender->ants[elem.post_code] > 0)
	{
		sender->ants[elem.post_code]--;
		ft_lst_last_in(&sender->traffic_jam, ft_lstnew(&elem, sizeof(t_path)));
	}
	else
		sender->flow--;
	return (elem.traffic->depth);
}

static char			*check_guest_list(t_lemin *lemin, int room_nb)
{
	t_room *tmp_rooms;

	tmp_rooms = lemin->amount_of_rooms;
	while (room_nb--)
		tmp_rooms = tmp_rooms->next;
	return (tmp_rooms->name);
}

bool	send_one_ant(t_lst *node, t_lemin *lemin, int i, t_send *s)
{
	int		wait;
	bool	departed;

	departed = (s->positions[i] == lemin->begin);
	if (lemin->flow > 1 && departed)
	{
		wait = alternative_way(s);
	}
	else
		wait = next_node(node);
	ft_printf("%s%d%c%s", "L", i + 1, '-', check_guest_list(lemin, wait));
    (i + 1 == s->departed) ? 0 : ft_putchar_fd(' ', STD_OUT);
	s->positions[i] = wait;
	return ((wait == lemin->finish) ? true : false);
}