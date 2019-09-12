# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/29 14:18:45 by yhetman           #+#    #+#              #
#    Updated: 2019/09/12 19:35:56 by yhetman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	gcc
RM		:=	rm -f
CFLAGS	:=	-Wall -Wextra -Werror
LIBDIR	:=	./libft
LIBFT	:=	$(LIBDIR)/libft.a
BFLAGS	:=	-I$(LIBDIR)/ -Iinclude
DEBUG	:=	-g3 -fsanitize=address -fsanitize=undefined -Og
INCLUDE	:=	-lft -L$(LIBDIR)/
NAME	:=	lem-in
SRC_PATH		= 	./sources/
SRC_NAME	:=	check_length_of_paths.c	\
				choose_paths.c			\
				constructor.c			\
				count_ants_to_send.c	\
				find_the_link.c			\
				ford_fulkerson.c		\
				initialize_pipes.c		\
				initialize_room.c		\
				initialize_send.c		\
				is_valid_room.c			\
				parsing.c				\
				pipes.c					\
				rooms.c					\
				free_leaks_in_check_len.c \
				send_one_ant.c			\
				shut_down_lemin.c

SRC			=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ_PATH	:= 	./obj/
OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_NAME	=	$(SRC_NAME:.c=.o)
MAIN		=	main.c
MAINO		=	$(OBJ_PATH)main.o
H_FILES		:=	includes/lem_in.h
DEPS		=	$(H_FILES) Makefile
TOOLDIR		:=	./tools

all: $(NAME)

$(LIBFT): force
	@$(MAKE) -C $(LIBDIR) 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(DEPS)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(BFLAGS) $< -c -o $@ 

$(NAME): $(DEPS) $(LIBFT) $(OBJ) $(MAINO)
	$(CC) $(CFLAGS) $(BFLAGS) $(INCLUDE) $(OBJ) $(MAINO) -o $@
clean:
	$(MAKE) clean -C $(LIBDIR)
	$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C libft/
	$(RM) $(NAME)
	$(RM) tags

re: fclean all

force:
	@true 
.PHONY: all, re, clean, fclean, force
