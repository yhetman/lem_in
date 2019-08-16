/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_sending.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:30:08 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:46:33 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	initialize_sending(t_send *sender, t_lemin *lemin, t_lst **graph)
{
	ft_bzero(sender, sizeof(t_send));
	sender->positions = ft_memalloc(sizeof(int) * (lemin->amount_of_ants));
	sender->len_of_path = size_of_the_way(graph, lemin);
	sender->fastest = ft_min_arr(sender->len_of_path, lemin->flow);
	sender->ants = ft_memalloc(sizeof(int) * lemin->flow);
	amount_to_depart(lemin, sender);
	sender->flow = count_steps(sender, lemin->flow);
	delete_dead_ends(sender, (graph)[lemin->begin], lemin->flow);
	sender->congestion = without_congestion(sender, graph[lemin->begin], lemin->flow);
}

void	clean_sending(t_send *sender)
{
	ft_memdel((void**)&sender->ants);
	ft_memdel((void**)&sender->len_of_path);
	ft_lstdel(&sender->congestion, &ft_free_node);
	ft_memdel((void**)&sender->positions);
}
