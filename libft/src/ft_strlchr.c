/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:01:33 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/11 10:02:31 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		++i;
	return (str[i] != (char)c ? -1 : i);
}
