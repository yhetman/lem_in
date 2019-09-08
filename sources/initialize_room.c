/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:30:34 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/08 18:36:12 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room			*initialize_room(char *name_ptr, char type,
                t_coord *coord, int ant_amount)
{
	t_room	*newest;

	newest = ft_memalloc(sizeof(t_room));
	newest->coord.x = coord->x;
	newest->coord.y = coord->y;
	newest->name = name_ptr;
	newest->type = type;
	if (type == BEGIN)
		newest->ant_amount = ant_amount;
	else
		newest->ant_amount = 0;
	newest->next = NULL;
	return (newest);
}