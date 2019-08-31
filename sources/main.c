/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 08:41:56 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/31 22:13:01 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


static t_lst	*read_from_stdin(void)
{
	t_lst		*input;
	char		*l;
	int			ret;

	l = NULL;
	input = NULL;
	while ((ret = ft_backn_gnl(0, &l)))
	{
		if (ret == -1 || !ft_isascii(l[0]))
			ft_error_manager("ERROR OCCURED: can't read the file.");
		ft_lst_last_in(&input, ft_lstnew(l, sizeof(char) * (ft_strlen(l) + 1)));
	}
	return (input);
}

//static int		optional(int argc, char **argv)
//{
//	int		i;
//	int		bits;
//
//	bits = 0;
//	i = 1;
//	while (i < argc)
//	{
//		if (IS_FLAG(argv[i]) == 0)
//			return (0);
//		else if (IS_FLAG(argv[i]) == 1)
//		{
//			argv[i]++;
//			while (*(argv[i]))
//			{
//				bits = bits | (1 << (*argv[i] - 'a'));
//				argv[i]++;
//			}
//		}
//		i++;
//	}
//	return (bits);
//}

static t_array_of_lists	ford(t_lemin *lemin)
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

	s = ford(lemin);
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
	if(argc && argv) {}
	//if (!(optional(argc, argv) ^ 21264))
	//	lemin.ant_output = ANT_DISPLAY;
	//else
		lemin.ant_output = "L";
	input = read_from_stdin();
	tmp = input;
	parsing(&input, &tmp, &lemin);
	output_buffer(tmp);
	figure_out_the_solution(&lemin);
	shut_the_f_up(&tmp, &lemin, "", EXIT_SUCCESS);
}
