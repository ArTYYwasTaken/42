# Name of the final executable this Makefile produces
NAME = megaphone

# CXX is the C++ compiler (C++ convention; C projects use CC)
CXX = c++
# Compiler flags:
# -Wall -Wextra : enable almost all warnings
# -Werror       : turn every warning into an error (subject rule)
# -std=c++98    : compile strictly as C++98 (subject rule)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# List of source files to compile
SRCS = megaphone.cpp

# Object file names: replace every ".cpp" with ".o" in SRCS
OBJS = $(SRCS:.cpp=.o)

# Default target: runs when you type plain "make"
all: $(NAME)

# Link rule: the executable depends on all object files.
# If an object is missing or outdated, make builds it first, then links.
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Pattern rule: any file ending in .o is built from the matching .cpp
# In the recipe: -c = compile only (no linking)
#                $< = first prerequisite (the .cpp file)
#                $@ = target name (the .o file)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean deletes the object files (keeps the binary)
clean:
	rm -f $(OBJS)

# fclean deletes the object files AND the executable
fclean: clean
	rm -f $(NAME)

# re rebuilds everything from scratch (fclean then all)
re: fclean all

# .PHONY declares these targets as commands, not files,
# so "make clean" works even if a file named "clean" exists
.PHONY: all clean fclean re
