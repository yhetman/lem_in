/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shut_down_lemin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:58:12 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/11 22:17:30 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


static void clean_rooms(t_room **list)
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

static void	clean_links(char **split)
{
	char	**temp;
	char	**ptr;

	if (!split)
		return ;
	temp = split;
	ptr = split;
	while (*split)
	{
		temp = split + 1;
		ft_strdel(split);
		split = temp;
	}
	ft_memdel((void**)&ptr);
}

void		shut_down_lemin(t_lst **list, t_lemin *lemin,
			const char *err_mssg, int exit_code)
{
	ft_lstdel(list, &ft_free_node);
	ft_strdel(&lemin->start_name);
	ft_strdel(&lemin->end_name);
	clean_rooms(&(lemin)->amount_of_rooms);
	clean_links(lemin->pipes);
	ft_putstr_fd(err_mssg, STD_ERR);
	exit(exit_code);
}
