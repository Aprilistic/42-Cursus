CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
RM			= rm -rf

NAME		= megaphone
HEADER		= ./
SRC			= megaphone.cpp
OBJ			= $(SRC:.cpp=.o)


.cpp.o			:
		@echo "Compiling..."
		@$(CXX) $(CXXFLAGS) -I $(HEADER) -o $@ -c $<

all			: $(NAME)

$(NAME)		: $(OBJ)
		@echo "Creating executable '$@'..."
		@$(CXX) $(CXXFLAGS) $^ -I $(HEADER) -o $@
		@echo "Done!"

clean		:
		@echo "Cleaning object files..."
		@RM $(OBJ)

fclean		: clean
		@echo "Removing executable '$(NAME)'..."
		@RM $(NAME)

.PHONY		: all clean fclean re
