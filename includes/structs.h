/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:19:26 by yhetman           #+#    #+#             */
/*   Updated: 2019/06/05 20:19:45 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
}					t_lem;

#endif