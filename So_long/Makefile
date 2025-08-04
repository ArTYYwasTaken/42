# Names
NAME = so_long
NAME_BONUS = so_long_bonus

# Variables
MDTDIR = ./Mandatory/
BONUSDIR = ./Bonus/
INCDIR = includes/
SRCDIR = srcs/
OBJDIR = ./objs/
LIBSDIR = ./libs/
LIBFTDIR = $(LIBSDIR)Libft/
MLIBXDIR = $(LIBSDIR)minilibx-linux/
INC = $(addprefix $(MDT_DIR), $(INC_DIR))
INC_BONUS = $(addprefix $(BONUS_DIR), $(INC_DIR)) 
INCLUDE	+= -I $(INC) 
INCLUDE	+= -I $(INC_BONUS)

# Files
SRC_FILES = 1-so_long.c 2-gamestart.c 3-map_validation.c 4-map_validation2.c 5-file_to_image.c\
6-game_loop.c 7-key_inputs.c 8-movement.c cleaning_functions.c display_messages.c\
game_ending.c win-lose_messages

BONUS_SRC_FILES = 1-so_long_bonus.c 2-gamestart_bonus.c 3-map_validation_bonus.c 4-map_validation2_bonus.c 5-file_to_image_bonus.c\
6-randomization_bonus.c 7-game_loop_bonus.c 8-draw_map_utils_bonus.c 9-key_inputs_bonus.c 10-movement_bonus.c\
11-movement_animation_bonus.c cleaning_free_game_bonus.c cleaning_functions_bonus.c display_messages_bonus.c game_ending_bonus.c\
win-lose_messages_bonus.c

SRC = $(addprefix $(MDT_DIR), $(addprefix $(SRCDIR), $(SRC_FILES)))
SRC_BONUS = $(addprefix $(BONUS_DIR), $(addprefix $(SRCDIR), $(BONUS_SRC_FILES)))

OBJS = $(addprefix $(OBJDIR), $(notdir $(SRC:.c=.o)))
OBJS_BONUS = $(addprefix $(OBJDIR), $(notdir $(SRC_BONUS:.c=.o)))

# CMD
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -L$(MLIBXDIR) -lmlx -lXext -lX11 -lm -lz
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
	@$(MAKE) -s -C $(MLIBXDIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTDIR)libft.a $(MLX_FLAGS) -o $(NAME)
	@echo "$(PINK)Program $(NAME) created successfully.$(DEF_COLOR)"
	@echo "$(LIGHT_BLUE)Objects compiled successfully.$(DEF_COLOR)"

mlx:
	@cd $(LIBSDIR) && git clone https://github.com/42Paris/minilibx-linux.git

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $(INCLUDE) -I$(LIBFTDIR) -I$(MLIBXDIR) $< -o $@
	@echo "$(WHITE)Compiling...$(DEF_COLOR)"

bonus:	 $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFTDIR)libft.a $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "$(PINK)Program $(NAME_BONUS) Compiled!$(DEF_COLOR)"

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) clean -s -C $(LIBFTDIR)
	@cd $(MLIBXDIR) && $(MAKE) -s clean
	@echo "$(LIGHT_BLUE)so_long objs pa mrd$(DEF_COLOR)"

mlxclean:
	@rm -rf $(MLIBXDIR)
	@echo "$(LIGHT_BLUE)MLX deleted$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -s -C $(LIBFTDIR)
	@echo "$(LIGHT_BLUE)so_long pa mrd$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re