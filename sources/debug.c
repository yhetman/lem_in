/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:51:01 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/11 21:51:39 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		lemin_debug(t_lemin *lemin, t_ant *ant, t_room *room)
{
	int		i;

	i = -1;
	usleep(DEBUG_SLEEP);
	ft_printf("\n\n");
	while (++i < ANT_HEIGHT)
	ft_printf("\n");
	ft_printf("Ant  id   : %{yellow}%d%{eoc}\n", ant->id);
	ft_printf("Room name : %{red}%d%{eoc}\n", room->flag);
	ft_printf("Room flag : %{red}%d%{eoc}\n", room->flag);
	ft_printf("L%{yellow}%d%{eoc}-%{red}%s%{eoc} \n", ant->id, ant->room->name);
	lemin->param.debug += 1;
	return ;
}
