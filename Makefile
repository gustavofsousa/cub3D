# Library Name #
NAME=cub3D

# Sources #
SRCS=	source/main.c source/render_game.c source/engine/setup.c \
	source/engine/render.c source/engine/draw.c source/engine/hooks.c

# Libft Variables #
LIBFT=libft/libft.a

OBJ=$(SRCS:.c=.o)

# Compiling Variables #
CFLAGS=-Wall -Wextra -Werror

# Colors #
GREEN	 =	\e[32m
YELLOW	 =	\e[33m
RESET	 =	\e[0m
_SUCCESS =	✅ $(GREEN)Successfully compiled$(RESET)
_INFO    =	ℹ️ $(YELLOW)Info$(RESET)

# Functions #
%.o: %.c
	@cc  -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
		@make -s -C mlx_Linux
		@make -s -C libft
		@cc $(OBJ) $(CFLAGS) -Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -o $(NAME) $(LIBFT)
		@printf "$(_SUCCESS) $(NAME) is ready.\n"

all: $(NAME)

clean:
	@make clean -s -C mlx_Linux
	@make clean -s -C libft
	@rm -f $(OBJ)
	@printf "$(_INFO) libft removed.\n"
	@printf "$(_INFO) $(NAME) removed.\n"

fclean: clean
	@make fclean -s -C libft
	@rm -fr $(NAME)

re: fclean all

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --track-fds=yes ./$(NAME)

.PHONY: all clean fclean re
