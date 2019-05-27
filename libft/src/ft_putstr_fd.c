/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:28:31 by yhetman           #+#    #+#             */
/*   Updated: 2018/12/29 18:11:15 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(const char *s, int fd)
{
	int j;

	j = 0;
	if (!s)
		return (0);
	while (s[j] != '\0')
	{
		ft_putchar_fd(s[j], fd);
		j++;
	}
	return (j);
}
