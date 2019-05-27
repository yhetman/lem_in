/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:01:35 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/06 21:15:20 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	j;

	j = -1;
	if (dest && src)
	{
		while (src[++j] != '\0')
			dest[j] = src[j];
		dest[j] = src[j];
	}
	return (dest);
}
