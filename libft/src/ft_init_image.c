/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 07:24:22 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 16:20:54 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_init_image(void *mlx, t_image *image)
{
	image->image = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	image->ptr = mlx_get_data_addr(image->image, &(image->bits),
		&(image->size), &(image->end));
	image->bits /= 8;
}
