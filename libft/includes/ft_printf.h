/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:12:47 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/13 17:48:45 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "macros.h"
# include "structs.h"

int						ft_printf(const char *format, ...);
int						ft_dprintf(int fd, const char *format, ...);
void					ft_conversion(t_shit *print);
void					ft_parsing(t_shit *print);
void					ft_buffering(t_shit *print, void *newest, size_t size);
void					ft_coloring(t_shit *print);
void					ft_filled(t_shit *print, int n);
void					ft_pointers(t_shit *print);
void					ft_no_chars(t_shit *print);
void					ft_nbput(t_shit *print);
void					ft_nbput_base(int base, t_shit *print);
void					ft_putfloats(t_shit *print);
void					ft_itoa_base_fill(uintmax_t tmp, int base,
						char str[BUFF_SIZE], t_shit *print);
void					ft_printf_itoa_base(uintmax_t n,
						int base, t_shit *print);
void					ft_printf_itoa(intmax_t n, t_shit *print, int length);
void					ft_printf_str(char *str, t_shit *print);
void					ft_wstrput(t_shit *print);
void					ft_wcharput(t_shit *print, int wc,
						int wlength, int byte_size);
void					ft_strput(t_shit *print);
void					ft_char(t_shit *print, unsigned c);

#endif
