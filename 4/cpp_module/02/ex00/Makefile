# ============================================================
# Commands
# ============================================================

CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
RM			= rm -rf

# ============================================================
# Files
# ============================================================

EXECUTABLE	= First
HEADER		= Fixed.hpp
SRC			= Fixed.cpp main.cpp
OBJ			= $(SRC:.cpp=.o)


# ============================================================
# Targets
# ============================================================

.cpp.o		:
		@echo "Compiling..."
		@$(CXX) $(CXXFLAGS) -c $< -o $@


$(EXECUTABLE)		: $(OBJ)
		@echo "Creating executable '$@'..."
		@$(CXX) $(CXXFLAGS) $^ -o $@
		@echo "Done!"


# ============================================================
# Rules
# ============================================================

all			: $(EXECUTABLE)

clean		:
		@echo "Cleaning object files..."
		@$(RM) $(OBJ)

fclean		: clean
		@echo "Removing executable '$(EXECUTABLE)'..."
		@$(RM) $(EXECUTABLE)

re			: fclean
		@make all

.PHONY		: all clean fclean re
