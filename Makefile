# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 16:57:14 by mthamir           #+#    #+#              #
#    Updated: 2024/05/04 15:53:49 by mthamir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

BON := checker

CC := cc

FLAGS := -Wall -Wextra -Werror

SRC_FILES := push_swap_m.c parsing_0_m.c	parsing_1_m.c	parsing_2_m.c	parsing_3_m.c	parsing_4_m.c moves_funs_m.c moves_funs1_m.c sorting_3_4_5_m.c set_index_m.c big_sort_0_m.c big_sort_1_m.c

SRC_BONUS := check_sorting_bonus.c mine_checker_bonus.c  moves_0_bonus.c  moves_1_bonus.c  pars_0_bonus.c  pars_1_bonus.c  pars_2_bonus.c  pars_3_bonus.c  pars_4_bonus.c 

OBJ_BONUS :=  $(SRC_BONUS:.c=.o)

OBJ_FILES := $(SRC_FILES:.c=.o)

all : $(NAME)

bonus : $(BON)

$(BON) : $(OBJ_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) -o $(BON)

$(NAME) : $(OBJ_FILES) 
	$(CC) $(FLAGS) $(OBJ_FILES)  -o $(NAME)

%bonus.o : %bonus.c checker_header.h
	$(CC) $(FLAGS) -c $<

%m.o : %m.c push_swap_m.h
	$(CC) $(FLAGS) -c $<

clean :
	rm -f $(OBJ_FILES) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME) $(BON)

re : fclean all
