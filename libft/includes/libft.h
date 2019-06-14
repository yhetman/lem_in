/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:39:33 by yhetman           #+#    #+#             */
/*   Updated: 2019/06/14 20:12:34 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <wchar.h>
# include <errno.h>
# include <string.h>
# include <time.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>
# include <sys/types.h>
# include "ft_printf.h"
# include "structs.h"
# include "macros.h"

int			ft_display(char *argv);
int			ft_rgb_to_int(int r, int g, int b);
void		ft_error_manager(char *str);
/*
**	function to convert different types
*/
char		*ft_itoa(int n);
int			ft_atoi(const char *str);
int			ft_htoi(const char *hexa);
char		*ft_uintmax_base_toa(uintmax_t n, char *b);
char		*ft_utoa_base(unsigned int numb, char *base);
/*
**	functions to work with lists
*/
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstiter(t_list *lst, void(*f)(t_list *elem));
void		ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void		ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
t_list		*ft_lstnew(void const *content, size_t content_size);
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list		*ft_lstsort(t_list *lst, int (*cmp)(int, int));
/*
**	function for standard output
*/
int			ft_putchar(char c);
int			ft_putstr(const char *str);
void		ft_putendl(const char *s);
void		ft_putnbr(int n);
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_putwstr(wchar_t *wstr);
int			ft_putwchar(wchar_t w);
int			ft_put_uint_base(unsigned int numb, char *base);
int			ft_put_uintmax_base(uintmax_t n, char *b);
void		ft_put_uintmax(uintmax_t n);
/*
**	functions to operate with strings
*/
void		ft_strdel(char **as);
char		*ft_strnew(size_t size);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
int			ft_strequ(const char *s1, const char *s2);
int			ft_strnequ(const char *s1, const char *s2, size_t n);
int			ft_find_whitespaces(char ch);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_free(char *s1, int free1, char *s2, int free2);
char		**ft_strsplit(char const *s, char c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strstr(const char *str, const char *to_find);
char		*ft_strnstr(const char *str, const char *to_find, size_t n);
char		*ft_strdup(const char *src);
int			ft_str_count_char(char *str, char *search);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *str, int ch);
int			ft_strcntchr(const char *str, bool(*find)(char));
int			ft_strcntsplt(char **str);
char		*ft_strcat(char *dest, const char *srce);
char		*ft_strncat(char *restrict str1,
			const char *restrict str2, size_t n);
size_t		ft_strlcat(char *restrict dest, const char *restrict srce,
			size_t size);
char		*ft_strrev(const char *s);
size_t		ft_strlen(const char *str);
void		ft_strerr(char *str);
int			ft_strchri(char *str, int ch, int i);
int			ft_strchri_lu(char *str, int ch, int i);
wchar_t		*ft_wstrsub(wchar_t const *s,
			unsigned int begin, size_t len);
wchar_t		*ft_wstrncpy(wchar_t *dest, const wchar_t *src, size_t n);
/*
**	functions to count length 
*/
size_t		ft_nbrlen(int n);
int			ft_strclen(const char *s, char c);
size_t		ft_strnlen(const char *s, size_t max_len);
size_t		ft_strlen_of_word(const char *str);
int			ft_umaxlen_base(uintmax_t n, int base);
int			ft_imaxlen_base(intmax_t n, int base);
size_t		ft_wstrlen(unsigned *s);
size_t		ft_wcharlen(unsigned wc);
int			ft_ulen_base(unsigned int nbr, int base);
/*
**	memory management
*/
void		ft_memdel(void **ap);
void		*ft_memalloc(size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memchr(const void *arr, int c, size_t n);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
void		*ft_memcpy(void *str1, const void *str2, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *destination,
			const void *source, size_t n);
void		*ft_memset(void *b, int c, size_t n);
/*
**	functions to check chars according to ASCII table
*/
int			ft_isalpha(int ch);
int			ft_isprint(int ch);
int			ft_isdigit(int ch);
int			ft_isascii(int ch);
int			ft_isalnum(int ch);
int			ft_is_integer(const char *arg);
bool		ft_isdash(char check);
int			ft_tolower(int ch);
int			ft_toupper(int ch);
/*
**	mathematical functions
*/ 
int			*ft_range(int first, int last);
void		ft_swap(int *a, int *b);
double		ft_pow(double n, int power);
/*
**	get_next_line
*/
int			get_next_line(const int fd, char **line);
int			ft_backn_gnl(const int fd, char **line);
/*
**	free functions
*/
void		ft_free_grid(char ***grid);
void    	ft_free_2d_arr(void **line);
void		ft_free_node(void *ptr, size_t size);
/*
**	graphical functions to work with mlx
*/
void		ft_init_image(void *mlx, t_image *image);
double		ft_gradient(int first, int second, double percent);
double  	ft_grad_percent(int val, int first, int second);
#endif
