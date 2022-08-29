# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 15:13:12 by jinheo            #+#    #+#              #
#    Updated: 2022/08/28 19:29:11 by jinheo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
#CFLAGS = -Wall -Wextra -Werror

SRCS	= mandatory/pipex.c mandatory/execute.c
OBJS	= $(SRCS:.c=.o)

SRCS_B	= bonus/execute_bonus.c bonus/pipex_bonus.c bonus/reroute_bonus.c
OBJS_B	= $(SRCS_B:.c=.o)

NAME	= pipex

RM		= rm -f
AR		= ar rcs

all :		$(NAME)

libft :
			@echo "Compiling libft..."
			@make -C libft

$(NAME)	:	
			@echo "Compiling pipex..."
			@make $(OBJS_B)
			@make -C libft all
			@$(CC) $(OBJS_B) libft/libft.a -o $(NAME)
			@echo "Done!"

.c.o:
			@${CC} ${CFLAGS} -c $< -o $@

clean :
			@make -C libft clean
			@$(RM) $(OBJS)
			@echo "Erasing .o files..."

fclean :	clean
			@make -C libft fclean
			@$(RM) $(NAME)
			@echo "Erasing .exec files..."

re :		fclean
			@make all
