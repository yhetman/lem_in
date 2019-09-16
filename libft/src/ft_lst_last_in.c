/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_last_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 21:29:16 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 16:25:15 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_lst	*ft_lst_find_last(t_lst *tail)
{
	while (tail && tail->next)
		tail = tail->next;
	return (tail);
}

void			ft_lst_last_in(t_lst **tail, t_lst *last)
{
	if (last)
	{
		if (*tail)
		{
			ft_lst_find_last(*tail)->next = last;
			last->next = NULL;
		}
		else
			ft_lstadd(tail, last);
	}
}
