/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:46:47 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/01 19:08:54 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	length;

	i = -1;
	if (!(s))
		return (NULL);
	length = LEN(s) - 1;
	while (ft_find_whitespaces(s[++i]))
		;
	while (length > i && ft_find_whitespaces(s[length]))
		length--;
	if (length < i)
		return (str = ft_strdup(""));
	return (str = ft_strsub(s, i, length - (size_t)i + 1));
}
