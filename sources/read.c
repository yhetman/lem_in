/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:45:27 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/11 21:45:49 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	read_command(char *line)
{
	int		ret;

	ret = NORMAL;
	if (line[0] != '#')
		ret = IGNORE;
	else if (ft_strequ("##start", line))
		ret = STARTROOM;
	else if (ft_strequ("##end", line))
		ret = ENDROOM;
	return (ret);
}

static int	read_room(char *line)
{
	while (*line && *line != ' ')
		line += 1;
	if (*line != ' ')
		return (0);
	line += 1;
	if (*line == '-')
		line += 1;
	while (*line && ft_isdigit(*line))
		line += 1;
	if (*line != ' ')
		return (0);
	line += 1;
	if (*line == '-')
		line += 1;
	while (*line && ft_isdigit(*line))
		line += 1;
	return (*line != '\0' ? 0 : 1);
}

static int	read_path(char *line, t_list *rooms)
{
	int		ret;
	t_path	tmp;

	ret = 0;
	if (ft_strchr(line, '-'))
	{
		tmp.door1 = ft_strsub(line, 0, ft_strlchr(line, '-'));
		tmp.door2 = ft_strdup(line + ft_strlchr(line, '-') + 1);
		if (get_room_name(tmp.door1, rooms) && get_room_name(tmp.door2, rooms))
			ret = 1;
		free(tmp.door1);
		free(tmp.door2);
		tmp.door1 = NULL;
		tmp.door2 = NULL;
	}
	return (ret);
}

int			lemin_read(t_lemin *lemin)
{
	int		ret;
	char	*line;
	int		flag;

	flag = NORMAL;
	lemin->rooms_done = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (read_command(line))
		{
			flag = (flag != NORMAL) ? flag : SET_FLAG(line);
		}
		else if (read_room(line) && !lemin->rooms_done)
		{
			lemin->room_list = ft_lstpush(lemin->room_list, \
											init_room(line, flag));
			flag = NORMAL;
		}
		else if (read_path(line, lemin->room_list) && (lemin->rooms_done = 1))
			lemin->path_list = ft_lstpush(lemin->path_list, init_path(line));
		else
			break ;
	}
	ft_memdel((void **)&line);
	return (ret);
}
