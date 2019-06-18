/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:35:51 by yhetman           #+#    #+#             */
/*   Updated: 2019/06/18 18:38:12 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**			ERROR MANAGER
*/

void	free_t_stdin(t_stdin **input, void (*del)(void*, size_t))
{
	t_stdin	*tempo;

	if (!del || !input || !*input)
		return ;
	while (*input)
	{
		tempo = (*input)->next;
		del((*input)->info, (*input)->info_size);
		free(*input);
		*input = tempo;
	}
	*input = NULL;
	return ;
}

void	free_t_lem(t_lem *ptr)
{
	ft_memdel((void**)&ptr->start);
	ft_memdel((void**)&ptr->end);
	//free_rooms(&(ptr)->rooms);
	ft_free_2d_arr((void**)ptr->pipes);
}

void	in_case_of_error(t_stdin **temp, t_lem *lem, char *str)
{
	free_t_stdin(temp, &ft_free_node);
	free_t_lem(lem);
	ft_error_manager(str);
}


/*
**			BUFFERING
*/

void	buffering(t_stdin *input)
{
	t_buffer	buff;

	buff.fd = 1;
	buff.printed = 0;
	buff.pos = 0;
	while (input)
	{
		ft_putstr_buff(&buff, input->info);
		ft_putchr_buff(&buff, '\n');
		input = input->next;
	}
	ft_flush_buff(&buff);
}


/*
**			CHECK IF THE PIPES ARE VALID
*/


int			knock_knock(char *name, t_room *neighbourhood)
{
	int		adress;

	adress = 0;
	while (neighbourhood)
	{
		if (!ft_strcmp(neighbourhood->name, name))
			return (adress);
		adress++;
		neighbourhood = neighbourhood->next;
	}
	return (-1);
}

bool		pipes_is_valid(t_stdin **input, char ***array, t_lem *lem)
{
	int	linker[2];

	if (ft_strcntchr((*input)->info, &ft_isdash) > 1
		|| ft_strcntsplt(*array) != 2)
	{
		ft_free_2d_arr((void**)*array);
		*input = (*input)->next;
		return (false);
	}
	linker[0] = knock_knock(*array[0], lem->rooms_list);
	if (linker[0] != 1)
		linker[1] = knock_knock(*array[1], lem->rooms_list);
	if (linker[0] == -1 || linker[1] == -1)
	{
		ft_free_2d_arr((void**)*array);
	}
	lem->pipes[linker[0]][linker[1]] = 4;
	lem->pipes[linker[1]][linker[0]] = 4;
	return (true);
}



/*
**			READING AND INITIALIZATION OF PIPES
*/



void		get_and_init_pipes(t_lem *lem, t_stdin **input)
{
	t_room	*temp;
	char	**arr;
	int		i;

	temp = lem->rooms_list;
	i = 0;
	while (lem->rooms_list)
	{
		lem->pipes[i][i] = lem->rooms_list->type;
		i++;
		lem->rooms_list = lem->rooms_list->next;
	}
	lem->rooms_list = temp;
	while (input)
	{
		if (((*input)->info)[0] == '#')
		{
			(*input) = (*input)->next;
			continue ;
		}
		arr = ft_strsplit((*input)->info, '-');
		if (!pipes_is_valid(input, &arr, lem))
			break ;
		*input = (*input)->next;
		ft_free_2d_arr((void**)arr);
	}
}

/*
**			COUNTING PIPES
*/

int			get_destination(char **array, int dest)
{
	int		i;

	i = 0;
	while (array[i][i] != dest)
		i++;
	return (i);
}

int			rooms_length(t_room *list)
{
	int	i;

	i = 0;
	while (list && ++i)
		list = list->next;
	return (i);
}

