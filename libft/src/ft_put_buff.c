/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:31:31 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 16:31:57 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_flush_buff(t_buffer *buf)
{
	if (buf->pos)
	{
		write(buf->fd, buf->step, buf->pos);
		buf->pos = 0;
	}
}

void	ft_putchr_buff(t_buffer *buff, char c)
{
	buff->step[buff->pos] = c;
	buff->pos++;
	buff->printed++;
	if (buff->pos == BUFF_SIZE)
		ft_flush_buff(buff);
}

void	ft_putstr_buff(t_buffer *buf, char *str)
{
	while (*str)
	{
		ft_putchr_buff(buf, *str);
		str++;
	}
}

void	ft_putnstr_buff(t_buffer *buf, char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
	{
		ft_putchr_buff(buf, str[i]);
		i++;
	}
}

void	ft_repeat_buff(t_buffer *buf, char c, int n)
{
	while (n)
	{
		ft_putchr_buff(buf, c);
		n--;
	}
}
