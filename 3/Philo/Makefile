# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 19:35:26 by jinheo            #+#    #+#              #
#    Updated: 2022/09/08 16:19:27 by jinheo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
#CFLAGS = -Wall -Wextra -Werror

SRCS = philo/practice.c
OBJS = $(SRCS:.c=.o)

NAME = test

.c.o :
		@$(CC) $(CFLAGS) -c $< -o $@

all	: $(NAME)

$(NAME) :
		@echo "Compiling .c files..."
		@make $(OBJS)
		@echo "Compiling .o files..."
		@$(CC) $(CFLAGS) -lpthread $(OBJS) -o $(NAME)
		@echo "Done!"


clean :
		@echo "Erasing .o files..."
		@rm -rf $(OBJS)
		@echo "Done!"
		

fclean :
		@make clean
		@echo "Erasing exec files..."
		@rm -rf $(NAME)
		@echo "Done!"

re :
		@make fclean
		@make all
