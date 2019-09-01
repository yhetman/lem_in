/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 08:20:47 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/01 21:51:23 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		output_buffer(t_lst *node)
{
	t_buffer	buffer;

	buffer.fd = 1;
	buffer.printed = 0;
	buffer.pos = 0;
	while (node)
	{
		ft_putstr_buff(&buffer, (char*)node->content);
		ft_putchr_buff(&buffer, '\n');
		node = node->next;
	}
	ft_flush_buff(&buffer);
}
