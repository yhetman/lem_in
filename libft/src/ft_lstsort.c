/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 08:02:38 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:18:47 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_comper(int a, int b)
{
	if (a <= b)
		return (1);
	else
		return (0);
}

static int	ft_content_comper(t_lst *lst, int (*cmp)(int, int))
{
	while (lst->next != NULL)
	{
		if ((*cmp)((int)lst->content, (int)lst->next->content) == 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_lst		*ft_lstsort(t_lst *lst, int (*cmp)(int, int))
{
	t_lst	*sorted;
	void	*tempo;

	if (lst == NULL || !(cmp))
		return (NULL);
	sorted = lst;
	while (ft_content_comper(sorted, ft_comper) == 0)
	{
		lst = sorted;
		while (lst->next != NULL)
		{
			if ((*cmp)((int)lst->content, (int)lst->next->content) == 0)
			{
				tempo = lst->content;
				lst->content = lst->next->content;
				lst->next->content = tempo;
			}
			lst = lst->next;
		}
	}
	return (sorted);
}
