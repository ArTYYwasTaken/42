# ==========================================================================
#   Makefile -- Exercise 01 (ScavTrap)
#
#   Same 5 mandatory rules as exercise 00; we just add ScavTrap.cpp to
#   the list of source files (ScavTrap inherits from ClapTrap, so both
#   implementations must be linked together into the final executable).
# ==========================================================================

# NAME: assigned variable holding the name of the produced executable.
NAME = scavtrap

# Compiler and its flags; -std=c++98 keeps us in strict C++98 (mandatory).
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# All sources of this exercise: the test program + both robot classes.
# Objects (.o = compiled but not yet linked) are derived from SRCS.
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = ClapTrap.hpp ScavTrap.hpp

# Default target: "make" runs this first; it only needs $(NAME).
all: $(NAME)

# Link rule: merge every object file into one executable named $(NAME).
$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compile rule: each .cpp file becomes one .o object file.
# $< = the .cpp prerequisite, $@ = the .o target of this rule.
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# clean: delete object files only.
clean:
	rm -f $(OBJS)

# fclean: delete objects AND the executable (full clean).
fclean: clean
	rm -f $(NAME)

# re: clean everything, then rebuild from scratch.
re: fclean all

# .PHONY: these names are rules, never files to be checked on disk.
.PHONY: all clean fclean re
