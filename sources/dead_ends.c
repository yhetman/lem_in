/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_ends.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:32:00 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:31:29 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/lem_in.h"

void			output_ends(t_lst *elem)
{
	output_dead_ends((t_dead_end*)(elem->content));
}

void			step_to_end(t_dead_end *dead_end)
{
	dead_end->flow += 1;
	dead_end->reverse->flow -= 1;
}
