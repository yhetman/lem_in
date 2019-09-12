# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/03 15:10:32 by yhetman           #+#    #+#              #
#    Updated: 2019/09/12 18:54:36 by yhetman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

LIBFT_FUNCTIONS = 	ft_display ft_rgb_to_int ft_error_manager \
					ft_itoa ft_atoi ft_htoi ft_lstadd ft_lstiter ft_lstdel \
					ft_lst_rec_free ft_lstforeach  ft_min_arr ft_lst_last_in \
					ft_lstdelone ft_lstnew ft_lstmap ft_lstpush \
					ft_putchar ft_putstr ft_putendl ft_putnbr \
					ft_putchar_fd ft_putstr_fd ft_putendl_fd \
					ft_putnbr_fd ft_putwstr ft_putwchar  ft_arr_len \
					ft_put_uint_base ft_put_uintmax_base \
					ft_put_uintmax ft_strdel ft_strnew ft_strmap \
					ft_strmapi ft_strclr ft_striter ft_striteri \
					ft_strequ ft_strnequ ft_find_whitespaces \
					ft_strsub ft_strtrim ft_strjoin ft_strjoin_free \
					ft_strsplit ft_strcmp ft_strncmp ft_strcpy \
					ft_strncpy ft_strstr ft_strnstr ft_strdup ft_strcntsplt\
					ft_str_count_char ft_strchr ft_strrchr ft_strlchr ft_strcat \
					ft_strncat ft_strlcat ft_strrev ft_strlen ft_strerr \
					ft_strchri ft_wstrsub ft_wstrncpy ft_nbrlen ft_strclen \
					ft_strnlen ft_strlen_of_word ft_wstrlen ft_memdel \
					ft_memalloc ft_bzero ft_memchr ft_memcpy ft_memccpy \
					ft_memcmp ft_memmove ft_memset ft_isalpha ft_isprint ft_put_buff\
					ft_isdigit ft_isascii ft_isalnum ft_is_integer ft_isdash\
					ft_tolower ft_toupper ft_range ft_swap ft_pow ft_put_buff_unicode\
					get_next_line ft_backn_gnl ft_free_grid ft_isflag\
					ft_free_2d_arr ft_gradient ft_grad_percent ft_free_node ft_strcntchr\
					ft_printf	\
					ft_buffering	\
					ft_coloring		\
					ft_conversion 	\
					ft_number_puts	\
					ft_parsing		\
					ft_pointers		\
					ft_printf_itoa	\
					ft_puts			
				
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

HEADERS = -I./includes -I./ft_printf/includes
HEADER_LIBFT = ./includes/libft.h ./includes/ft_printf.h ./includes/macros.h ./includes/structs.h

EOC = \033[0m
GREEN = \033[38;5;132m
RED = \033[38;5;96m
PURPLE = \33[38;5;213m
CYAN = \033[38;5;170m

all: $(NAME)

.PHONY: all clean
.NOTPARALLEL: all $(NAME) clean fclean re 

OBJ_PATH = obj

$(NAME): $(OBJ_PATH) $(OBJ_LIBFT) $(OBJ_PRINTF) $(HEADER_LIBFT) $(HEADER_PRINTF)
	@echo " $(RED)>$(EOC) $(GREEN)$(NAME) is ready.$(EOC)\n"
	@ar rcs $(NAME) $(OBJ_LIBFT) $(OBJ_PRINTF)
	@ranlib $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_LIBFT): obj/%.o: src/%.c $(HEADER_LIBFT)
	@$(CC) -o $@ $(FLAGS) $(HEADERS) -c $<
	@echo "$(CYAN).$(EOC)"

$(OBJ_PRINTF): ft_printf/obj/%.o: ft_printf/src/%.c $(HEADER_PRINTF)
	@$(CC) -o $@ $(FLAGS) $(HEADERS) -c $<
	@echo "$(PURPLE).$(EOC)"

clean:
	@rm -rf $(OBJ_LIBFT) $(OBJ_PRINTF)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
