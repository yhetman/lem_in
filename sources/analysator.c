/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:15:59 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/01 22:27:58 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	analysator(t_array_of_lists graph, t_lemin *lemin)
{
	int		*lengths;
	int		avg_len;
	int		ret;

	lengths = size_of_the_way(graph, lemin);
	avg_len = ft_arr_len(lengths, lemin->flow);
	ret = (lemin->amount_of_ants - 1 / lemin->flow + avg_len);
	ft_lstdel(&lemin->len_of_path, &ft_free_node);
	ft_memdel((void**)&lengths);
	return (ret);
}
