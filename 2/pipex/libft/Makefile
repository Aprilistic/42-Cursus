# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 15:12:57 by jinheo            #+#    #+#              #
#    Updated: 2022/08/29 20:57:33 by jinheo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS	 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_strcmp.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_strncmp.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

HEADER	= libft.h
NAME	= libft.a

RM		= rm -f
AR		= ar rcs

all :		$(NAME)

$(NAME)	:	
			@echo "Compiling libft..."
			@make $(OBJS)
			@echo "Archiving libft..."
			@$(AR) $(NAME) $(OBJS)
			@echo "Done!"

.c.o:
			@${CC} ${CFLAGS} -c $< -o $@
			
clean :
			@$(RM) $(OBJS)
			@echo "Erasing .o files..."

fclean :	clean
			@$(RM) $(NAME)
			@echo "Erasing lib files..."

re :		fclean
			@make all

.PHONY :	all bonus clean fclean re
