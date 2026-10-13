# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/11 00:00:00 by kelle             #+#    #+#              #
#    Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brain             # Name of the final executable

CC = c++                 # The modules must be compiled with c++
CFLAGS = -Wall -Wextra -Werror -std=c++98   # Mandatory flags, plus C++98 compliance
CPPFLAGS_HEAD = -I.      # Preprocessor flag: where to find the headers

SRCS = main.cpp          # Every source of the program (single-file exercise)
OBJS = $(SRCS:.cpp=.o)   # Object files are derived from the sources (.cpp -> .o)

all: $(NAME)             # Default target: just build the executable

$(NAME): $(OBJS)         # Link step: all objects together produce the executable
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp               # Every object depends on its own source file only
	$(CC) $(CFLAGS) -c -o $@ $< $(CPPFLAGS_HEAD)

clean:                   # Remove all object files (keep the sources!)
	rm -f $(OBJS)

fclean: clean            # Remove the objects AND the executable
	rm -f $(NAME)

re: fclean all           # Rebuild from scratch: clean then all

.PHONY: all clean fclean re   # Declared phony so they never clash with real files
