/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:41:25 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/03 15:48:50 by yhetman          ###   ########.fr       */
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

typedef struct		s_lemin
{
	int				begin;
	int				finish;
	int				amount_of_ants;
	int				size_of_graph;
	char			*begin_name;
	char			*finish_name;
	char			**pipes;
	int				flow;
	t_lst			*input;
	t_lst			*len_of_path;
	t_room			*amount_of_rooms;
}					t_lemin;

typedef struct		s_dead_end
{
	int				flow;
	int				src;
	int				depth;
	struct s_dead_end	*reverse;
}					t_dead_end;

typedef struct		s_send
{
	int				*ants;
	int				departed;
	int				arrived;
	int				*positions;
	int				*len_of_path;
	int				fastest;
	int				flow;
	t_lst			*congestion;
}					t_send;

typedef struct		s_path
{
	t_dead_end		*traffic;
	int				sender;
}					t_path;


void				parsing(t_lst **input, t_lst **tmp, t_lemin *lemin);
void				remember_rooms(t_lst **head, t_lemin *lemin);
bool				remember_pipes(t_lst **ptr, t_lemin *lemin);
bool		  		send_one_ant(t_lst *peak, t_lemin *l, int i, t_send *s);
t_room				*add_new_room(char *n, char t, t_coord *coord, int ant_amount);
char				*room_name(char *input);
int					check_name_in_list(char *name, t_room *amount_of_rooms);
void				clean_lem_in(t_lemin *addr);
void				clean_double_array(char **split);
void				room_maid(t_room **head);
int					amount_of_rooms_in_list(t_room *amount_of_rooms);
int					amount_of_splits(char **split);
int					length_of_the_way(t_array_of_lists graph, int src, int depth);
int					*size_of_the_way(t_array_of_lists graph, t_lemin *lemin);
int					ford_fulkerson(t_array_of_lists g, t_lemin *lemin, int stop);
void				send_ants(t_array_of_lists graph, t_lemin *lemin);
void				shut_the_f_up(t_lst **g, t_lemin *l, const char *err_msg, int status);
void				amount_to_depart(t_lemin *lemin, t_send *sender);
void				delete_dead_ends(t_send *sender, t_lst *start, int flow);
t_array_of_lists	construct_this_sht(t_lemin *lemin);
t_coord				get_coord(char *input);
int					last_peak(t_lst *peak);
int					calculation_of_length(t_array_of_lists graph, int src, int depth);
int					peak_step(t_lst *peak);
int					analysator(t_array_of_lists graph, t_lemin *lemin);
void				output_buffer(t_lst *node);

#endif
