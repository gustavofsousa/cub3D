NAME = libft.a
MAKEFLAGS	:= --silent

##################	Compiler	##################
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

###	Directories	####
OBJDIR	:=	obj/

##################	Sources & OBJ	##################
GNL		= get_nl.c	get_nl_utils.c


SRC =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c		\
		ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c			\
		ft_strnstr.c ft_strncmp.c ft_striteri.c									\
		ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_strdup.c			\
		ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c 			\
		ft_atoi.c ft_itoa.c ft_bzero.c											\
		ft_toupper.c ft_tolower.c ft_calloc.c ft_substr.c 						\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 			\
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c					\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_abs.c					\
		$(addprefix get_next_line/, $(GNL))

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

################## ft_printf		##################

# Colors
BLACK	=	\033[0;30m
BLUE	=	\033[0;34m
CYAN	=	\033[0;36m
GREEN	=	\033[0;32m
MAGENTA	=	\033[1;35m
ORANGE	=	\033[1;38;5;214m
RED		=	\033[0;31m
RESET	=	\033[0m
WHITE	=	\033[0;37m
YELLOW	=	\033[0;33m

##################	Commands	##################

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(addprefix $(OBJDIR), get_next_line/)
	@echo "directories for objects created"

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@echo "$(YELLOW)lib created$(WHITE)"

$(OBJDIR)%.o : $(SRCDIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "objects created 😉 ->$(MAGENTA) $@$(WHITE)"

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
