# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 17:24:07 by jinheo            #+#    #+#              #
#    Updated: 2022/11/25 21:24:17 by jinheo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = main_bonus.c delete_bonus.c routine_philosopher_bonus.c \
	routine_control_bonus.c \
	set_data_bonus.c set_semaphore_bonus.c utility_bonus.c run_bonus.c
OBJS = $(SRCS:.c=.o)

.c.o :
			@$(CC) $(CFLAGS) -c $< -o $@

NAME = philo_bonus

$(NAME) : $(OBJS)
		@echo "Making .o files..."
		@$(CC) $(CFLAGS) -pthread -o $@ $^
		@echo "Making exec files..."

all :
		@make $(NAME)

clean :
		@echo "Erasing .o files..."
		@$(RM) $(OBJS)

fclean :
		@make clean
		@echo "Erasing exec files..."
		@$(RM) $(NAME)

re :
		@make fclean
		@make all

.PHONY : all clean fclean re
