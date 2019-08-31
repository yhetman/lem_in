/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:41:08 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/31 21:22:37 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			shut_the_f_up(t_lst **lst, t_lemin *lemin, const char *err, int status)
{
	ft_lstdel(lst, &ft_free_node);
	clean_lem_in(lemin);
	ft_putstr_fd(err, STDERR_FILENO);
	exit(status);
}

bool			remember_each_f_ant(t_lst **head, int *leminants)
{
	while (((char*)(*head)->content)[0] == '#')
	{
		if (ft_strequ((char*)(*head)->content, "##start")
				|| ft_strequ((char*)(*head)->content, "##end"))
			return (false);
		(*head) = (*head)->next;
	}
	if (IS_INT((char*)(*head)->content))
	{
		*leminants = ft_atoi((char*)(*head)->content);
		if (DEBUG > 1)
			ft_printf("DEBUG: Stored %d ant%c.\n", *leminants, *leminants > 1 ? 's' : 0);
		if (*leminants >= 0)
			return (true);
		else
			return (false);
	}
	else
		return (false);
}

static bool		map_has_in_out(t_lemin *lemin)
{
	if (DEBUG > 1)
		ft_printf("DEBUG: Start room: \"%s\", end room: \"%s\".\n",
				lemin->begin_name, lemin->finish_name);
	return (lemin->begin_name && lemin->finish_name);
}

void			parsing(t_lst **input, t_lst **tmp, t_lemin *lemin)
{
	if (!(*input))
		shut_the_f_up(tmp, lemin, "ERROR: No arguments.\n", EXIT_FAILURE);
	if (!(remember_each_f_ant(input, &lemin->amount_of_ants)))
		shut_the_f_up(tmp, lemin, "ERROR: Invalid number of amount_of_ants.\n", \
				EXIT_FAILURE);
	*input = (*input)->next;
	remember_rooms(input, lemin);
	if (!lemin->amount_of_rooms || !map_has_in_out(lemin))
		shut_the_f_up(tmp, lemin, "ERROR: Map error.\n", EXIT_FAILURE);
	if (DEBUG > 1)
	{
		output_rooms(lemin->amount_of_rooms);
		ft_printf("DEBUG: All amount_of_rooms are stored. Processing pipes.\n");
	}
	if (!remember_pipes(input, lemin))
		shut_the_f_up(tmp, lemin, "ERROR: No pipes.\n", EXIT_FAILURE);
}
