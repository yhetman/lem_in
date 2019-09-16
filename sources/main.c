/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 08:41:56 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 15:43:55 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void				clean_map(t_array_of_lists map, int size)
{
	int					i;

	if (!map || !size)
		return ;
	i = -1;
	while (++i < size)
	{
		if (map[i])
			ft_lstdel(&map[i], &ft_free_node);
	}
	ft_memdel((void**)&map);
}

static t_lst			*read_from_stdin(char *line, t_lst *input)
{
	int					result;

	while ((result = ft_backn_gnl(0, &line)))
	{
		if (result == -1 || !IS_ASCII(line[0]))
			ft_error_manager("ERROR OCCURED: can't read the file!\n");
		ft_lst_last_in(&input, ft_lstnew(line, sizeof(char) * (LEN(line) + 1)));
	}
	return (input);
}

static t_array_of_lists	ford(t_lemin *lemin, int steps)
{
	t_lemin				cpy;
	t_array_of_lists	map;

	ft_memcpy(&cpy, lemin, sizeof(t_lemin));
	map = constructor(&cpy);
	steps = ford_fulkerson(map, &cpy, -1);
	if (!steps)
	{
		clean_map(map, cpy.size_of_graph);
		return (NULL);
	}
	clean_map(map, cpy.size_of_graph);
	map = constructor(lemin);
	ford_fulkerson(map, lemin, steps);
	return (map);
}

static void				figure_out_the_solution(t_lst **buffer, t_lemin *lemin)
{
	t_lst				**solve;

	solve = ford(lemin, 0);
	if (solve && lemin->flow > 0)
	{
		output_buffer(*buffer);
		ft_putchar_fd('\n', STD_OUT);
		ft_lstdel(&lemin->len_of_path, &ft_free_node);
		choose_paths(solve, lemin);
	}
	else
		ft_error_manager("ERROR OCCURED!\n");
	clean_map(solve, lemin->size_of_graph);
}

int						main(void)
{
	t_lst				*input;
	t_lst				*tmp;
	t_lemin				lemin;

	input = read_from_stdin(NULL, NULL);
	tmp = input;
	ft_bzero(&lemin, sizeof(t_lemin));
	parsing(&input, &tmp, &lemin);
	figure_out_the_solution(&tmp, &lemin);
	shut_down_lemin(&tmp, &lemin, "", SUCCESS);
	return (1);
}
