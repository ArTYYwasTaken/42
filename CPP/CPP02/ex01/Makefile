# -*- Makefile for ex01: fixed-point conversions -*-
# Same structure as ex00: $(NAME) + all/clean/fclean/re, no linking by hand.

NAME		=	fixed

SRCS		=	main.cpp \
				Fixed.cpp

# $(SRCS:.cpp=.o) = textual suffix substitution, .cpp -> .o for each file.
OBJS		=	$(SRCS:.cpp=.o)

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -f

# all is the first target, and the first target is the default one.
all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Pattern rule: any %.o is built from the matching %.cpp file.
#   $< = the first prerequisite (the .cpp), $@ = the target (the .o)
%.o:		%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
