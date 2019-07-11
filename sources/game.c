/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:51:58 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/11 21:52:29 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_ant(t_lemin *lemin, t_ant *ant, t_room *room)
{
	if (!lemin->param.debug)
	{
		ft_putchar_fd('L', FT_STD_OUT);
		ft_putnbr_fd(ant->id, FT_STD_OUT);
		ft_putchar_fd('-', FT_STD_OUT);
		ft_putstr_fd(ant->room->name, FT_STD_OUT);
		ft_putchar_fd(' ', FT_STD_OUT);
	}
	else
		lemin_debug(lemin, lemin->ant_list, room);
	return ;
}


static void	move_ants(t_lemin *lemin, t_ant *ant, t_room *room)
{
	ant->room->has_ant = 0;
	ant->last = ant->room;
	ant->room = room;
	ant->room->has_ant = 1;
	print_ant(lemin, ant, room);
	lemin->moves += 1;
	return ;
}

void		lemin_play(t_lemin *lemin)
{
	int		result;
	int		distance;
	t_list	*ls;
	t_room	*tmp;
	t_room	*next;

	distance = FT_INT_MAX;
	ls = lemin->ant_list->room->paths;
	while (ls)
	{
		tmp = (t_room *)ls->content;
		if ((tmp->flag == ENDROOM || !tmp->has_ant) \
				&& tmp != lemin->ant_list->last)
		{
			result = find_room(tmp, ENDROOM);
			if (result < distance && result > -1)
			{
				distance = result;
				next = tmp;
			}
		}
		ls = ls->next;
	}
	if (distance < FT_INT_MAX)
		move_ants(lemin, lemin->ant_list, next);
}
