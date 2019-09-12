/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_leaks_in_check_len.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:07:30 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/12 19:34:08 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	free_leaks_in_check_len(t_lemin *lemin, t_array_of_lists map)
{
	int	result;
	int	*len;

	len = check_length_of_paths(map, lemin);
	result = (lemin->ants - 1) / lemin->flow +
	ft_arr_len(len, lemin->flow);
	ft_memdel((void**)&len);
	ft_lstdel(&lemin->len_of_path, &ft_free_node);
	return (result);
}
