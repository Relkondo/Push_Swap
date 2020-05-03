# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoron <scoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 12:40:23 by scoron            #+#    #+#              #
#    Updated: 2019/03/14 12:36:42 by scoron           ###   ########.fr        #
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
          ps_split \
          ps_rotation \
          ps_index \
          ps_small \
          ps_pile \
          ps_pop \
          ps_helper

S_PATH = src/
H_PATH = includes/
O_PATH = obj/
L_PATH = libft/

LIBFT = $(addprefix $(S_PATH), $(L_PATH))
FLAGS = -Wall -Wextra -Werror
CC = clang

SRC:=$(addprefix $(S_PATH),$(addsuffix .c,$(BASE_SRC)))
SRC_PW:=$(addprefix $(S_PATH),$(addsuffix .c,$(MAIN_PS)))
SRC_CH:=$(addprefix $(S_PATH),$(addsuffix .c,$(MAIN_CH)))
OBJ:=$(addprefix $(O_PATH),$(addsuffix .o,$(BASE_SRC)))
OBJ_CH:=$(addprefix $(O_PATH),$(addsuffix .o,$(MAIN_CH)))
OBJ_PS:=$(addprefix $(O_PATH),$(addsuffix .o,$(MAIN_PS)))

RED		=	\033[0;31m
GREEN	=	\033[0;32m
NC		=	\033[0m

all: $(NAME_CH) $(NAME_PS)

$(NAME_CH): lib $(OBJ) $(OBJ_CH)
	@echo "$(GREEN)compiling $@...$(NC)"
	@$(CC) -o $(NAME_CH) $(OBJ) $(OBJ_CH) $(FLAGS) -I $(L_PATH)$(H_PATH) -L $(LIBFT) -lft
	@echo "$(GREEN)$@ is ready$(NC)"

$(NAME_PS): lib $(OBJ) $(OBJ_PS)
	@echo "$(GREEN)compiling $@...$(NC)"
	@$(CC) -o $(NAME_PS) $(OBJ) $(OBJ_PS) $(FLAGS) -I $(L_PATH)$(H_PATH) -L $(LIBFT) -lft
	@echo "$(GREEN)$@ is ready$(NC)"

$(O_PATH)%.o: $(S_PATH)%.c includes/$(HEADER)
	@mkdir -p $(O_PATH)
	@$(CC) $(FLAGS) -I $(H_PATH) -c $< -o $@

lib :
	@make -C $(LIBFT)

clean:
	@echo "$(RED)deleting objects...$(NC)"
	@make -C $(LIBFT) clean
	@/bin/rm -rf $(O_PATH)

fclean : clean
	@echo "$(RED)deleting both executables...$(NC)"
	@make -C $(LIBFT) fclean
	@/bin/rm -f $(NAME_CH)
	@/bin/rm -f $(NAME_PS)

re: fclean all

.PHONY: all clean fclean re
