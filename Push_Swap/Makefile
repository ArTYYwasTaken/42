# Name
NAME = push_swap

# Directories
INCDIR = includes/
SRCDIR = srcs/
OBJDIR = objs/
LIBFTDIR = Libft/
LIBFT = $(LIBFTDIR)libft.a
INCLUDE = -I$(INCDIR)

# Files
SRC_FILES = push_swap.c push_swap_utils.c
SRCS = $(addprefix $(MDTDIR)$(SRCDIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJDIR), $(SRC_FILES:.c=.o))

# CMD
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f
MAKE = make

# Colors
DEF_COLOR = \033[0;39m
LIGHT_BLUE = \033[38;2;85;205;252m
PINK = \033[38;2;247;168;184m
WHITE = \033[38;2;255;255;255m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(MAKE) -s -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(PINK)Program $(NAME) created successfully.$(DEF_COLOR)"
	@echo "$(LIGHT_BLUE)Objects compiled successfully.$(DEF_COLOR)"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFTDIR)

$(OBJDIR)%.o: $(MDTDIR)$(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $(INCLUDE) -I$(LIBFTDIR) $< -o $@
	@echo "$(WHITE)Compiling...$(DEF_COLOR)"

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) clean -s -C $(LIBFTDIR)
	@echo "$(LIGHT_BLUE)push_swap objs pa mrd$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -s -C $(LIBFTDIR)
	@echo "$(LIGHT_BLUE)push_swap pa mrd$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re