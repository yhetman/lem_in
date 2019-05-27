/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:12:47 by yhetman           #+#    #+#             */
/*   Updated: 2019/03/15 19:44:37 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define FLAG_HASH		(1 << 0)
# define FLAG_SPACE		(1 << 1)
# define FLAG_PLUS		(1 << 2)
# define FLAG_MINUS		(1 << 3)
# define FLAG_ZERO		(1 << 4)
# define STAR			(1 << 5)
# define UPCASE			(1 << 6)
# define TYPE_SHORT		(1 << 7)
# define TYPE_SHORT2	(1 << 8)
# define TYPE_LONG		(1 << 9)
# define TYPE_LONG2		(1 << 10)
# define TYPE_INTMAX	(1 << 11)
# define TYPE_SIZET		(1 << 12)
# define WIDTH			(1 << 13)
# define PRECIS			(1 << 14)
# define POINTER		(1 << 15)
# define BUFF_SIZE		4096

typedef struct			s_shit
{
	int					len;
	short				params;
	short				n;
	int					min_length;
	int					precis;
	int					filled;
	int					writen;
	int					fd;
	int					index;
	char				buffer[BUFF_SIZE];
	va_list				ap;
	char				*format;
	unsigned			type;
}						t_shit;

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
void					ft_wcharput(t_shit *print, unsigned int wc,
						int wlength, int byte_size);
void					ft_strput(t_shit *print);
void					ft_char(t_shit *print, unsigned c);

#endif
