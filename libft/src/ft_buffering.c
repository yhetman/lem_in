/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:32:42 by yhetman           #+#    #+#             */
/*   Updated: 2018/12/29 18:02:24 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_buffering(t_shit *print, void *newest, size_t size)
{
	int			difference;
	long long	i;

	i = 0;
	while (BUFF_SIZE - print->index < (int)size)
	{
		difference = BUFF_SIZE - print->index;
		ft_memcpy(&(print->buffer[print->index]), (newest + i), difference);
		size -= difference;
		i += difference;
		print->index += difference;
		print->len += difference;
		write(print->fd, print->buffer, print->index);
		print->index = 0;
	}
	ft_memcpy(&(print->buffer[print->index]), (newest + i), size);
	print->index += size;
	print->len += size;
}
