# -*- Makefile for 42 C++ Piscine projects -*-
# Same Makefile rules as the C Norm chapter apply:
#   - You may only use $(NAME), $(SRCS), $(OBJS), $(CC), $(CFLAGS), and
#     $(RM) in your rules.
#   - Your Makefile must not link the compilation.
#   - Required targets: $(NAME), all, clean, fclean, re.
#   - "all" must be the first target of the Makefile.

# ----------------------------------------------------------------------------
# 1. VARIABLES
# ----------------------------------------------------------------------------

# The NAME of the executable we must produce.
NAME		=	fixed

# The source files to compile (main plus the Fixed class implementation).
SRCS		=	main.cpp \
				Fixed.cpp

# Object files: the same list, with .cpp changed to .o.
#   $(SRCS:.cpp=.o)  ->  replace every ".cpp" suffix with ".o"
OBJS		=	$(SRCS:.cpp=.o)

# Compiler choice; the subject says compile with "c++".
CC			=	c++

# Flags imposed by the subject. -std=c++98 keeps us C++98-pure.
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

# Remove command (a variable so the Norm does not see bare "rm -f").
RM			=	rm -f

# ----------------------------------------------------------------------------
# 2. RULES
# ----------------------------------------------------------------------------

# "all" must be the FIRST rule, and it just builds $(NAME).
all:		$(NAME)

# $^ expands to every prerequisite, i.e. all object files.
# Link them into the executable.
$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Generic compilation rule: every .o comes from the .cpp with the same name.
#   $<  = first prerequisite (the .cpp)
#   $@  = target name (the .o)
%.o:		%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean removes the object files (NOT the binary).
clean:
	$(RM) $(OBJS)

# fclean = FULL clean: object files AND the executable.
fclean:		clean
	$(RM) $(NAME)

# re = recompile everything from scratch.
re:			fclean all

# Every one of these files influences the build, so rebuild (phony) always.
.PHONY:		all clean fclean re
