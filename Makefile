# Library Name #
NAME	=	cub3D

# Mandatory Variables #
SRCS	=	./source/main.c ./source/render_game.c

# Libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft
INC			=	-I. -I$(LIBFT_DIR)

# Compiling Variables #
CC		=	cc
CFLAGS»·=	-Wall -Wextra -Werror
RM		=	rm -f

# Colors #
GREEN	=	\e[32m
YELLOW	=	\e[33m
RESET	=	\e[0m
_SUCCESS	=	✅ $(GREEN)Successfully compiled$(RESET)
_INFO		=	ℹ️  $(YELLOW)Info$(RESET)

# Functions #
$(NAME): $(SRCS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C miniLibX all &> /dev/null
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(INC) -Ofast -LminiLibX -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "$(_SUCCESS) cub3D is ready.\n"

all: $(NAME)

clean:
	@$(RM) *.o */*.o */*/*.o
	@printf "$(_INFO) libft removed.\n"
	@printf "$(_INFO) cub3D removed.\n"

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) *.a */*.a */*/*/*.a

re:		fclean all

mandatory:	$(NAME)

m	:	mandatory

.PHONY:	all clean fclean re mandatory m