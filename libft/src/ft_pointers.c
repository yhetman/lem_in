/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 20:41:45 by yhetman           #+#    #+#             */
/*   Updated: 2018/12/29 21:04:58 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointers(t_shit *print)
{
	void	*pointer;

	pointer = va_arg(print->ap, void *);
	print->params &= ~FLAG_HASH;
	print->min_length -= (print->params & FLAG_ZERO ? 2 : 0);
	print->filled = (print->writen > print->min_length - 3) ? 0 :
		print->min_length - 3 - print->writen;
	print->params |= FLAG_HASH;
	print->params |= POINTER;
	ft_printf_itoa_base((uintmax_t)pointer, 16, print);
}
