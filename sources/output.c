/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 08:20:47 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:56:00 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		output_buffer(t_lst *node)
{
	t_buffer	buffer;

	buffer.fd = 1;
	buffer.printed = 0;
	buffer.pos = 0;
	while (node)
	{
		ft_putstr_buff(&buffer, (char*)node->content);
		ft_putchr_buff(&buffer, '\n');
		node = node->next;
	}
	ft_flush_buff(&buffer);
}

void		output_ants(int i, char *room_name, int departed, char *display)
{
	ft_putstr(display);
	ft_putnbr(i + 1);
	ft_putchar('-');
	ft_putstr(room_name);
	(i + 1 == departed) ? 0 : ft_putchar(' ');
	if (!ft_strequ(display, "L"))
		ft_putstr("\e[0m");
}

void		output_rooms(t_room *map)
{
	int		i;
	char	*room_type;

	i = -1;
	if (DEBUG > 3)
		ft_putendl("DEBUG: Printing amount_of_rooms.");
	while (map)
	{
		if (map->type == FINISH)
			room_type = "FINISH";
		else if (map->type == BEGIN)
			room_type = "BEGIN";
		else
			room_type = "NORM";
		if (DEBUG > 3)
		{
			ft_putstr("DEBUG: ");
			ft_printf("\tRoom %d: \"%s\", type %s.\n", \
							++i, map->name, room_type);
		}
		map = map->next;
	}
}

void		output_ways(t_send *sender, int flow)
{
	int i;

	if (DEBUG)
	{
		ft_printf("DEBUG: Printing paths information...\n");
		i = -1;
		while (++i < flow)
			ft_printf("\tIn path %d of length %d, we'll send %d amount_of_ants.\n", i, \
		sender->len_of_path[i], sender->ants[i]);
	}
}

void		output_dead_ends(t_dead_end *dead_end)
{
	ft_printf("\tCurrent dead_end: %d->%d. Flow %d.\n", \
			dead_end->src, dead_end->depth, dead_end->flow);
}
