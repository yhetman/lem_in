/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gradient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 07:38:44 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 16:27:40 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double		ft_gradient(int first, int second, double percent)
{
	int		r;
	int		g;
	int		b;

	if (first - second == 0)
		return (first);
	r = (first >> 16) + ((second >> 16)
			- (first >> 16)) * percent;
	g = (first >> 8 & 0xFFFF) + ((second >> 8 & 0xFFFF)
			- (first >> 8 & 0xFFFF)) * percent;
	b = (first & 0xFF) + ((second & 0xFF)
			- (first & 0xFF)) * percent;
	return (r << 16 | g << 8 | b);
}
