# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 17:24:07 by jinheo            #+#    #+#              #
#    Updated: 2022/11/19 17:19:10 by jinheo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = main.c delete.c routine_philosopher.c routine_monitor.c routine_waiter.c \
	set_data.c set_mutex.c utility.c run.c
OBJS = $(SRCS:.c=.o)

.c.o :
			@$(CC) $(CFLAGS) -c $< -o $@

NAME = philo

$(NAME) : $(OBJS)
		@echo "Making .o files..."
		@$(CC) $(CFLAGS) -lpthread -o $@ $^
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

.PHONY : all clean fclean re $(NAME)
