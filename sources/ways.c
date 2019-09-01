/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:20:41 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/01 22:24:50 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static bool	case_one_ant(t_lemin *lemin, t_send *sender)
{
	int	i;

	i = -1;
	while (++i < lemin->flow)
		if (sender->fastest == sender->len_of_path[i])
		{
			sender->ants[i] = 1;
			return (true);
		}
	return (false);
}

static int		count_lines(t_send *sender, t_lemin *lemin)
{
	int	ret;
	int	i;

	i = -1;
	ret = 0;
	while (++i < lemin->flow)
		ret = sender->len_of_path[i] + sender->ants[i] > ret ?
		sender->len_of_path[i] + sender->ants[i] : ret;
	return (ret);
}

static int		reorganize_ants(t_lemin *lemin, t_send *sender, int to_add)
{
	int	i;
	int	lines;

	if (lemin->amount_of_ants == 1)
		if (case_one_ant(lemin, sender))
			return (0);
	while (to_add > 0)
	{
		lines = count_lines(sender, lemin);
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

static int		overflow_of_ants(t_lemin *lemin, t_send *sender, int to_subtract)
{
	int	i;

	while (to_subtract > 0)
	{
		i = -1;
		while (++i < lemin->flow)
			if (sender->ants[i]-- > 0)
				to_subtract--;
	}
	return (-to_subtract);
}

void	amount_to_depart(t_lemin *lemin, t_send *sender)
{
	int	avg;
	int	ants_remaining;
	int	i;
	int	ants_avg;

	ants_avg = lemin->amount_of_ants / lemin->flow;
	i = -1;
	avg = 0;
	ants_remaining = lemin->amount_of_ants;
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
		ants_remaining = overflow_of_ants(lemin, sender, -ants_remaining);
	if (ants_remaining)
		ants_remaining = reorganize_ants(lemin, sender, ants_remaining);
}
