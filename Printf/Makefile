# Variables
INCDIR = ./includes/
SRCDIR = ./srcs/
OBJDIR = ./objs/
LIBDIR = ./Libft/
SRC_FILES = ft_printf.c ft_printfchar.c ft_printfstring.c ft_printfhex.c \
            ft_printfdecimal.c ft_printfpointer.c ft_printfunsigned.c ft_uitoa.c \
            ft_itoa_base.c ft_ulitoa_base.c
SRC = $(addprefix $(SRCDIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRC:.c=.o)))
NAME = libftprintf.a
NAMELFT = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
AR = ar rcs
MAKE = make

# Colors
DEF_COLOR = \033[0;39m
LIGHT_BLUE = \033[38;2;85;205;252m
PINK = \033[38;2;247;168;184m
WHITE = \033[38;2;255;255;255m

all: $(NAMELFT) $(NAME)

$(NAMELFT):
	@$(MAKE) -C $(LIBDIR)

$(NAME): $(OBJS) $(NAMELFT)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(PINK)Library $(NAME) created successfully.$(DEF_COLOR)"
	@echo "$(LIGHT_BLUE)Objects compiled successfully.$(DEF_COLOR)"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c -I$(INCDIR) -I$(LIBDIR) $< -o $@
	@echo "$(WHITE)Compiling...$(DEF_COLOR)"

clean:
	@$(RM) $(OBJS)
	@cd $(LIBDIR) && $(MAKE) clean
	@echo "$(LIGHT_BLUE)printf objs pa mrd$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@cd $(LIBDIR) && $(MAKE) fclean
	@echo "$(LIGHT_BLUE)libftprintf pa mrd$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re