bool		count_pipes(t_stdin **input, t_lem *lem)
{
	int		i;
	int		amount;
	bool	uno_link;

	i = 0;
	uno_link = false;
	amount = rooms_length(lem->rooms_list);
	lem->pipes = ft_memalloc(sizeof(char*) * (amount +1));
	while (i < amount)
	{
		lem->pipes[i] = ft_memalloc(sizeof(char*) * (amount +1));
		ft_memset(lem->pipes[i], 1, sizeof(char*) * (amount +1));
	}
	lem->map = amount;
	get_and_init_pipes(lem, input);
	lem->start = get_destination(lem->pipes, 2);
	lem->end = get_destination(&lem->end_room, 3);
	while (--i >= 0 && !uno_link)
		if (!uno_link)
			uno_link = !(!ft_strchr(lem->pipes[i], 4));
	return (uno_link);
}


/*
**			COUNTING ANTS
*/


int			count_ants(t_stdin **input, int *ants)
{
	while (((*input)->info)[0] == '#')
	{
		if (ft_strequ((*input)->info, "##start")
				|| ft_strequ((*input)->info, "##end"))
			return (0);
		(*input) = (*input)->next;
	}
	if (IS_INT((*input)->info))
	{
		*ants = ft_atoi((*input)->info);
		return((*ants >= 0) ? 1 : 0);
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
	ft_free_2d_arr((void**)(void**)coords);
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
		lem->start_room = ft_strdup(name);
	}
	else if (type == 3)
	{
		if (lem->end)
		{
			ft_memdel((void**)&name);
			return (false);
		}
		lem->end_room = ft_strdup(name);
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
	*line = (*list)->info;
	while (*line[0] == '#')
	{
		(*list) = (*list)->next;
		*line = (*list)->info;
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
		if (line[0] == '#')
		{
			if (line[1] != '#')
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
		in_case_of_error(temp, lem, "ERROR: wrong number of arguments\n.");
	if (!(count_ants(input, &lem->ants)))
		in_case_of_error(temp, lem, "ERROR: invalid amount of ants\n.");
	*input = (*input)->next;
	count_rooms(input, lem);
	if (!lem->rooms_list || !no_destination(lem))
		in_case_of_error(temp, lem, "ERROR: there's no beggining or end.\n");
	if (!count_pipes(input, lem))
		in_case_of_error(temp, lem,
		"ERROR: some troubles with pipes, please check everything twice\n.");		
}



/*
**			READING FROM THE STDIN
*/

t_stdin	*new_t_stdin(void const *info, size_t info_size)
{
	t_stdin	*new;

	if (!(new = (t_stdin *)malloc(sizeof(t_stdin))))
		return (NULL);
	if (info == NULL)
	{
		new->info = NULL;
		new->info_size = 0;
		new->next = NULL;
	}
	else
	{
		if (!(new->info = malloc(info_size)))
			return (NULL);
		new->info = ft_memcpy(new->info,
			info, info_size);
		new->info_size = info_size;
		new->next = NULL;
	}
	return (new);
}

void	add_t_stdin(t_stdin **input, t_stdin *add)
{
	if (input != NULL && *input != NULL && add != NULL)
	{
		add->next = *input;
		*input = add;
	}
}


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
			ft_error_manager("ERROR: can't read the file\n");
		add_t_stdin(&input, new_t_stdin(line, sizeof(char) * (LEN(line) + 1)));
	}
	return (input);
}



/*
**			MAIN FUNCTION ITSELF
*/

int		def_flags(int argc, char **argv)
{
	int		i;
	int		bits;

	bits = 0;
	i = 0;
	while (++i < argc)
	{
		if (ft_isflag(argv[i]) == 0)
			return (0);
		else if (ft_isflag(argv[i]) == 1)
		{
			argv[i]++;
			while (*(argv[i]))
			{
				bits = bits | (1 << (*argv[i] - 'a'));
				argv[i]++;
			}
		}
	}
	return (bits);
}

int		main(int argc, char **argv)
{
	t_lem	lem;
	t_stdin	*input;
	t_stdin	*temp;

	ft_bzero(&lem, sizeof(t_lem));
	if (def_flags(argc, argv) ^ 21264)
		lem.insects = "L";
	input = save_input();
	temp = input;
	parsing(&input, &temp, &lem);//parsing of input and init_lem;
	buffering(temp);
	return (0);
}
