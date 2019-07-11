/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:49:08 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/11 21:50:40 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			get_ant_total(void)
{
	char	*line;
	int		ant_number;

	line = NULL;
	if (get_next_line(0, &line) > 0)
	{
		while (line[0] == '#')
		{
			ft_memdel((void **)&line);
			if (get_next_line(0, &line) == ERROR)
			{
				line = NULL;
				break ;
			}
		}
	}
	ant_number = (line != NULL && *line != '\0') ? atoi(line) : 0;
	ft_memdel((void **)&line);
	return (ant_number);
}

t_room		*get_room_flag(int flag, t_list *list)
{
	int		done;
	t_room	*tmp;

	done = 0;
	while (list && !done)
	{
		tmp = (t_room *)list->content;
		done = tmp->flag == flag ? 1 : 0;
		list = list->next;
	}
	return (done ? tmp : NULL);
}

int			find_room(void *room, int targetflag)
{
	t_room	*current;
	t_list	*testing;
	int		smallestpath;
	int		lastpath;

	current = (t_room *)room;
	if (current->flag == targetflag)
		return (0);
	if (current->busy)
		return (-1);
	current->busy = 1;
	smallestpath = FT_INT_MAX;
	testing = current->paths;
	while (testing)
	{
		if ((lastpath = find_room(testing->content, targetflag)) < smallestpath
														&& lastpath != -1)
			smallestpath = 1 + lastpath;
		testing = testing->next;
	}
	current->busy = 0;
	return (smallestpath == FT_INT_MAX ? ERROR : smallestpath);
}