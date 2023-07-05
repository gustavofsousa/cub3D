NAME		:=	cub3D	
##MAKEFLAGS	:= --silent

####	Compilers & flags	####
CC		:=	cc
CFLAGS	:=	-g -Wextra -Wall -Werror

####	Directories	####
SRCDIR	:=	source/
OBJDIR	:=	obj/
INCDIR	:=	include/
LIBDIR	:=	libft/
LISTDIR 	:=	color texture game interpretate_map validate_map	raycast	minimap	movements

####	Sources & objects MANDATORY	####

MAIN				:=	main	setup	common_libft	pixel_put
MANDATORY			:=	render_game			hooks_keyboard
BONUS				:=	render_game_bonus	hooks_keyboard_bonus

INTERPRETATE_MAP	:=	interpretate_map	auxiliar	transform_map
COLOR				:=	get_color	checkers
TEXTURE				:=	get_texture	cardinal_points
VALIDATE_MAP		:=	validate_map	validate_player	validate_border	validate_char			\
						validate_up_down	validate_left_right	validate_middle
RAYCAST				:=	background	ray_config	texture_config	paint_walls		utils	utils2
MOVEMENTS			:=	turn	walk

MINIMAP				:=	draw_map2d_bonus	draw_miniplayer_bonus	bresenham_bonus

SRC		:=	$(MAIN)												\
			$(MANDATORY)										\
			$(addprefix interpretate_map/, $(INTERPRETATE_MAP))	\
			$(addprefix validate_map/, $(VALIDATE_MAP))			\
			$(addprefix color/, $(COLOR))						\
			$(addprefix texture/, $(TEXTURE))					\
			$(addprefix game/, $(GAME))							\
			$(addprefix raycast/, $(RAYCAST))					\
			$(addprefix movements/, $(MOVEMENTS))

SRCS	:=	$(addsuffix .c, $(SRC))
OBJ		:=	$(addprefix $(OBJDIR), $(SRCS:.c=.o))


####	Sources & objects	 BONUS  ####

SRC_BONUS	:=	$(MAIN)												\
				$(BONUS)											\
				$(addprefix interpretate_map/, $(INTERPRETATE_MAP))	\
				$(addprefix validate_map/, $(VALIDATE_MAP))			\
				$(addprefix color/, $(COLOR))						\
				$(addprefix texture/, $(TEXTURE))					\
				$(addprefix game/, $(GAME))							\
				$(addprefix raycast/, $(RAYCAST))					\
				$(addprefix movements/, $(MOVEMENTS))				\
				$(addprefix minimap/, $(MINIMAP))

SRCS_BONUS	:=	$(addsuffix .c, $(SRC_BONUS))
OBJ_BONUS		:=	$(addprefix $(OBJDIR), $(SRCS_BONUS:.c=.o))


####	Libft		####
LIBLIB		:=	$(LIBDIR)libft.a

####	defining OS name variable	####
UNAME := $(shell uname)

#----------------- mlx library  for mac ---------------
ifeq ($(UNAME), Darwin)
	MLX		:= ./miniLibX/
	MLX_LIB	:= $(addprefix $(MLX), libmlx.a	)
	MLX_INC	:= -I ./miniLibX
	MLX_LNK	:= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit
endif

#----------------- mlx library  for linux ---------------
ifeq ($(UNAME), Linux)
	MLX		:= ./mlx_linux
	MLX_LIB	:= $(addprefix $(MLX), mlx.a)
	MLX_INC	:= -Imlx_linux -O3
	MLX_LNK	:= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

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
_SUCCESS	=	✅ $(GREEN)Successfully compiled$(RESET)
_INFO		=	ℹ️ $(YELLOW)Info$(RESET)

######	Commands	######

all:	obj $(MLX_LIB) $(LIBLIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(addprefix $(OBJDIR), $(LISTDIR))

$(OBJDIR)%.o : $(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(LIBLIB) $(LINK) -o $@
	@printf "$(_SUCCESS) cub3d is ready.\n"

$(LIBLIB):
	@make -C $(LIBDIR) all
	@printf "$(_SUCCESS) libft is ready.\n"

$(MLX_LIB):
	make -C $(MLX)

bonus: obj $(MLX_LIB) $(LIBLIB) $(OBJ_BONUS) $(NAME)
		@printf "$(_SUCCESS) bonus is ready.\n"



clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBDIR) clean
	@printf "$(_INFO) libft removed.\n"
	@printf "$(_INFO) cub3d removed.\n"

fclean:	clean
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --track-fds=yes ./${NAME}

norm:
	@norminette include libft source

.PHONY: re, fclean, clean, all
