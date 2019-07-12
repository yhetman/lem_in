# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 18:36:12 by yhetman           #+#    #+#              #
#    Updated: 2019/06/18 16:04:57 by yhetman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	lem-in
RM			:=	rm -rf
OS			:=	$(shell uname)

CC			:=	gcc
FLAGS		:=	-Wall -Wextra -Werror -g3 #-fsanitize=address
HEADER		:=	-I libft/includes -I ./includes

TOOLDIR		:=	./tools

FILES		=	main read init get_params game debug end get_info loop print start validation

SRC			=	$(addprefix sources/, $(addsuffix .c, $(FILES)))
OBJ			=	$(addprefix obj/, $(addsuffix .o, $(FILES)))

obj/%.o: sources/%.c
	$(CC) $(FLAGS) -c -o $@ $< $(HEADER)

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I /usr/local/include -L /usr/local/lib libft/libft.a

libft/libft.a:
	make -C libft

clean: 
	make -C libft clean
	@rm -rf $(OBJ)

fclean:
	make -C libft fclean
	@rm -rf $(NAME)
re: fclean  all

big: all
	@$(RM) big.lemin big.lemin.out
	@echo "\033[4mTesting run time on --big...\033[0m"
	@$(TOOLDIR)/generator --big > big.lemin
	@grep -m 1 required < big.lemin
	@time ./lem-in < big.lemin > big.lemin.out
	@echo "vs.\t\t\t\t\c"
	@grep L < big.lemin.out | wc -l
	@grep L < big.lemin.out | python $(TOOLDIR)/check_doubles.py
	@echo "Output saved in \033[3mbig.lemin.out.\033[0m\n"

super: all
	@$(RM) super.lemin super.lemin.out
	@echo "\033[4mTesting run time on --big-superposition...\033[0m"
	@$(TOOLDIR)/generator --big-superposition > super.lemin
	@grep -m 1 required < super.lemin
	@time ./lem-in < super.lemin > super.lemin.out
	@echo "vs.\t\t\t\t\t\c"
	@grep -c L < super.lemin.out
	@grep L < super.lemin.out | python $(TOOLDIR)/check_doubles.py
	@echo "Output saved in \033[3msuper.lemin.out.\033[0m\n"

ten: all
	@$(RM) ten.lemin ten.lemin.out
	@echo "\033[4mTesting --flow-ten...\033[0m"
	@$(TOOLDIR)/generator --flow-ten > ten.lemin
	@grep -m 1 required < ten.lemin
	@./lem-in < ten.lemin > ten.lemin.out
	@echo "vs.\t\t\t\t\t\c"
	@grep -c L < ten.lemin.out
	@grep L < ten.lemin.out | python $(TOOLDIR)/check_doubles.py
	@echo "Output saved in \033[3mten.lemin.out.\033[0m\n"

one: all
	@$(RM) one.lemin one.lemin.out
	@echo "\033[4mTesting --flow-one...\033[0m"
	@$(TOOLDIR)/generator --flow-one > one.lemin
	@grep -m 1 required < one.lemin
	@./lem-in < one.lemin > one.lemin.out
	@echo "vs.\t\t\t\t\t\c"
	@grep -c L < one.lemin.out
	@grep L < one.lemin.out | python $(TOOLDIR)/check_doubles.py
	@echo "Output saved in \033[3mone.lemin.out.\033[0m\n"

thousand: all
	@$(RM) thousand.lemin thousand.lemin.out
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 18:36:12 by yhetman           #+#    #+#              #
#    Updated: 2019/06/18 16:04:57 by yhetman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
