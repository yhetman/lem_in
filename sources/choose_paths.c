/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:49:12 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/09 18:17:29 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	clean_info(t_send *sender)
{
	ft_memdel((void**)&sender->ants);
	ft_memdel((void**)&sender->len_of_path);
	ft_lstdel(&sender->traffic_jam, &ft_free_node);
	ft_memdel((void**)&sender->positions);
}

static void	optimize_the_way(t_send *sender, t_lst *beg, int flow)
{
	int		i;

	i = -1;
	while (++i < flow && beg)
	{
		while (beg && (((t_dead_end*)(beg->content))->flow == 0))
			beg = beg->next;
		if (i == flow || !beg)
			break ;
		((!sender->ants[i] && ((t_dead_end*)(beg->content))->flow)
			? (((t_dead_end*)(beg->content))->flow = 0) : 0);
			//if (DEBUG)
			//	ft_printf("DEBUG: Path %d (of flow %d) cleared out.\n", i, ((t_dead_end*)(beg->content))->flow);
		//i++;
		((beg->next) ? beg = beg->next : 0);
	}
}

void			choose_paths(t_array_of_lists graph, t_lemin *lemin)
{
	int			i;
	t_send	sender;

	initialize_send(&sender, lemin, graph);
	i = -1;
	while (++i < lemin->ants)
		sender.positions[i] = lemin->begin;
	while (sender.arrived < lemin->ants)
	{
		if (sender.departed < lemin->ants)
			sender.departed += sender.flow;
		i = 0;
		while (i < sender.departed && i < lemin->ants)
		{
			optimize_the_way(&sender, (graph)[lemin->begin], lemin->flow);
			if (sender.positions[i] != lemin->finish)
				sender.arrived += send_one_ant(graph[sender.positions[i]], lemin, i, &sender);
			i++;
		}
		ft_putchar_fd('\n', STD_OUT);
		//if (DEBUG)
		//	print_paths_info(&sender, lemin->flow);
	}
	clean_info(&sender);
}