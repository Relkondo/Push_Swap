# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoron <scoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 12:40:23 by scoron            #+#    #+#              #
#    Updated: 2020/05/09 22:24:43 by scoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CH:= checker
NAME_PS:= push_swap
MAIN_CH:= ch_main
MAIN_PS:= ps_main

BASE_SRC = ps_init \
		   ps_get \
		   ps_verify \
		   ps_operators \
		   ps_operators2 \
		   ch_print \
		   ch_colors \
		   ps_split \
		   ps_rotation \
		   ps_index \
		   ps_small \
		   ps_pile \
		   ps_pop \
		   ps_helper \
		   ch_helper

S_PATH = src/
H_PATH = includes/
O_PATH = obj/
L_PATH = libft/

LIBFT = $(addprefix $(S_PATH), $(L_PATH))
CFLAGS = -Wall -Wextra -fsanitize=address,undefined -g3
ifneq ($(err), no)
	CFLAGS += -Werror
endif

CC = clang

SRC:=$(addprefix $(S_PATH),$(addsuffix .c,$(BASE_SRC)))
SRC_PW:=$(addprefix $(S_PATH),$(addsuffix .c,$(MAIN_PS)))
SRC_CH:=$(addprefix $(S_PATH),$(addsuffix .c,$(MAIN_CH)))
OBJ:=$(addprefix $(O_PATH),$(addsuffix .o,$(BASE_SRC)))
OBJ_CH:=$(addprefix $(O_PATH),$(addsuffix .o,$(MAIN_CH)))
OBJ_PS:=$(addprefix $(O_PATH),$(addsuffix .o,$(MAIN_PS)))

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m

all: $(NAME_CH) $(NAME_PS)

check: check_leak check_error check_ko check_ok check_pw

check_leak:
	valgrind ./push_swap 2>&1 | grep lost
	valgrind ./push_swap "1 2" 2>&1 | grep lost
	valgrind ./push_swap "2 2" 2>&1 | grep lost
	valgrind ./push_swap "a 2" 2>&1 | grep lost
	valgrind ./push_swap "2147483649" 2>&1 | grep lost
	echo "sa" | valgrind ./checker 2>&1 | grep lost
	echo "sa" | valgrind ./checker 1 2 2>&1 | grep lost
	echo "sa" | valgrind ./checker "2 2" 2>&1 | grep lost
	echo "sa" | valgrind ./checker "a 2" 2>&1 | grep lost
	echo "sa" | valgrind ./checker "2147483649" 2>&1 | grep lost
	echo "sa " | valgrind ./checker "1 2" 2>&1 | grep lost
	echo "  sa" | valgrind ./checker "1 2" 2>&1 | grep lost
	echo "sa" | valgrind ./checker -v "1 2" 2>&1 | grep lost
	echo "sa" | valgrind ./checker -vact "1 2" 2>&1 | grep lost
	echo "sa" | valgrind ./checker -g "1 2" 2>&1 | grep lost
	ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | valgrind ./checker -t $$ARG 2>&1 | grep lost
	ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; valgrind ./push_swap $$ARG 2>&1 | grep lost

check_error:
	./checker a 2>&1 | cat -e
	./checker 1 1 2>&1 | cat -e
	./checker 2147483649 2>&1 | cat -e
	./checker 2>&1 | cat -e
	echo "swap" | ./checker "1 2" 2>&1 | cat -e
	echo "sa  " | ./checker "1 2" 2>&1 | cat -e
	echo "  sa" | ./checker "1 2" 2>&1 | cat -e
	./checker -g 2>&1 | cat -e
	./checker -catgv 2>&1 | cat -e
	./push_swap a 2>&1 | cat -e
	./push_swap 1 1 2>&1 | cat -e
	./push_swap -2147483649 2>&1 | cat -e
	./push_swap 2>&1 | cat -e

check_ko:
	echo "sa\npb\nrrr" | ./checker 0 9 1 8 2 7 3 6 4 5
	echo "sa\npb\nrrr" | ./checker "3 2 5 1"

check_ok:
	echo "pb\nra\npb\nra\nsa\nra\npa\npa" | ./checker 0 9 1 8 2
	echo "sa" | ./checker 1 0 2
	cat /dev/null | ./checker 0 1 2

check_pw:
	./push_swap 42
	./push_swap 0 1 2 3
	./push_swap 0 1 2 3 4 5 6 7 8 9
	ARG="2 1 0"; ./push_swap $$ARG | ./checker $$ARG
	ARG="1 5 2 4 3"; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l

check_bonus:
	ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker -vca $$ARG

$(NAME_CH): $(LIBFT)/libft.a $(OBJ) $(OBJ_CH)
	echo "$(GREEN)compiling $@...$(NC)"
	$(CC) -o $(NAME_CH) $(OBJ) $(OBJ_CH) $(CFLAGS) -I $(L_PATH)$(H_PATH) -L $(LIBFT) -lft
	echo "$(GREEN)$@ is ready$(NC)"

$(NAME_PS): $(LIBFT)/libft.a $(OBJ) $(OBJ_PS)
	echo "$(GREEN)compiling $@...$(NC)"
	$(CC) -o $(NAME_PS) $(OBJ) $(OBJ_PS) $(CFLAGS) -I $(L_PATH)$(H_PATH) -L $(LIBFT) -lft
	echo "$(GREEN)$@ is ready$(NC)"

$(O_PATH)%.o: $(S_PATH)%.c includes/$(HEADER)
	mkdir -p $(O_PATH)
	$(CC) $(CFLAGS) -I $(H_PATH) -c $< -o $@

$(LIBFT)/libft.a: FORCE
	$(MAKE) -C $(LIBFT)

FORCE:

clean:
	echo "$(RED)deleting objects...$(NC)"
	$(MAKE) -C $(LIBFT) clean
	$(RM) -R $(O_PATH)

fclean : clean
	echo "$(RED)deleting both executables...$(NC)"
	make -C $(LIBFT) fclean
	$(RM) $(NAME_CH)
	$(RM) $(NAME_PS)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re FORCE
