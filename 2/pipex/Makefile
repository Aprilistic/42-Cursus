# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 15:13:12 by jinheo            #+#    #+#              #
#    Updated: 2022/08/30 12:57:40 by jinheo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS	= mandatory/pipex.c mandatory/execute.c
OBJS	= $(SRCS:.c=.o)

SRCS_B	= bonus/pipex_bonus.c bonus/execute_bonus.c
OBJS_B	= $(SRCS_B:.c=.o)

NAME	= pipex

RM		= rm -f
AR		= ar rcs

ifdef	BONUS
		TARGET_OBJS = $(OBJS_B)
else
		TARGET_OBJS = $(OBJS)
endif

all :		$(NAME)

bonus :		
			@make BONUS=1 all

libft :
			@echo "Compiling libft..."
			@make -C libft

$(NAME)	:
			@make -C libft all
			@echo "Compiling pipex..."
			@make $(TARGET_OBJS)
			@$(CC) $(CFLAGS) $(TARGET_OBJS) libft/libft.a -o $(NAME)
			@echo "Done!"
			
.c.o:
			@${CC} ${CFLAGS} -c $< -o $@

clean :
			@make -C libft clean
			@$(RM) $(OBJS) $(OBJS_B)
			@echo "Erasing .o files..."

fclean :	clean
			@make -C libft fclean
			@$(RM) $(NAME)
			@echo "Erasing .exec files..."

re :		fclean
			@make all

rebonus :	fclean
			@make bonus

.PHONY : all bonus libft clean fclean re
