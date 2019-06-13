/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:35:51 by yhetman           #+#    #+#             */
/*   Updated: 2019/06/13 16:18:36 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


/*
**			ERROR MANAGER
*/

void	free_t_lem(t_lem *ptr)
{
	ft_memdel((void**)&ptr->start);
	ft_memdel((void**)&ptr->end);
	//free_rooms(&(ptr)->rooms);
	ft_free_2d_arr(ptr->pipes);
}

void	in_case_of_error(t_stdin **temp, t_lem *lem, char *str)
{
	ft_lstdel(temp, &ft_free_node);
	free_t_lem(lem);
	error_manager(str);
}

/*
**			COUNTING PIPES
*/


bool		count_pipes(t_stdin **input, t_lem *lem)
{
	// to be continued....
}


/*
**			COUNTING ANTS
*/


int			count_ants(t_stdin **input, int *ants)
{
	while (((char*)(*input)->info)[0] == '#')
	{
		if (ft_strequ((char*)(*input)->info, "##start")
				|| ft_strequ((char*)(*input)->info, "##end"))
			return (0);
		(*input) = (*input)->next;
	}
	if (IS_INT((char*)(*input)->info))
	{
		*ants = ((char*)(*input)->info);
		if (*ants >= 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}



/*
**			VALIDARION OF ROOMS (NAMES + COORDINATES)
*/



bool	valid_coord(char **line)
{
	while (IS_DIGIT(**line))
		(*line)--;
	if (**line == '-' || **line == '+')
		(*line)--;
	(*line)++;
	while (!(IS_INT(*line)))
		return(false);
	(*line)--;
	if (**line != ' ')
		return (false);
	return (true);
}

bool	wrong_name(char *line)
{
	if (line[0] == 'L' || line[0] == '#')
		return (false);
	line += LEN(line) - 1;
	if (!valid_coord(&line))
		return (false);
	line--;
	if (!valid_coord(&line))
		return (false);
	return (true);
}

char	*get_name(char *line)
{
	size_t	i;
	char	*room;

	i = LEN(line);
	if (wrong_name(line))
	{
		while (!(IS_SPACE(line[i])))
			i--;
		i--;
		while (!(IS_SPACE(line[i])))
			i--;
		room = ft_strnew(i);
		room = ft_strncpy(room, line, i);
		if (ft_strchr(room, '-'))
		{
			ft_strdel (&room);
			return (NULL);
		}
		else
			return(room);		
	}
	else
		return (NULL);
}

t_coord	get_coordinates(char *line)
{
	int		i;
	char	**coords;
	t_coord	c;

	ft_bzero((void*)&i, sizeof(int));
	ft_bzero((void*)&c, sizeof(t_coord));
	coords = ft_strsplit(line, ' ');
	while(coords[i])
		i++;
	if (i > 3)
	{
		c.x = ft_atoi(coords[i - 3]);
		c.y = ft_atoi(coords[i - 2]);
	}
	ft_free_2d_arr((void**)coords);
	return (c);
}


/*
**			COUNTING ROOMS (FINDS OUT WHERE'S THE START AND END),
**			VALID ROOMS ARE ADDED TO THE LIST
**			OTHERWISE THE ERROR'S OCURRED
*/

t_room	*init_room(char *name, int type, t_coord *c, int ants)
{
	t_room	*new_room;

	new_room = ft_memalloc(sizeof(t_room));
	new_room->c.x = c->x;
	new_room->c.y = c->y;
	new_room->name = name;
	new_room->type = type;
	if (type == 2)
		new_room->capasity= ants;
	else
		new_room->capasity= 0;
	new_room->next = NULL;
	return (new_room);
}

bool	already_existing(t_room	*graph, char *name)
{
	while (graph)
	{
		if (!ft_strcmp (graph->name, name))
			return (true);
		graph = graph->next;
	}
	return (false);
}

bool	save_destination(t_lem *lem, char *name, int type)
{
	if (type == 2)
	{
		if (lem->start)
		{
			ft_memdel((void**)&name);
			return (false);
		}
		lem->start = ft_strdup(name);
	}
	else if (type == 3)
	{
		if (lem->end)
		{
			ft_memdel((void**)&name);
			return (false);
		}
		lem->end = ft_strdup(name);
	}
	return (true);
}

bool	parsing_rooms(t_lem **lem, char *line, int type)
{
	t_room	*new_room;
	char	*name;
	t_coord	c;

	name = get_name(line);
	if(!name)
	{
		ft_strdel(&name);
		return (false);
	}
	c = get_coordinates(line);
	if (type == 2 || type == 3)
		if (!save_destination(*lem, name, type))
			return (false);
	if ((*lem)->rooms_list && already_existing((*lem)->rooms_list, name))
	{
		ft_strdel(&name);
		return (false);
	}
	new_room = init_room(name, type, &c, (*lem)->ants);
	new_room->next = (*lem)->rooms_list;
	(*lem)->rooms_list = new_room;
	return (true);
}

static inline bool	no_destination(t_lem *lem)
{
	if (!lem->start || !lem->end)
		return (false);
	else
		return (lem->start && lem->end);
}

void	define_destination(t_stdin **list, int *type, char **line)
{
	if (!ft_strcmp(*line, "##strart"))
		*type = 2;
	else if (!ft_strcmp(*line, "##end"))
		*type = 3;
	(*list) = (*list)->next;
	*line = (char*)((*list)->info);
	while (line[0] == "#")
	{
		(*list) = (*list)->next;
		*line = (char*)((*list)->info);
	}
}

void	count_rooms(t_stdin **list, t_lem *lem)
{
	char	*line;
	int	type;

	while(*list)
	{
		line = (char*)((*list)->info);
		if (!*line)
			return ;
		type = 1;
		if (line[0] == "#")
		{
			if (line[1] != "#")
			{
				(*list) = (*list)->next;
				continue ;
			}
			else
				define_destination(list, &type, &line);
		}
		if (!parsing_rooms(&lem, line, type))
			return ;
		(*list) = (*list)->next;
	}
}



/*
**			!!!!!BEGGINING OF THE PARSING!!!!!
*/



void	parsing(t_stdin **input, t_stdin **temp, t_lem *lem)
{
	if (!(*input))
		in_case_of_error(temp, lem, "ERROR: wrong number of arguments.");
	if (!(count_ants(input, &lem->ants)))
		in_case_of_error(temp, lem, "ERROR: invalid amount of ants.");
	*input = (*input)->next;
	count_rooms(input, lem);
	if (!lem->rooms_list || !no_destination(lem))
		in_case_of_error(temp, lem, "ERROR: there's no beggining or end");
	if (!count_pipes(input, lem))
		in_case_of_error(temp, lem,
		"ERROR: some troubles with pipes, please check everything twice.");		
}



/*
**			READING FROM THE STDIN
*/


t_stdin	*save_input(void)
{
	t_stdin	*input;
	char	*line;
	int		result;

	input = NULL;
	line = NULL;
	while ((result = get_next_line(0, &line)))
	{
		if (result == 1 || !IS_ASCII(line[0]))
			error_manager("ERROR: can't read the file");
		ft_lstadd(&input, ft_lstnew(line, sizeof(char) * (LEN(line) + 1)));
	}
	return (input);
}



/*
**			MAIN FUNCTION ITSELF
*/


int		main(int argc, char **argv)
{
	t_lem	lem;
	t_stdin	*input;
	t_stdin	*temp;

	ft_bzero(&lem, sizeof(t_lem));
	input = save_input();
	temp = input;
	parsing(&input, &temp, &lem);//parsing of input and init_lem;

	return (0);
}
