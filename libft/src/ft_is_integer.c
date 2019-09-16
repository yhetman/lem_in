/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:16:59 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 16:21:29 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int				ft_is_integer(const char *arg)
{
	intmax_t	tmp;
	size_t		len;

	len = ft_strlen_of_word(arg);
	if (len > 11)
		return (0);
	tmp = ft_atoi(arg);
	if ((intmax_t)INT_MAX < (intmax_t)tmp
		|| (intmax_t)tmp < (intmax_t)INT_MIN)
		return (0);
	if (*arg == '+' || *arg == '-')
		arg++;
	if (!IS_DIGIT(*arg))
		return (0);
	while (*arg && !IS_SPACE(*arg))
		if (!IS_DIGIT(*arg++))
			return (0);
	return (1);
}
