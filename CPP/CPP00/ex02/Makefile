# Name of the final executable
NAME = account

# C++ compiler
CXX = c++
# All warnings are errors + strict C++98 (subject rules)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Sources: your implementation of Account + the provided test main
SRCS = Account.cpp tests.cpp
# Header dependency (provided file, do not modify)
HEADERS = Account.hpp

# Object files: ".cpp" -> ".o"
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(NAME)

# Link the executable from the two object files
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Every object also depends on the header: editing it forces a rebuild
$(OBJS): $(HEADERS)

# Compile rule: -c = compile only; $< = the .cpp; $@ = the .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove object files only
clean:
	rm -f $(OBJS)

# Remove object files AND the executable
fclean: clean
	rm -f $(NAME)

# Full rebuild
re: fclean all

# Command targets, not real files
.PHONY: all clean fclean re
