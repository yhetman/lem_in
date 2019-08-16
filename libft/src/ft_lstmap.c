/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 07:34:27 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:18:47 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst *elem))
{
	t_lst	*newlst;
	t_lst	*created;
	t_lst	*tempo;

	if (!lst || !f)
		return (NULL);
	tempo = f(lst);
	if ((newlst = ft_lstnew(tempo->content, tempo->content_size)))
	{
		created = newlst;
		lst = lst->next;
		while (lst != NULL)
		{
			tempo = (*f)(lst);
			if (!(created->next = ft_lstnew(tempo->content,
				tempo->content_size)))
				return (NULL);
			created = created->next;
			lst = lst->next;
		}
	}
	return (newlst);
}
