# Name of the final executable
NAME = phonebook

# C++ compiler (C++ convention)
CXX = c++
# -Wall -Wextra -Werror : all warnings are errors (subject rule)
# -std=c++98            : compile strictly as C++98 (subject rule)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# All source files of this exercise
SRCS = main.cpp PhoneBook.cpp Contact.cpp
# Headers listed as dependencies: changing one rebuilds the objects
HEADERS = PhoneBook.hpp Contact.hpp

# Object files: ".cpp" replaced by ".o"
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(NAME)

# Link rule: build the executable from the object files.
# If an object is missing, make builds it first via the pattern rule.
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Extra dependency: every object also depends on every header,
# so editing a header triggers recompilation of the objects
$(OBJS): $(HEADERS)

# Compile rule: one .o per .cpp.
# -c = compile only; $< = the .cpp; $@ = the .o target
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

# These are commands, not files (so "make clean" always works)
.PHONY: all clean fclean re
