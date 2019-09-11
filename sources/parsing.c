/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:07:17 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/11 19:57:11 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		output_buffer(t_lst *node)
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


static void			clean_rooms(t_room **list)
{
	t_room	*temp;
	t_room	*ptr;

	ptr = *list;
	while (ptr)
	{
		temp = ptr->next;
		ft_strdel((char**)&ptr->name);
		ft_memdel((void**)&ptr);
		ptr = temp;
	}
}

void				shut_down_lemin(t_lst **list, t_lemin *lemin,
					const char *err_mssg, int exit_code)
{
	ft_lstdel(list, &ft_free_node);
	ft_strdel(&lemin->start_name);
	ft_strdel(&lemin->end_name);
	clean_rooms(&(lemin)->amount_of_rooms);
	clean_pipes(lemin->pipes);
	ft_putstr_fd(err_mssg, STD_ERR);
	exit(exit_code);
}

static inline bool	remember_ants(t_lst **list, int *ants)
{
	while (((char*)(*list)->content)[0] == HASH)
	{
		if (ft_strequ((char*)(*list)->content, START)
				|| ft_strequ((char*)(*list)->content, END))
			return (false);
		(*list) = (*list)->next;
	}
	if (IS_INT((char*)(*list)->content))
	{
		*ants = ft_atoi((char*)(*list)->content);
		return((*ants >= 0) ? true : false);
	}
	else
		return (false);
}


void				parsing(t_lst **input, t_lst **tmp,
					t_lemin *lemin)
{
	if (!(*input))
		shut_down_lemin(tmp, lemin, "ERROR OCCURED: incorrect input.\n", FAIL);
	if (!(remember_ants(input, &lemin->ants)))
		shut_down_lemin(tmp, lemin, "ERROR OCCURED: invalid input of ants.\n", FAIL);
	*input = (*input)->next;
	remember_rooms(input, lemin);
	if (!lemin->amount_of_rooms)
		shut_down_lemin(tmp, lemin, "ERROR OCCURED: invalid rooms' declaration.\n", FAIL);
	if (!lemin->start_name)
		shut_down_lemin(tmp, lemin, "ERROR OCCURED: map has no start room.\n", FAIL);
	if (!lemin->end_name)
		shut_down_lemin(tmp, lemin, "ERROR OCCURED: map has no end room.\n", FAIL);
	if (!remember_pipes(input, lemin))
		shut_down_lemin(tmp, lemin, "ERROR OCCURED: wrong pipes' declaration.\n", FAIL);
	output_buffer(*tmp);
}
