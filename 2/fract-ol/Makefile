# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 14:19:56 by jinheo            #+#    #+#              #
#    Updated: 2022/08/24 20:37:50 by jinheo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fract-ol

SRCS	= srcs/default.c srcs/formula.c srcs/from_libft.c srcs/color.c srcs/move.c\
		srcs/hook.c srcs/main.c srcs/pixel.c srcs/render.c srcs/palette.c
OBJS	= $(SRCS:.c=.o)
INCLUDES = includes/

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
CLIB	= -Lmlx -lmlx -Imlx -framework OpenGL -framework Appkit

all		: $(NAME)

.c.o	:
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
		@$(CC) $(CFLAGS) $(CLIB) $(SRCS) -I $(INCLUDES) -o $(NAME)
		@echo "compiling..."
		@echo "done!"

clean	:
		@rm -rf $(OBJS)
		@echo "erasing .o files"

fclean	: clean
		@rm -rf $(NAME)
		@echo "erasing .exec files"

bonus	: all

re		:
		@make fclean
		@make all

.PHONY	: all clean fclean re bonus
