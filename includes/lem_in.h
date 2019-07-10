/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:35:58 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/10 17:44:26 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/structs.h"

typedef t_stdin**	t_graph;

typedef struct		s_stdin
{
	char			*info;
	size_t			info_size;
	struct s_stdin	*next;
}					t_stdin;

typedef struct		s_room
{
	char			*name;
	int				capasity;
	char			type;
	t_coord			c;
	struct s_room	*next;
}					t_room;

typedef struct		s_destin
{
	int				flow_numb;
	int				src;
	int				depth;
	struct s_destin	*reverse;
}					t_destination;

typedef struct		s_lem
{
	int				start;
	int				end;
	int				flow_numb;
	int				map;
	int				ants;
	char			*start_room;
	char			*end_room;
	char			*insects;
	char			**pipes;
	t_room			*rooms_list;
	t_stdin			*input;
	t_stdin			*len;
}                   t_lem;

/*
**		main.c
*/
void    parsing(t_stdin **input, t_stdin **temp, t_lem *lem);

/*
**		reading.c
*/
t_stdin	*save_input(void);
t_stdin *new_t_stdin(char const *info, size_t info_size);
void	add_t_stdin(t_stdin **input, t_stdin *add);
void	del_t_stdin(t_stdin **input, void (*del)(void *, size_t));
void	delone_t_stdin(t_stdin *input, void(*del)(void *, size_t));

/*
**		error.c
*/
void	error_manager(char *str);

#endif
