/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:38:58 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/11 21:49:36 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*init_room(char *line, int room_flag)
{
	int		i;
	t_room	*newroom;

	i = 0;
	if (!(newroom = (t_room *)malloc(sizeof(t_room))))
		ft_strerr("Memory allocation failed.");
	while (line[i] != ' ')
		i += 1;
	newroom->flag = room_flag;
	newroom->name = ft_strsub(line, 0, i);
	while (line[i] == ' ')
		i += 1;
	newroom->x = ft_atoi(line + i);
	while (line[i] != ' ')
		i += 1;
	while (line[i] == ' ')
		i += 1;
	newroom->y = ft_atoi(line + i);
	newroom->paths = NULL;
	newroom->busy = 0;
	newroom->has_ant = 0;
	free(line);
	return (newroom);
}

t_path		*init_path(char *line)
{
	int		i;
	t_path	*newpath;

	if (!(newpath = (t_path *)malloc(sizeof(t_path))))
		ft_strerr("Memory allocation failed.");
	i = (int)ft_strlchr(line, '-');
	newpath->door1 = ft_strsub(line, 0, i);
	newpath->door2 = ft_strdup(line + i + 1);
	free(line);
	return (newpath);
}

t_ant		*init_ants(int total_ants, t_list *rooms)
{
	int		i;
	t_ant	*ants;

	i = -1;
	if (!(ants = (t_ant *)malloc(sizeof(t_ant) * total_ants)))
		ft_strerr("Memory allocation failed.");
	while (++i < total_ants)
	{
		ants[i].room = get_room_flag(STARTROOM, rooms);
		ants[i].did_turn = 0;
		ants[i].id = i + 1;
	}
	return (ants);
}

static void	init_values(t_lemin *init)
{
	if (!(init->ant_total = get_ant_total()))
		ft_strerr("Error: Invalid number of ants.");
	if (lemin_read(init) == ERROR)
		ft_strerr("Error: Reading failed.");
	if (!init->room_list || !init->path_list)
		ft_strerr("Error: Missing rooms or paths.");
	init->ant_list = init_ants(init->ant_total, init->room_list);
}

t_lemin		*lemin_init(int total_params, char *params[])
{
	t_lemin	*init;

	if (!(init = (t_lemin *)malloc(sizeof(t_lemin))))
		ft_strerr("Memory allocation failed.");
	init->moves = 0;
	init->room_list = NULL;
	init->path_list = NULL;
	init->param.debug = 0;
	init->param.ant_colored = 0;
	init->param.path_colored = 0;
	init->param.room_colored = 0;
	get_params(total_params, params, init);
	init_values(init);
	return (init);
}
