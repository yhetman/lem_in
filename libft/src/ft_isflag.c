/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:21:14 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 16:23:03 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

bool	ft_isflag(const char *arg)
{
	if (!arg || *arg != '-')
		return (0);
	while (*(++arg))
		if (!IS_LOWER(*arg))
			return (0);
	return (1);
}
