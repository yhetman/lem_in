/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grad_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 07:40:27 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 16:15:54 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double	ft_grad_percent(int val, int first, int second)
{
	if (val == first)
		return (0.0);
	else if (val == second)
		return (1.0);
	else
		return ((double)(val - first) / (second - first));
}
