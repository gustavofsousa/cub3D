NAME		:=	cub3D	
##MAKEFLAGS	:= --silent

####	Compilers & flags	####
CC		:=	cc
CFLAGS	:=	-Wextra -Wall -Werror -g

####	Directories	####
SRCDIR	:=	source/
OBJDIR	:=	obj/
INCDIR	:=	include/
LIBDIR	:=	libft/
LISTDIR 	:=	color texture game interpretate_map validate_map

####	Sources & objects	####
MAIN				:=	main	setup	common_libft			
INTERPRETATE_MAP	:=	interpretate_map		auxiliar
COLOR				:=	get_color	checkers
TEXTURE				:=	get_texture	cardinal_points
VALIDATE_MAP		:=	validate_map	validate_player	validate_border	validate_char
GAME				:=	render_game

SRC		:=	$(MAIN)	\
			$(addprefix interpretate_map/, $(INTERPRETATE_MAP))	\
			$(addprefix validate_map/, $(VALIDATE_MAP))	\
			$(addprefix color/, $(COLOR))	\
			$(addprefix texture/, $(TEXTURE))	\
			$(addprefix game/, $(GAME))

SRCS	:=	$(addsuffix .c, $(SRC))
OBJ		:=	$(addprefix $(OBJDIR), $(SRCS:.c=.o))

####	Libft		####
LIBLIB		:=	$(LIBDIR)libft.a

############## mlx library  for mac ##############
MLX		:= ./miniLibX/
MLX_LIB	:= $(addprefix $(MLX), libmlx.a)
MLX_INC	:= -I ./miniLibX
MLX_LNK	:= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

############## mlx library  for linux ##############
##MLX		:= ./mlx_linux
##MLX_LIB	:= $(addprefix $(MLX), mlx.a)
##MLX_INC	:= -Imlx_linux -O3
##MLX_LNK	:= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

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

######	Commands	######

all:	obj $(MLX_LIB) $(LIBLIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(addprefix $(OBJDIR), $(LISTDIR))

$(OBJDIR)%.o : $(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@
	@echo "Take a look in the objects you conceived😉 ->$(MAGENTA) $@$(WHITE)"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(LIBLIB) $(LINK) -o $@
	@echo "Let's play it! piupiu 🤪"

$(LIBLIB):
	@make -C $(LIBDIR) all
	@echo "libf lib created🙃"

$(MLX_LIB):
	make -C $(MLX)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBDIR) clean
	@echo "I deleted everything, sir 🪖👮🏻‍♂️"

fclean:	clean
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean
	@echo "I deleted even the deletion, sir 🪖👮🏻‍♂️"

re: fclean all

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --track-fds=yes ./minishell

.PHONY: re, fclean, clean, all

#$(shell echo '$@ <- Nome da regra.')
#$(shell echo '$< <- Nome da primeira dependência.')
#$(shell echo '$^ <- Lista de dependências.')
#$(shell echo '$? <- Lista de dependências mais recentes que a regra.')
#$(shell echo '$* <- Nome do arquivo sem sufixo.')