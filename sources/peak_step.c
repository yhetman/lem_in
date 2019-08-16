/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peak_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 13:11:59 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:38:00 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				peak_step(t_lst *peak)
{
	int		count;
	t_dead_end	*dead_end;

	count = 0;
	while (peak)
	{
		dead_end = ((t_dead_end*)(peak->content))->reverse;
		if (DEBUG)
			ft_printf("\t...now looking at %d->%d. Flow %d.\n", dead_end->src, \
dead_end->depth, dead_end->flow);
		if (dead_end->flow == 1)
			count++;
		peak = peak->next;
	}
	return (count);
}
