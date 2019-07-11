/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:33:47 by yhetman           #+#    #+#             */
/*   Updated: 2019/07/11 21:35:50 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/macros.h"
# include "../libft/includes/structs.h"

# define IGNORE			(0)
# define STARTROOM 		(1)
# define NORMAL 		(2)
# define ENDROOM		(3)


# define ERROR			(-1)
# define PARAM_ERR		(-2)
# define MALLC_ERR		(-3)

# define ANT_NUM		(3)
# define ANT_WIDTH		(47)
# define ANT_HEIGHT		(4)
# define LOGO_WIDTH		(51)
# define LOGO_HEIGHT	(7)

# define DEBUG_SLEEP	(420000)
# define SET_FLAG(line)	read_command(line);ft_memdel((void **)&line)

# ifndef GLOBAL_VAR
#  define GLOBAL_VAR

extern char const		g_logo[LOGO_HEIGHT][LOGO_WIDTH];
extern char const		g_ant[ANT_NUM][ANT_HEIGHT][ANT_WIDTH];

# endif

typedef struct			s_path
{
	char				*door1;
	char				*door2;
}						t_path;

/*
** Room structure.
*/

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
	int					flag;
	int					busy;
	int					has_ant;
	t_list				*paths;
}						t_room;

/*
** Ant structure.
*/

typedef struct			s_ant
{
	int					id;
	t_room				*room;
	t_room				*last;
	int					did_turn;
}						t_ant;

/*
** Parameter structure.
*/

typedef struct			s_param
{
	int					debug;
	int					ant_colored;
	int					path_colored;
	int					room_colored;
}						t_param;

/*
** Lemin structure.
*/

typedef struct			s_lemin
{
	int					ant_total;
	int					rooms_done;
	long int			moves;
	t_ant				*ant_list;
	t_list				*room_list;
	t_list				*path_list;
	t_param				param;
}						t_lemin;

int						lemin_read(t_lemin *lemin);
int						lemin_validate(t_lemin *lemin);
void					lemin_end(t_lemin *lemin);
void					lemin_loop(t_lemin *lemin);
void					lemin_play(t_lemin *lemin);
void					lemin_start(t_lemin *lemin);
void					lemin_print(t_lemin *lemin);
void					lemin_debug(t_lemin *lemin, t_ant *ant, t_room *room);
t_lemin					*lemin_init(int total_params, char *params[]);
int						find_room(void *room, int flag);
int						get_ant_total(void);
void					get_params(int argc, char *argv[], t_lemin *init);
t_room					*get_room_name(char *name, t_list *list);
t_room					*get_room_flag(int flag, t_list *list);
t_ant					*init_ants(int total_ants, t_list *rooms);
t_path					*init_path(char *line);
t_room					*init_room(char *line, int room_flag);

#endif
