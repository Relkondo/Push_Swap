# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoron <scoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 12:40:23 by scoron            #+#    #+#              #
#    Updated: 2020/05/09 20:59:57 by scoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CH:= checker
NAME_PS:= push_swap
MAIN_CH:= ch_main
MAIN_PS:= ps_main
FILES:= ps_init \
        ps_get \
        ps_verify \
        ps_operators \
        ps_operators2 \
        ch_colors \
        ch_print \
        ps_split \
        ps_rotation \
        ps_index \
        ps_small \
        ps_pile \
        ps_pop \
        ps_helper \
		ch_helper

LFTDIR:=./libft

COMPILER:=clang
LINKER:=ar rc
S_PATH:=src/
H_PATH:=includes/
O_PATH:=obj/
IFLAGS:=-I $(H_PATH) -I $(LFTDIR)/includes
LFLAGS:=-L $(LFTDIR) -lft
CFLAGS:=-Wall -Wextra -Werror $(IFLAGS)
WIDTH = $(shell echo $(notdir $(FILES)) | tr " " ".c\n" | \
        awk ' { if ( length > x) { x = length; y = $$0 } }END{ print y }'| wc -c)

BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

SRC:=$(addprefix $(S_PATH),$(addsuffix .c,$(FILES)))
SRC_PW:=$(addprefix $(S_PATH),$(addsuffix .c,$(MAIN_PS)))
SRC_C:=$(addprefix $(S_PATH),$(addsuffix .c,$(MAIN_CH)))
OBJ:=$(addprefix $(O_PATH),$(addsuffix .o,$(FILES)))
OBJ_C:=$(addprefix $(O_PATH),$(addsuffix .o,$(MAIN_CH)))
OBJ_PW:=$(addprefix $(O_PATH),$(addsuffix .o,$(MAIN_PS)))
CCHF:=.cache_exists

all: $(NAME_PS) $(NAME_CH)

$(NAME_CH): $(OBJ) $(OBJ_C)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) "Compiling $@..." $(RED)
	@$(COMPILER) $(CFLAGS) $(SRC) $(LFLAGS) $(S_PATH)$(MAIN_CH).c -o $(NAME_CH)
	@echo $(GREEN) " - Compiled" $(EOC)

$(NAME_PS): $(OBJ) $(OBJ_PW)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) "Compiling $@..." $(RED)
	@$(COMPILER) $(CFLAGS) $(SRC) $(LFLAGS) $(SRC_PW) -o $(NAME_PS)
	@echo $(GREEN) " - Compiled" $(EOC)

$(O_PATH)%.o: $(S_PATH)%.c | $(CCHF)
	@tput civis
	@printf $(PURPLE)
	@printf "Compiling %-$(WIDTH)s" $(notdir $<)
	@$(COMPILER) $(CFLAGS) -c $< -o $@
	@printf $(EOC)
	@printf "\r"

%.c:
	@echo $(RED)"Missing file : $@" $(EOC)

$(CCHF):
	@mkdir $(O_PATH)
	@touch $(CCHF)

clean:
	@rm -rf $(O_PATH)
	@rm -f $(CCHF)
	@cd $(LFTDIR) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME_CH)
	@rm -f $(NAME_PS)
	@rm -rf $(NAME_CH).dSYM/
	@rm -rf $(NAME_PS).dSYM/
	@cd $(LFTDIR) && $(MAKE) fclean

re: fclean
	@$(MAKE) all

test: $(NAME_CH) $(NAME_PS)
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_C) $(SRC) $(LFLAGS) -o checker
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_PW) $(SRC) $(LFLAGS) -o push_swap
	@./push_swap $(ARG) | ./checker $(OPT) $(ARG)

test_ch: $(NAME_CH)
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_C) $(SRC) $(LFLAGS) -o checker
	@./push_swap $(ARG) | ./checker $(ARG)

test_pw: $(NAME_PS)
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_PW) $(SRC) $(LFLAGS) -o push_swap
	@ ./push_swap $(ARG)
	@ echo $(ARG) > input.txt
	
debug_pw: $(NAME_PS)
	@$(COMPILER) -g -w $(CFLAGS) $(SRC_PW) $(SRC) $(LFLAGS) -o push_swap
	@ ./push_swap $(OPT) $(ARG)
	@ echo $(ARG) > input.txt

debug: $(NAME_CH) $(NAME_PS)
	@$(COMPILER) -g $(IFLAGS) $(SRC_C) $(SRC) $(LFLAGS) -o checker
	@$(COMPILER) -g $(IFLAGS) $(SRC_PW) $(SRC) $(LFLAGS) -o push_swap

check: check_leak check_error check_ko check_ok check_pw

check2: check_error check_ko check_ok check_pw

check_leak: $(NAME_CH) $(NAME_PS)
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

check_error: $(NAME_CH) $(NAME_PS)
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

check_ko: $(NAME_CH)
	echo "sa\npb\nrrr" | ./checker 0 9 1 8 2 7 3 6 4 5
	echo "sa\npb\nrrr" | ./checker "3 2 5 1"

check_ok: $(NAME_CH) $(NAME_PS)
	echo "\0" | ./checker 0 1 2
	echo "pb\nra\npb\nra\nsa\nra\npa\npa" | ./checker 0 9 1 8 2
	echo "sa" | ./checker 1 0 2

check_pw:
	./push_swap 42
	./push_swap 0 1 2 3
	./push_swap 0 1 2 3 4 5 6 7 8 9
	ARG="2 1 0"; ./push_swap $$ARG | ./checker -t $$ARG
	ARG="1 5 2 4 3"; ./push_swap $$ARG | ./checker -t $$ARG
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l

check_bonus:
	ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker -vca $$ARG

norm:
	@norminette $(SRC) $(H_PATH) | grep -v	Norme -B1 || true
	@cd $(LFTDIR) && $(MAKE) norm

push : fclean
	@git add -A
	@git commit -m "quick push"
	@git push origin master
	git status

.PHONY: all clean fclean re test norme test_ch test_pw debug check push
