# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/03 15:10:32 by yhetman           #+#    #+#              #
#    Updated: 2019/05/06 20:55:36 by yhetman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -g3

LIBFT_FUNCTIONS = ft_putchar	ft_putendl		ft_putstr		\
				ft_putnbr		ft_strclr 		ft_putnbr_fd	\
				ft_putendl_fd	ft_putchar_fd	ft_putstr_fd	\
				ft_striteri		ft_striter		ft_strequ		\
				ft_strnequ		ft_memdel		ft_memalloc		\
				ft_strdel		ft_strnew		ft_strmap		\
				ft_strmapi		ft_strsub		ft_strtrim		\
				ft_strjoin		ft_strsplit		ft_itoa			\
				ft_strerr		ft_swap			ft_lstsort		\
				ft_range		ft_rgb_to_int	ft_lstnew		\
				ft_lstdelone	ft_lstdel		ft_lstadd		\
				ft_tolower		ft_lstiter		ft_lstmap		\
				ft_atoi			ft_bzero		ft_isalnum		\
				ft_isalpha		ft_isdigit		ft_isprint		\
				ft_isascii		ft_memset		ft_memcpy		\
				ft_memccpy		ft_memmove		ft_memchr		\
				ft_memcmp		ft_strlen		ft_strdup		\
				ft_strcpy		ft_strncpy		ft_strcat		\
				ft_strncat		ft_strlcat		ft_strchr		\
				ft_strrchr		ft_strstr		ft_strnstr		\
				ft_strcmp		ft_strncmp		ft_toupper		\
				ft_display		ft_strrev		ft_strnlen		\
				ft_find_whitespaces ft_backn_gnl get_next_line	\
				ft_put_uint_base	ft_put_uintmax_base			\
				ft_put_uintmax		ft_putwchar		ft_putwstr	\
				ft_wstrlen			ft_wstrncpy		ft_wstrsub	\
				ft_maxlen_base		ft_pow 			ft_strchri	\
				ft_strjoin_free		ft_free_grid	ft_charinstr\
				ft_strclen			ft_htoi			ft_printf	\
				ft_buffering	\
				ft_coloring		\
				ft_conversion 	\
				ft_number_puts	\
				ft_parsing		\
				ft_pointers		\
				ft_printf_itoa	\
				ft_puts			\
				
PRINTF_FUNCTIONS = 	ft_printf		\
					ft_buffering	\
					ft_coloring		\
					ft_conversion 	\
					ft_number_puts	\
					ft_parsing		\
					ft_pointers		\
					ft_printf_itoa	\
					ft_puts			\


OBJ_LIBFT = $(addprefix obj/, $(addsuffix .o, $(LIBFT_FUNCTIONS)))
SRC_LIBFT = $(addprefix src/, $(addsuffix .c, $(LIBFT_FUNCTIONS)))

#OBJ_PRINTF = $(addprefix ft_printf/obj/, $(addsuffix .o, $(PRINTF_FUNCTIONS)))
#SRC_PRINTF = $(addprefix ft_printf/src/, $(addsuffix .c, $(PRINTF_FUNCTIONS)))

HEADERS = -I./includes -I./ft_printf/includes
HEADER_LIBFT = ./includes/libft.h ./includes/ft_printf.h
#HEADER_PRINTF = ./ft_printf/includes/ft_printf.h

EOC = \033[0m
GREEN = \e[38;5;132m
RED = \e[38;5;96m
PURPLE = \e[38;5;213m
CYAN = \e[38;5;170m

all: $(NAME)

.PHONY: all clean
.NOTPARALLEL: all $(NAME) clean fclean re 

OBJ_PATH = obj

$(NAME): $(OBJ_PATH) $(OBJ_LIBFT) $(OBJ_PRINTF) $(HEADER_LIBFT) $(HEADER_PRINTF)
	@printf " $(RED)>$(EOC) $(GREEN)$(NAME) is ready.$(EOC)\n"
	@ar rcs $(NAME) $(OBJ_LIBFT) $(OBJ_PRINTF)
	@ranlib $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_LIBFT): obj/%.o: src/%.c $(HEADER_LIBFT)
	@$(CC) -o $@ $(FLAGS) $(HEADERS) -c $<
	@printf "$(CYAN).$(EOC)"

$(OBJ_PRINTF): ft_printf/obj/%.o: ft_printf/src/%.c $(HEADER_PRINTF)
	@$(CC) -o $@ $(FLAGS) $(HEADERS) -c $<
	@printf "$(PURPLE).$(EOC)"

clean:
	@rm -rf $(OBJ_LIBFT) $(OBJ_PRINTF)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
