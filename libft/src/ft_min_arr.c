/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 18:43:08 by yhetman           #+#    #+#             */
/*   Updated: 2019/08/16 18:45:44 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min_arr(int *arr, int size)
{
	int		i;
	int		min;

	i = 0;
	min = arr[0];
	while (++i < size)
		min = MIN(min, arr[i]);
	return (min);
}