# Variables
INCDIR = ./includes/
SRCDIR = ./srcs/
OBJDIR = ./objs/
LIBSDIR = ./libs/
LIBFTDIR = $(LIBSDIR)Libft/
MLIBXDIR = $(LIBSDIR)minilibx-linux/
SRC_FILES = so_long.c
SRC = $(addprefix $(SRCDIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRC:.c=.o)))
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz
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
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTDIR)libft.a $(MLX_FLAGS) -o $(NAME)
	@echo "$(PINK)Program $(NAME) created successfully.$(DEF_COLOR)"
	@echo "$(LIGHT_BLUE)Objects compiled successfully.$(DEF_COLOR)"

mlx:
	@cd $(LIBSDIR) && git clone https://github.com/42Paris/minilibx-linux.git

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c -I$(INCDIR) -I$(LIBFTDIR) -I$(MLIBXDIR) $< -o $@
	@echo "$(WHITE)Compiling...$(DEF_COLOR)"

clean:
	@$(RM) $(OBJS)
	@cd $(LIBFTDIR) && $(MAKE) clean
	@cd $(MLIBXDIR) && $(MAKE) clean
	@rmdir $(OBJDIR)
	@echo "$(LIGHT_BLUE)so_long objs pa mrd$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@cd $(MLIBXDIR) && $(MAKE) fclean
	@echo "$(LIGHT_BLUE)so_long lib pa mrd$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re