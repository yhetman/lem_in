/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:16:42 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 16:08:40 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libft.h"
# include "macros.h"

typedef struct		s_shit
{
	int				len;
	short			params;
	short			n;
	int				min_length;
	int				precis;
	int				filled;
	int				writen;
	int				fd;
	int				index;
	char			buffer[BUFF_SIZE];
	va_list			ap;
	char			*format;
	unsigned		type;
}					t_shit;

typedef struct		s_fdl
{
	int				fd;
	char			*reste;
	struct s_fdl	*next;
}					t_fdl;

typedef struct		s_buffer
{
	char			step[BUFF_SIZE];
	size_t			pos;
	int				fd;
	int				printed;
}					t_buffer;

typedef struct		s_gnl
{
	int				length;
	char			*buffer;
	t_fdl			*mew;
	int				ret;
}					t_gnl;

typedef struct		s_lst
{
	void			*content;
	size_t			content_size;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				dec;
}					t_color;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_image
{
	void			*image;
	char			*ptr;
	int				bits;
	int				size;
	int				end;
}					t_image;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_image			image;
	int				win_height;
	int				win_width;
}					t_mlx;

typedef t_lst**		t_array_of_lists;

#endif
