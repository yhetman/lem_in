/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:40:50 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/01 22:08:05 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_coord			get_coord(char *input)
{
	int			i;
	char		**matrix;
	t_coord		coord;

	ft_bzero((void*)&coord, sizeof(t_coord));
	matrix = ft_strsplit(input, ' ');
	i = 0;
	while (matrix[i])
		i++;
	if (i > 3)
	{
		coord.x = ft_atoi(matrix[i - 3]);
		coord.y = ft_atoi(matrix[i - 2]);
	}
	clean_double_array(matrix);
	return (coord);
}
