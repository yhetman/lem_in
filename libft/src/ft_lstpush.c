/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:52:19 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/11 09:53:59 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstpush(t_list *first, void *item)
{
	t_list	*tmp;

	if (!item)
		return (NULL);
	if (!first)
	{
		first = (t_list *)malloc(sizeof(t_list));
		first->content = item;
		first->next = NULL;
	}
	else
	{
		tmp = first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_list *)malloc(sizeof(t_list));
		tmp->next->content = item;
		tmp->next->next = NULL;
	}
	return (first);
}
