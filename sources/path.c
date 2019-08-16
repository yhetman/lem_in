/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:40:50 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:37:56 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_coord	get_coord(char *input)
{
	int				i;
	char			**splitted;
	t_coord			coord;

	coord.x = 0;
	coord.y = 0;
	splitted = ft_strsplit(input, ' ');
	i = 0;
	while (splitted[i++])
		;
	if (i > 3)
	{
		coord.x = ft_atoi(splitted[i - 3]);
		coord.y = ft_atoi(splitted[i - 2]);
	}
	clean_double_array(splitted);
	return (coord);
}

t_lst	*without_congestion(t_send *sender, t_lst *beg_point, int flow)
{
	t_lst	*congestion;
	int		i;
	t_path	path;

	i = 0;
	congestion = NULL;
	while (1)
	{
		while (i < flow && sender->ants[i] == 0)
			i++;
		while (beg_point && ((t_dead_end*)(beg_point)->content)->flow == 0)
			beg_point = beg_point->next;
		if (i == flow || !beg_point)
			break ;
		path.traffic = ((t_dead_end*)(beg_point)->content);
		path.sender = i;
		ft_lstadd(&congestion, ft_lstnew(&path, sizeof(path)));
		if (DEBUG > 1)
			ft_printf("DEBUG: Queued path %d: %d->%d.\n", i,
			((t_dead_end*)(beg_point)->content)->src,
			((t_dead_end*)(beg_point)->content)->depth);
		i++;
		beg_point = beg_point->next;
	}
	return (congestion);
}

int		another_way(t_send *sender)
{
	t_path	elem;
	t_lst	*ptr;

	ptr = sender->congestion->next;
	ft_memcpy(&elem, sender->congestion->content, sender->congestion->content_size);
	ft_lstdelone(&sender->congestion, &ft_free_node);
	sender->congestion = ptr;
	if (sender->ants[elem.sender] > 0)
	{
		sender->ants[elem.sender]--;
		ft_lstadd(&sender->congestion, ft_lstnew(&elem, sizeof(t_path)));
		if (DEBUG)
			ft_printf("DEBUG: Sending ant through path %d.\n", elem.sender);
	}
	else
		sender->flow--;
	return (elem.traffic->depth);
}
