# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taeypark <taeypark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 14:19:56 by jinheo            #+#    #+#              #
#    Updated: 2023/03/02 21:18:03 by taeypark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT

SRCS	= main_bonus.c \
		vec3/vec3_util_bonus.c vec3/vec3_util2_bonus.c \
		our_mlx/our_mlx_bonus.c our_mlx/our_mlx_utils_bonus.c \
		parse/parse_bonus.c parse/parse_util_bonus.c parse/parse_util2_bonus.c parse/parse_util3_bonus.c \
		hit/hittable_bonus.c hit/hit_bonus.c hit/hit_utils_bonus.c hit/hit_utils2_bonus.c\
		calculation/color_bonus.c calculation/brightness_bonus.c calculation/reflection_bonus.c \
		rendering/camera_bonus.c rendering/image_bonus.c

OBJS	= $(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I.
CLIB	= -lmlx -Lmlx -framework OpenGL -framework Appkit


all		: $(NAME)

bonus	: $(NAME)

.c.o	:
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
		@echo "compiling libft..."
		@make all -s -C libft
		@echo "compiling mlx..."
		@make all -s -C mlx 2> /dev/null
		@echo "compiling all..."
		@$(CC) $(CFLAGS) $(CLIB) $(OBJS) libft/libft.a -o $(NAME)
		@echo "done!"

clean	:
		@make clean -s -C libft
		@make clean -s -C mlx
		@rm -rf $(OBJS)
		@echo "erasing .o files"

fclean	: clean
		@make fclean -s -C libft
		@rm -rf $(NAME)
		@echo "erasing executable"

re		:
		@make fclean
		@make all

.PHONY	: all clean fclean re bonus
