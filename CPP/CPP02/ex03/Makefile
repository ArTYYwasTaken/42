# -*- Makefile for ex03: BSP (point in triangle) -*-
# Same discipline as ex00-02, plus Point.cpp and bsp.cpp.
# bsp.cpp has no .hpp of its own: its single function is declared in
# Point.hpp (a natural place, since it only manipulates Points).

NAME		=	bsp

SRCS		=	main.cpp \
				Fixed.cpp \
				Point.cpp \
				bsp.cpp

# Textual substitution: .cpp -> .o for every source.
OBJS		=	$(SRCS:.cpp=.o)

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Pattern rule shared by all four sources:
# $< is the .cpp, $@ is the .o being built.
%.o:		%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
