/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:41:25 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/11 20:57:34 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <time.h>
# include <stdbool.h>

# include "../libft/includes/libft.h"
# include "../libft/includes/macros.h"
# include "../libft/includes/structs.h"

# define HASH		'#'
# define START		"##start"
# define END		"##end"
# define NORM		1
# define BEGIN		2
# define FINISH		3
# define LINKED		4

typedef struct		s_room
{
	int				ant_amount;
	char			*name;
	char			type;
	t_coord			coord;
	struct s_room	*next;
}					t_room;

typedef struct		s_dead_end
{
	int				flow;
	int				src;
	int				depth;
	struct s_dead_end	*reverse;
}					t_dead_end;

typedef struct		s_path
{
	int				post_code;
	t_dead_end		*traffic;
}					t_path;

typedef struct		s_send
{	
	int				flow;
	int				departed;
	int				arrived;
	int				fastest;
	int				*ants;
	int				*positions;
	int				*len_of_path;
	t_lst			*traffic_jam;
}					t_send;

typedef struct		s_lemin
{
	int				begin;
	int				finish;
	int				size_of_graph;
	int				ants;
	int				flow;
	char			**pipes;
	char			*start_name;
	char			*end_name;
	t_lst			*input;
	t_lst			*len_of_path;
	t_room			*amount_of_rooms;
}					t_lemin;

void				parsing(t_lst **input, t_lst **tmp,
					t_lemin *lemin);
void				shut_down_lemin(t_lst **list, t_lemin *lemin,
					const char *err_mssg, int exit_code);
void				remember_rooms(t_lst **list, t_lemin *lemin);
bool			    is_valid_room(t_lemin **lemin, char *input, char type);
char				*find_the_links(char *input);
t_room				*initialize_room(char *name_ptr, char type,
               		t_coord *coord, int ant_amount);
bool				remember_pipes(t_lst **list, t_lemin *lemin);
void				initialize_pipes(t_lemin *lemin, t_lst **ptr);
void				clean_pipes(char **split);
void				clean_info(t_send *sender);
void				choose_paths(t_array_of_lists graph, t_lemin *lemin);
int					*check_length_of_paths(t_array_of_lists map, t_lemin *lemin);
bool				send_one_ant(t_lst *node, t_lemin *lemin, int i, t_send *s);
void				initialize_send(t_send *sender, t_lemin *lemin, t_lst **map);
void				count_ants_to_send(t_lemin *lemin, t_send *sender);
t_array_of_lists	constructor(t_lemin *lemin);
int					ford_fulkerson(t_array_of_lists map, t_lemin *lemin, int stop);
#endif
