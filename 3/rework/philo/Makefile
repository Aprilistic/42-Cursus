# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 17:24:07 by jinheo            #+#    #+#              #
#    Updated: 2022/09/18 15:35:01 by jinheo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = main.c delete.c routine.c philosopher_routine.c print.c set.c utility.c initialize.c
OBJS = $(SRCS:.c=.o)

.c.o :
			@$(CC) $(CFLAGS) -c $< -o $@

NAME = philo

$(NAME) : $(OBJS)
		@echo "Making .o files..."
		@$(CC) $(CFLAGS) -lpthread -o $@ $^

all :
		@echo "Making exec files..."
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
