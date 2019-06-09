/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:35:51 by yhetman           #+#    #+#             */
/*   Updated: 2019/06/07 05:21:55 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_node(void *ptr, size_t size)
{
	ft_bzero(ptr, size);
	ft_memdel(&ptr);
}

void	free_t_lem(t_lem *ptr)
{
	ft_memdel((void**)&ptr->start);
	ft_memdel((void**)&ptr->end);
	//free_rooms(&(ptr)->rooms);
	//free_split(ptr->pipes);
}

void	in_case_of_error(t_stdin **temp, t_lem *lem, char *str)
{
	ft_lstdel(temp, &free_node);
	free_t_lem(lem);
	error_manager(str);
}

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

void	count_rooms(t_stdin **list, t_lem *lem);

void	parsing(t_stdin **input, t_stdin **temp, t_lem *lem)
{
	if (!(*input))
		in_case_of_error(temp, lem, "ERROR: wrong number of arguments.");
	if (!(count_ants(input, &lem->ants)))
		in_case_of_error(temp, lem, "ERROR: invalid amount of ants.");
	*input = (*input)->next;
	count_rooms(input, lem);
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
			error_manager("ERROR: can't read the file");
		ft_lstadd(&input, ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1)));
	}
	return (input);
}

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
