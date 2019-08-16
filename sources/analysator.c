/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:15:59 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:30:50 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	requirement_of_lines(int amount_of_ants, int flow, int avg)
{
	return ((amount_of_ants - 1) / flow + avg);
}

int	analysator(t_array_of_lists graph, t_lemin *lemin)
{
	int		*lengths;
	int		avg_len;
	int		ret;

	lengths = size_of_the_way(graph, lemin);
	avg_len = ft_arr_len(lengths, lemin->flow);
	ret = requirement_of_lines(lemin->amount_of_ants, lemin->flow, avg_len);
	if (DEBUG)
	{
		ft_printf("DEBUG: Avg path length: %d.\n", avg_len);
		ft_printf("\tExpecting %d lines to figure_out_the_solution.\n", ret);
	}
	ft_lstdel(&lemin->len_of_path, &ft_free_node);
	ft_memdel((void**)&lengths);
	return (ret);
}
