# -*- Makefile for ex02: operator overloading -*-
# Same structure as the previous exercises: 4 mandatory targets + re,
# only $(NAME) $(SRCS) $(OBJS) $(CC) $(CFLAGS) $(RM) used in rules.

NAME		=	fixed

SRCS		=	main.cpp \
				Fixed.cpp

# Suffix substitution: every .cpp becomes a .o.
OBJS		=	$(SRCS:.cpp=.o)

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -f

# First rule == default goal. "all" builds the executable.
all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Implicit pattern rule for every .o file:
# $< is the .cpp prerequisite, $@ the .o target.
%.o:		%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
