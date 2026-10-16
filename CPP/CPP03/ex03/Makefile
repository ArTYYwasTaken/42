# ==========================================================================
#   Makefile -- Exercise 03 (DiamondTrap)
#
#   Same 5 mandatory rules; only the file list grows with DiamondTrap.cpp.
#   The -Wshadow note from the subject: DiamondTrap owns a "_name" member
#   which shadows ClapTrap's private "_name". Compiling with -Wshadow
#   would warn here;   -Wshadow -Wno-shadow   silences exactly that family
#   of warnings. We keep the required flags mandatory (-Wall -Wextra
#   -Werror -std=c++98) and simply stay aware of which member is used.
# ==========================================================================

# NAME: name of the executable produced by this Makefile.
NAME = diamondtrap

# Compiler + mandatory flags (subject: -Wall -Wextra -Werror, C++98).
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# All sources: tests + the four class implementations of the family.
# OBJS derives from SRCS by replacing .cpp with .o; HEADERS drives rebuilds.
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

# Default target: "make" with no argument builds $(NAME).
all: $(NAME)

# Link rule: all object files joined into one executable.
$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compile rule: each .cpp file compiles independently into a .o object.
# $< = the .cpp source of the rule, $@ = the .o file being made.
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# clean: remove the object files, keep the executable.
clean:
	rm -f $(OBJS)

# fclean: remove object files AND the executable.
fclean: clean
	rm -f $(NAME)

# re: rebuild everything from scratch.
re: fclean all

# .PHONY: guarantees these rule names never collide with real files.
.PHONY: all clean fclean re
