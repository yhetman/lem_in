/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:35:58 by yhetman           #+#    #+#             */
/*   Updated: 2019/06/06 16:12:03 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/structs.h"

typedef struct		s_room
{
	char			*name;
	int				capasity;
	char			type;
	t_coord			c;
	struct s_room	*next;
}					t_room;

typedef struct		s_lem
{
	int				start;
	int				end;
	int				map;
	int				ants;
	t_room			*rooms_list;
	char			**pipes;
}                   t_lem;

/*
**		main.c
*/
t_list	*save_input(void);
void    parsing(t_list **input, t_list **temp, t_lem *lem);

/*
**		error.c
*/
void	error_manager(char *str);
#endif
