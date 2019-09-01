/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:20:14 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/01 19:08:54 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = LEN(s) - 1;
	str = (char *)malloc(sizeof(char) * j);
	while (i < LEN(s) && str)
		str[i++] = s[j--];
	str[i] = '\0';
	return (str);
}
