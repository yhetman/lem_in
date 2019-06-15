# lem_in

The project is meant to code an ant farm manager using Breadth-First Search in Edmons-Karp algorithm.

Make an ant farm, with tunnels and rooms;
place the ants on the one side;
and look at how they find the exit.

The rooms are joined to one another with as many tubes as it's needed.

A tube joins two rooms to each other.

A room can be linked to an infinite number of rooms and by as many tubes as deemed necessary.

Program will receive the data describing the ant farm from the standard output:

The rooms are defined by:	name	coord_x	coord_y

The links are defined by:	name1-name2

Also the command lines are broken by coments, which start with #

But lines that start with ## are commands modifying the propeties of the line that comes right after:
			##start signals the ant farm's entrance
			##end	signals the ant farm's exit

If there's not enough data to process normally the ERROR must be displayed.

