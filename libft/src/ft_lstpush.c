/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:52:19 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:18:47 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_lst		*ft_lstpush(t_lst *first, void *item)
{
	t_lst	*tmp;

	if (!item)
		return (NULL);
	if (!first)
	{
		first = (t_lst *)malloc(sizeof(t_lst));
		first->content = item;
		first->next = NULL;
	}
	else
	{
		tmp = first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_lst *)malloc(sizeof(t_lst));
		tmp->next->content = item;
		tmp->next->next = NULL;
	}
	return (first);
}
