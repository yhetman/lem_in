/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcntchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 19:59:51 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 16:35:47 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strcntchr(const char *str, bool (*find)(char))
{
	int	reg;

	reg = 0;
	while (*str)
	{
		reg += find(*str);
		str++;
	}
	return (reg);
}
