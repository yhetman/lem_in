/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:41:08 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/01 19:45:39 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void						shut_the_f_up(t_lst **lst, t_lemin *lemin, const char *err, int status)
{
	ft_lstdel(lst, &ft_free_node);
	clean_lem_in(lemin);
	ft_putstr_fd(err, STD_ERR);
	exit(status);
}

static inline bool			remember_each_f_ant(t_lst **head, int *ants)
{
	while (((char*)(*head)->content)[0] == HASH)
	{
		if (ft_strequ((char*)(*head)->content, START)
				|| ft_strequ((char*)(*head)->content, END))
			return (false);
		(*head) = (*head)->next;
	}
	if (IS_INT((char*)(*head)->content))
	{
		*ants = ft_atoi((char*)(*head)->content);
		return((*ants >= 0) ? true : false);
	}
	else
		return (false);
}

static inline bool		is_valid_map(t_lemin *lemin)
{
	return (lemin->begin_name && lemin->finish_name);
}

void			parsing(t_lst **input, t_lst **tmp, t_lemin *lemin)
{
	if (!(*input) || !(remember_each_f_ant(input, &lemin->amount_of_ants)))
		shut_the_f_up(tmp, lemin, "ERROR OCCURED: incorrect input.\n", FAIL);
	*input = (*input)->next;
	remember_rooms(input, lemin);
	if (!lemin->amount_of_rooms || !is_valid_map(lemin) || !remember_pipes(input, lemin))
		shut_the_f_up(tmp, lemin, "ERROR OCCURED: invalid map.\n", FAIL);
}
