NAME		=	lem_in
OS			=	$(shell uname)

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g3 #-fsanitize=address
HEADER		=	-I libft/includes -I ./includes

ifeq ($(OS), Linux)
FLAGS_PLUS	= -L ./minilibx -lmlx -lm -lXext -lX11
else
FLAGS_PLUS	= -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit
endif

FILES		=	main 

SRC			=	$(addprefix sources/, $(addsuffix .c, $(FILES)))
OBJ			=	$(addprefix obj/, $(addsuffix .o, $(FILES)))

obj/%.o: sources/%.c
	$(CC) $(FLAGS) -c -o $@ $< $(HEADER)

all: $(NAME)

$(NAME): libft/libft.a mlx $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I /usr/local/include -L /usr/local/lib \
	-lmlx libft/libft.a -framework OpenGL -framework AppKit

libft/libft.a:
	make -C libft

ifeq ($(OS), Linux)
mlx:
	make -C minilibx
else
mlx:
	make -C minilibx_macos
endif


clean: clean_mlx
	make -C libft clean
	@rm -rf $(OBJ)

ifeq ($(OS), Linux)
clean_mlx:
	make -C minilibx clean
else
clean_mlx:
	make -C minilibx_macos clean
endif

fclean: clean_mlx
	make -C libft fclean
	rm -rf $(OBJ)
	rm -rf $(NAME)


re: fclean all

.PHONY: all clean fclean re
.NOTPARALLEL: all $(NAME) libft/libft.a mlx clean clean_mlx fclean re
