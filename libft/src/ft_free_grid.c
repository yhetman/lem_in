/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 19:14:41 by yhetman           #+#    #+#             */
/*   Updated: 2019/05/25 21:21:53 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_free_grid(char ***grid)
{
	int i;
	int j;

	j = 0;
	while (grid[j])
	{
		i = 0;
		while (grid[j][i])
			if (grid[j][i++])
				free(grid[j][i - 1]);
		if (grid[j++])
			free(grid[j - 1]);
	}
	if (grid)
		free(grid);
}
