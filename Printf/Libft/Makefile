# VARIABLES
NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror -g
SRCS = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
ft_memcpy.c  ft_memmove.c  ft_memset.c  ft_strlcat.c  ft_strlcpy.c  ft_strlen.c\
ft_toupper.c ft_tolower.c ft_strchr.c ft_strdup.c ft_atoi.c ft_strrchr.c\
ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_substr.c\
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c  ft_lstlast.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

# Colors
DEF_COLOR = \033[0;39m
LIGHT_BLUE = \033[38;2;85;205;252m
PINK = \033[38;2;247;168;184m
WHITE = \033[38;2;255;255;255m

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(LIGHT_BLUE)Library check$(DEF_COLOR)"
	@echo "$(PINK)Objs check$(DEF_COLOR)"

bonus: .bonus

.bonus: $(BONUS_OBJS) $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@touch .bonus
	@echo "$(WHITE)Bonus check$(DEF_COLOR)"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(BONUS_OBJ) $(OBJS)
	@echo "$(PINK)Objs pa mrd$(DEF_COLOR)"

clean_bonus:
	@rm -f $(BONUS_OBJS) .bonus
	@echo "$(WHITE)bonus pa mrd$(DEF_COLOR)"

fclean: clean clean_bonus
	@rm -f $(NAME)
	@echo "$(PINK)Lib pa mrd${DEF_COLOR}"

re: fclean all