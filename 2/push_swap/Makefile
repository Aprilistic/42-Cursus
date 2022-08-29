# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 19:01:28 by jinheo            #+#    #+#              #
#    Updated: 2022/08/12 17:46:02 by jinheo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Commands
RM		= rm -f

#Binary
NAME = push_swap
CHECK_NAME = checker

#Directory
PUSH_DIR = mandatory/
CHECK_DIR = bonus/

#Name
PUSH_SRC_NAME	= additional_func.c calculate_info.c \
		init_sort_a_to_a.c init_sort_a_to_b.c \
		merge_sort_func.c push_swap.c small_num_sort.c \
		stl/basic_func_1.c stl/basic_func_2.c \
		stl/redefined_func_1.c stl/redefined_func_2.c

CHECK_SRC_NAME = additional_func_bonus.c checker_bonus.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c \
		stl/basic_func_1_bonus.c stl/basic_func_2_bonus.c \
		stl/redefined_func_1_bonus.c stl/redefined_func_2_bonus.c

PUSH_OBJ_NAME	= $(PUSH_SRC_NAME:.c=.o)

CHECK_OBJ_NAME	= $(CHECK_SRC_NAME:.c=.o)

#Files
PUSH_SRC	= $(addprefix $(PUSH_DIR), $(PUSH_SRC_NAME))
PUSH_OBJ 	= $(addprefix $(PUSH_DIR), $(PUSH_OBJ_NAME))

CHECK_SRC	= $(addprefix $(CHECK_DIR), $(CHECK_SRC_NAME))
CHECK_OBJ	= $(addprefix $(CHECK_DIR), $(CHECK_OBJ_NAME))

.c.o :
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(PUSH_OBJ)
			@$(CC) $(CFLAGS) $(PUSH_OBJ) -o $(NAME)
			@echo "Creating push_swap"

$(CHECK_NAME) : $(CHECK_OBJ)
			@$(CC) $(CFLAGS) $(CHECK_OBJ) -o $(CHECK_NAME)
			@echo "Creating checker"
			
all :		$(NAME)

bonus :		$(CHECK_NAME)
			
clean :
			@$(RM) $(PUSH_OBJ) $(CHECK_OBJ)
			@echo ".o files erased"

fclean :	clean
			@$(RM) $(NAME) $(CHECK_NAME)
			@echo "exec files erased"

re :		
			@make fclean
			@make all

rebonus : 	
			@make fclean
			@make bonus

.PHONY :	all bonus clean fclean re rebonus
