/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peak_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 13:11:59 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/01 22:09:45 by yhetman          ###   ########.fr       */
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
		if (dead_end->flow == 1)
			count++;
		peak = peak->next;
	}
	return (count);
}
