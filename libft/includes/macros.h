/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:20:45 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 16:08:07 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define STD_IN		    (0)
# define STD_OUT		(1)
# define STD_ERR		(2)
# define FAIL           1
# define SUCCESS        0
/*
**  definition of window's size for mlx
*/
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define FT_INT_MAX 2147483647
/*
**  colors
*/
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define EOC		"\033[0m"
/*
**  bit masks for ft_printf
*/
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
/*
**  definition of buffer's size, used in get_next_line and ft_printf
*/
# define BUFF_SIZE      1
/*
**  string stuff
*/
# define LEN(x)					ft_strlen(x)
# define NLEN(x, y)				ft_strnlen(x, y)
# define STRERR					strerror
/*
**  mathematical macros
*/
# define MAX(a, b)				(b & ((a - b) >> 31)) | (a & ((~(a - b)) >> 31))
# define MIN(a, b)				(a & ((a - b) >> 31)) | (b & ((~(a - b)) >> 31))
# define ABS(x)					((x < 0) ? -x : x)
# define DABS(a)				(a < 0.0f) ? -a : a
# define POW(x)					((x) * (x))
# define AVERAGE(x, y)			(((x) + (y)) / 2.0)
# define COS(c)					cos(c)
# define SIN(c)					sin(c)
/*
**  macros to check chars according to the ASCII table
*/
# define IS_ASCII(c)			(!(c >> 7))
# define IS_BLANK(c)			(c == ' ' || c == '\t' || c == '\n')
# define IS_WHITE(c)			(c == '\f' || c == '\v' || c == '\r')
# define IS_DIGIT(c)			((unsigned int)(c - '0') < 10)
# define IS_GRAPH(c)			((unsigned int)(c - '!') < 94)
# define IS_LOWER(c)			((unsigned int)(c - 'a') < 26)
# define IS_PRINT(c)			((unsigned int)(c - ' ') < 95)
# define IS_CNTRL(c)			(!IS_PRINT(c))
# define IS_UPPER(c)			((unsigned int)(c - 'A') < 26)
# define IS_ALPHA(c)			(IS_LOWER(c) || IS_UPPER(c))
# define IS_ALNUM(c)			(IS_DIGIT(c) || IS_ALPHA(c))
# define IS_PUNCT(c)			(IS_PRINT(c) && !FT_ISALNUM(c) && c != ' ')
# define IS_SPACE(c)			(((9 <= c && c <= 13) || c == 32) ? 1 : 0)
# define IS_SIGN(c)				(c == '+' || c == '-')
# define IS_INT(c)              ft_is_integer(c)
# define IS_DASH(c)             ft_isdash(c)
# define IS_FLAG(c)             ft_isflag(c)
# define TO_ASCII(c)			(c & 0x7F)
# define TO_LOWER(c)			(IS_UPPER(c) ? c + ' ' : c)
# define TO_UPPER(c)			(IS_LOWER(c) ? c - ' ' : c)
/*
**  macros to work with bits
*/
# define SET_BIT(val, plc)		(val | (1 << plc))
# define CLEAR_BIT(val, plc)	(val & (~(1 << plc)))
# define TOGGLE_BIT(val, plc)	(val ^ (1 << plc))
# define GET_BIT(val, plc)		((val >> plc) & 1)
# define GET_MSB(val, datatype)	GET_BIT(val, (sizeof(datatype) * 4 - 1))
# define GET_LSB(val)			GET_BIT(val, 0)
#endif
