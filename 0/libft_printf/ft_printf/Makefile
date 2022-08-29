CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS	= ft_printf.c get_functions.c additional_functions.c \
		print_functions.c buffer_functions.c

OBJS	= $(SRCS:.c=.o)

HEADER	= ft_printf.h
NAME	= libftprintf.a

RM		= rm -f
AR		= ar rcs

.c.o :
			@$(CC) $(CFLAGS) -c $< -o $@

all :		$(NAME)


$(NAME) :	$(OBJS)
			@$(AR) $@ $^

bonus : 	$(NAME)

clean :
			@$(RM) $(OBJS) $(B_OBJS)

fclean :	clean
			@$(RM) $(NAME)

re :		fclean
			@make all

.PHONY :	all bonus clean fclean re
