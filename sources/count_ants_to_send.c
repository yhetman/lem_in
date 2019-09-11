/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ants_to_send.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:10:05 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/11 21:00:23 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static bool     case_one_ant(t_lemin *lemin, t_send *sender)
{
	int	i;

	i = -1;
	while (++i < lemin->flow)
	{
		if (sender->fastest == sender->len_of_path[i])
		{
			sender->ants[i] = 1;
			return (true);
		}
	}
	return (false);
}

static int		count_required_lines(t_send *sender, t_lemin *lemin)
{
	int	result;
	int	i;

	i = -1;
	result = 0;
	while (++i < lemin->flow)
		result = sender->len_of_path[i] + sender->ants[i] > result
			? sender->len_of_path[i] + sender->ants[i] : result;
	return (result);
}

static int		depart_extra_ants(t_lemin *lemin, t_send *sender, int to_add)
{
	int	i;
	int	lines;

	if (lemin->ants == 1)
		if (case_one_ant(lemin, sender))
			return (0);
	while (to_add > 0)
	{
		lines = count_required_lines(sender, lemin);
		i = -1;
		while (++i < lemin->flow)
		{
			if (sender->len_of_path[i] + sender->ants[i] <= lines)
			{
				sender->ants[i]++;
				to_add--;
				if (to_add == 0)
					break ;
			}
		}
	}
	return (0);
}
static int		too_many_ants_sent(t_lemin *lemin, t_send *sender, int to_subtract)
{
	int	i;

	while (to_subtract > 0)
	{
		i = -1;
		while (++i < lemin->flow)
		{
			if (sender->ants[i] > 0)
			{
				sender->ants[i]--;
				to_subtract--;
			}
		}
	}
	return (-to_subtract);
}

void	count_ants_to_send(t_lemin *lemin, t_send *sender)
{
	int	avg;
	int	ants_remaining;
	int	i;
	int	ants_avg;

	ants_avg = lemin->ants / lemin->flow;
	i = -1;
	avg = 0;
	ants_remaining = lemin->ants;
	while (++i < lemin->flow)
		avg += sender->len_of_path[i];
	avg /= lemin->flow;
	i = -1;
	while (++i < lemin->flow)
	{
		sender->ants[i] = ants_avg - (sender->len_of_path[i] - avg);
		if (sender->ants[i] < 0)
			sender->ants[i] = 0;
		ants_remaining -= sender->ants[i];
	}
	if (ants_remaining < 0)
		ants_remaining = too_many_ants_sent(lemin, sender, -ants_remaining);
	i = -1;
	if (ants_remaining)
		ants_remaining = depart_extra_ants(lemin, sender, ants_remaining);
}
