/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:03:36 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/17 16:27:26 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_hexa(const char *hexa)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (IS_ALNUM(hexa[i]))
	{
		if (IS_DIGIT(hexa[i]))
			n = n * 16 + (int)hexa[i++] - '0';
		else if (hexa[i] >= 'A' && hexa[i] <= 'F')
			n = n * 16 + (int)hexa[i++] - 'A' + 10;
		else
			n = n * 16 + (int)hexa[i++] - 'a' + 10;
	}
	return (n);
}

int			ft_htoi(const char *hexa)
{
	size_t		i;
	int			sign;

	i = 0;
	sign = 1;
	while (IS_BLANK(hexa[i]) || IS_WHITE(hexa[i]))
		i++;
	if (IS_SIGN(hexa[i]))
		i++;
	return (sign * ft_hexa(hexa + i));
}
