# ==========================================================================
#   Makefile -- Exercise 00 (ClapTrap)
#
#   A Makefile automates compilation. You type "make" and instead of
#   remembering long compiler commands, make reads THIS file and builds
#   the program for you. It must contain the 5 mandatory rules:
#   $(NAME), all, clean, fclean, re  (same rules as in the C modules).
# ==========================================================================

# NAME is an assigned variable: the name of the final executable produced.
NAME = claptrap

# Compilation flags (subject requirement):
# -Wall  : enable all common warnings
# -Wextra: enable even more warnings
# -Werror: treat every warning as a compiling ERROR (no warning allowed!)
# -std=c++98: force the strict 1998 C++ standard (mandatory in 42 modules).
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# SRCS lists every source file (.cpp) that is part of this exercise.
# The object files (.o) and headers are listed too; wildcard is forbidden
# in the C norm's Makefile rules, and it keeps the build explicit.
SRCS = main.cpp ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = ClapTrap.hpp

# First target declared = the default target ran by plain "make".
# It simply depends on the executable, and "all" itself does nothing.
all: $(NAME)

# Rule to build the executable: link the object files together into $(NAME).
# Note: the line MUST start with a TAB, not spaces, or make refuses to run it.
$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Implicit-style rule: how to turn any .cpp file into its .o object file.
# $< = the first prerequisite (the .cpp), $@ = the target (the .o).
# -c means "compile only, do not link" (linking happens in the rule above).
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# clean: remove the object files (.o) but keep the executable.
clean:
	rm -f $(OBJS)

# fclean: "full clean" = clean + delete the executable too.
fclean: clean
	rm -f $(NAME)

# re: rebuild everything from a perfectly clean state.
re: fclean all

# .PHONY declares these rules as "not files": even if a file named "clean"
# existed, "make clean" would still run the recipe instead of doing nothing.
.PHONY: all clean fclean re
