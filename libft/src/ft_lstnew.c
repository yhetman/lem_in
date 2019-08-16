/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:09:00 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:18:47 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstnew(void const *content, size_t content_size)
{
	t_lst	*element;

	if (!(element = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	if (content == NULL)
	{
		element->content = NULL;
		element->content_size = 0;
		element->next = NULL;
	}
	else
	{
		if (!(element->content = malloc(content_size)))
			return (NULL);
		element->content = ft_memcpy(element->content,
			content, content_size);
		element->content_size = content_size;
		element->next = NULL;
	}
	return (element);
}
