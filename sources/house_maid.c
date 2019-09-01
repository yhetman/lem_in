/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   house_maid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:42:13 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/01 21:17:02 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	room_maid(t_room **head)
{
	t_room	*tmp;
	t_room	*ptr;

	ptr = *head;
	while (ptr)
	{
		tmp = ptr->next;
		ft_strdel(&ptr->name);
		ft_memdel((void**)&ptr);
		ptr = tmp;
	}
}

void	clean_double_array(char **split)
{
	char	**tmp;
	char	**ptr;

	if (!split)
		return ;
	tmp = split;
	ptr = split;
	while (*split)
	{
		tmp = split + 1;
		ft_strdel(split);
		split = tmp;
	}
	ft_memdel((void**)&ptr);
}

void	clean_lem_in(t_lemin *addr)
{
	ft_strdel(&addr->begin_name);
	ft_strdel(&addr->finish_name);
	room_maid(&(addr)->amount_of_rooms);
	clean_double_array(addr->pipes);
}
