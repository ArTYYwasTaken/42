# Variables
INCDIR = ./includes/
SRCDIR = ./srcs/
OBJDIR = ./objs/
LIBDIR = ./libft/
SRC_FILES = ft_printf.c ft_printfchar.c ft_printftstring.c ft_printfhex.c \
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
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAMELFT) $(NAME)

$(NAMELFT):
	@$(MAKE) -C $(LIBDIR)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -I$(INCDIR) -I$(LIBDIR) $< -o $@

clean:
	$(RM) $(OBJS)
	cd $(LIBDIR) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	cd $(LIBDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re