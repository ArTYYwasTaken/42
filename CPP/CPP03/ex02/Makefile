# ==========================================================================
#   Makefile -- Exercise 02 (FragTrap)
#
#   Same structure as ex01's Makefile: we simply add FragTrap.cpp to the
#   build. Every source file of the exercise family must be linked in.
# ==========================================================================

# NAME: the name of the final executable this Makefile produces.
NAME = fragtrap

# Compiler with the subject's mandatory warning/standard flags.
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# All sources of this exercise: tests + the three class implementations.
# OBJS = the same list with .o extensions, HEADERS = header dependencies.
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

# Default rule: plain "make" builds $(NAME).
all: $(NAME)

# Link all objects together into the executable.
$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compile each .cpp into its own .o object file.
# $< expands to the .cpp file, $@ expands to the .o target.
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# clean: remove object files, keep the binary.
clean:
	rm -f $(OBJS)

# fclean: remove objects AND the binary.
fclean: clean
	rm -f $(NAME)

# re: full rebuild (clean + all).
re: fclean all

# .PHONY: these rules are commands, not files to compare timestamps with.
.PHONY: all clean fclean re
