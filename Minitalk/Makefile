# ================================= NAMES =================================== #

CLIENT		= client
SERVER		= server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

# =============================== DIRECTORIES =============================== #

SRCDIR		= srcs/
MANDATORY	= $(SRCDIR)Mandatory/
BONUS		= $(SRCDIR)Bonus/
OBJDIR		= objs/
LIBFTDIR	= Libft/
INCDIR		= $(LIBFTDIR)includes/

# ================================= FILES =================================== #

CLIENT_SRC	= client.c
SERVER_SRC	= server.c
CLIENT_BONUS_SRC = client_bonus.c
SERVER_BONUS_SRC = server_bonus.c

# ================================ OBJECTS =================================== #

CLIENT_OBJ		= $(OBJDIR)client.o
SERVER_OBJ		= $(OBJDIR)server.o
CLIENT_BONUS_OBJ = $(OBJDIR)client_bonus.o
SERVER_BONUS_OBJ = $(OBJDIR)server_bonus.o

# ================================ LIBRARY =================================== #

LIBFT		= $(LIBFTDIR)libft.a

# =============================== COMPILER ================================== #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
INCLUDES	= -I$(INCDIR)
RM			= rm -f

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

all: $(CLIENT) $(SERVER)

# ---------------------------- Mandatory Targets ---------------------------- #
$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	@echo "$(YELLOW)Linking $(CLIENT)...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)
	@echo "$(GREEN)✓ $(CLIENT) created successfully!$(DEF_COLOR)"

$(SERVER): $(SERVER_OBJ) $(LIBFT)
	@echo "$(YELLOW)Linking $(SERVER)...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)
	@echo "$(GREEN)✓ $(SERVER) created successfully!$(DEF_COLOR)"

# ------------------------------ Bonus Targets ------------------------------ #
bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ) $(LIBFT)
	@echo "$(YELLOW)Linking $(CLIENT_BONUS)...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) $(LIBFT) -o $(CLIENT_BONUS)
	@echo "$(GREEN)✓ $(CLIENT_BONUS) created successfully!$(DEF_COLOR)"

$(SERVER_BONUS): $(SERVER_BONUS_OBJ) $(LIBFT)
	@echo "$(YELLOW)Linking $(SERVER_BONUS)...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) $(LIBFT) -o $(SERVER_BONUS)
	@echo "$(GREEN)✓ $(SERVER_BONUS) created successfully!$(DEF_COLOR)"

# ----------------------------- Object Files -------------------------------- #
$(OBJDIR)client.o: $(MANDATORY)$(CLIENT_SRC)
	@mkdir -p $(OBJDIR)
	@echo "$(CYAN)Compiling $(CLIENT_SRC)...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)server.o: $(MANDATORY)$(SERVER_SRC)
	@mkdir -p $(OBJDIR)
	@echo "$(CYAN)Compiling $(SERVER_SRC)...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)client_bonus.o: $(BONUS)$(CLIENT_BONUS_SRC)
	@mkdir -p $(OBJDIR)
	@echo "$(CYAN)Compiling $(CLIENT_BONUS_SRC)...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)server_bonus.o: $(BONUS)$(SERVER_BONUS_SRC)
	@mkdir -p $(OBJDIR)
	@echo "$(CYAN)Compiling $(SERVER_BONUS_SRC)...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ------------------------------- Library ----------------------------------- #
$(LIBFT):
	@echo "$(MAGENTA)Building libft...$(DEF_COLOR)"
	@$(MAKE) -s -C $(LIBFTDIR)
	@echo "$(GREEN)✓ libft built successfully!$(DEF_COLOR)"

# ------------------------------ Clean Rules -------------------------------- #
clean:
	@echo "$(RED)Cleaning object files...$(DEF_COLOR)"
	@$(RM) -rf $(OBJDIR)
	@$(MAKE) clean -s -C $(LIBFTDIR)
	@echo "$(GREEN)✓ Object files cleaned!$(DEF_COLOR)"

fclean: clean
	@echo "$(RED)Cleaning executables...$(DEF_COLOR)"
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@$(MAKE) fclean -s -C $(LIBFTDIR)
	@echo "$(GREEN)✓ All files cleaned!$(DEF_COLOR)"

re: fclean all

# ------------------------------- Phony Targets ----------------------------- #
.PHONY: all bonus clean fclean re
