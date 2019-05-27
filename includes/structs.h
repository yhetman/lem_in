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