# VARIABLES
NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SRCS = $(filter-out main.c, $(wildcard *.c))
BONUS = $(filter-out $(SRCS), $(wildcard *.c))
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c+.o)
MAIN = main

all: $(NAME) $(MAIN)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "lib foi"
	@echo "obj foi"

bonus: $(BONUS_OBJS) $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

$(MAIN): $(NAME)
	@$(CC) $(FLAGS) -I. $(MAIN).c -L. -lft $< -o $@
	@echo "main fixe"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(MAIN)
	@echo "objs pa mrd"

fclean: clean
	@rm -f $(NAME)
	@echo "lib pa mrd"

re: fclean all