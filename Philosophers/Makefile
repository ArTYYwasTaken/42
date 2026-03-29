# ================================= NAME =================================== #

NAME = philo

# =============================== DIRECTORIES =============================== #

SRCDIR		= srcs/
OBJDIR		= objs/
INCDIR		= includes/

# ================================= FILES =================================== #

SRC_FILES	= philo.c philostart.c philostart_utils.c mutex.c threads.c \
			routine_main.c routine_helpers.c routine_actions.c monitor.c \
			cleanup.c \
			utils.c utils_ft.c

SRC = $(addprefix $(SRCDIR), $(SRC_FILES)) \

# ================================ OBJECTS =================================== #

OBJS = $(addprefix $(OBJDIR), $(SRC:$(SRCDIR)%.c=%.o))

# =============================== COMPILER ================================== #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
PTHREAD			= -pthread
INCLUDES		= -I$(INCDIR)
RM				= rm -f
MAKE			= make

# ================================= COLORS =================================== #

DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
LIGHT_BLUE	= \033[38;2;85;205;252m
PINK		= \033[38;2;247;168;184m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

# ================================= RULES ==================================== #

all: $(NAME)

# --------------------------------- Targets ---------------------------------- #
$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(PTHREAD) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(DEF_COLOR)"

# ----------------------------- Object Files -------------------------------- #
$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(dir $@)
	@echo "$(CYAN)Compiling $<...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(PTHREAD) $(INCLUDES) -c $< -o $@

# ------------------------------ Clean Rules -------------------------------- #
clean:
	@echo "$(RED)Cleaning object files...$(DEF_COLOR)"
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)✓ Object files cleaned!$(DEF_COLOR)"

fclean: clean
	@echo "$(RED)Cleaning executables...$(DEF_COLOR)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✓ All files cleaned!$(DEF_COLOR)"

re: fclean all

# ------------------------------- Phony Targets ----------------------------- #
.PHONY: all clean fclean re