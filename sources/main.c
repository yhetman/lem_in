/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 08:41:56 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:37:43 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_array_of_lists	metakarp(t_lemin *lemin)
{
	t_array_of_lists	g;
	int			steps;
	t_lemin		cpy;

	ft_memcpy(&cpy, lemin, sizeof(t_lemin));
	g = construct_this_sht(&cpy);
	steps = ford_fulkerson(g, &cpy, -1);
	if (!steps)
	{
		delete_map(g, cpy.size_of_graph);
		return (NULL);
	}
	delete_map(g, cpy.size_of_graph);
	g = construct_this_sht(lemin);
	ford_fulkerson(g, lemin, steps);
	return (g);
}

static void				figure_out_the_solution(t_lemin *lemin)
{
	t_lst				**s;

	s = metakarp(lemin);
	if (s && lemin->flow > 0)
	{
		ft_putchar('\n');
		ft_lstdel(&lemin->len_of_path, &ft_free_node);
		send_ants(s, lemin);
	}
	else
		ft_putendl("ERROR");
	delete_map(s, lemin->size_of_graph);
}

int					main(int argc, char **argv)
{
	t_lst			*input;
	t_lst			*tmp;
	t_lemin			lemin;

	ft_bzero(&lemin, sizeof(t_lemin));
	if (!(ft_options(argc, argv) ^ 21264))
		lemin.ant_output = ANT_DISPLAY;
	else
		lemin.ant_output = "L";
	input = ft_stdin_to_list();
	tmp = input;
	parsing(&input, &tmp, &lemin);
	output_buffer(tmp);
	figure_out_the_solution(&lemin);
	shut_the_f_up(&tmp, &lemin, "", EXIT_SUCCESS);
}
