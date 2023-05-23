# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 13:13:20 by gusousa           #+#    #+#              #
#    Updated: 2023/05/23 18:18:58 by gusousa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

####	Sources & objects	####

MAIN			:=	main
##MAP_CHECK		:=	
##RENDER		:=	

SRC		:=	$(MAIN)
			##$(addprefix map_check/, $(MAP_CHECK))			\
			##$(addprefix render/, $(RENDER))			\

SRCS	:=	$(addsuffix .c, $(SRC))
OBJ		:=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

####	Libft		####
LIBLIB		:=	$(LIBDIR)libft.a

############## mlx library ##############
MLX		:= ./miniLibX/
MLX_LIB	:= $(addprefix $(MLX), mlx.a)
NAMEMLX		= libmlx.a


##LISTDIR 	:=	map_check render

#$(shell echo '$@ <- Nome da regra.')
#$(shell echo '$< <- Nome da primeira dependência.')
#$(shell echo '$^ <- Lista de dependências.')
#$(shell echo '$? <- Lista de dependências mais recentes que a regra.')
#$(shell echo '$* <- Nome do arquivo sem sufixo.')

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

all:	$(OBJDIR) $(LIBLIB) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	##@mkdir -p $(addprefix $(OBJDIR), $(LISTDIR))

$(OBJDIR)%.o : $(SRCDIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Take a look in the objects you conceived😉 ->$(MAGENTA) $@$(WHITE)"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBLIB) $(LINK) -o $@
	@echo "Let's play it! piupiu 🤪"

$(LIBLIB):
	@make -C $(LIBDIR) all
	@echo "libf lib created🙃"

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBDIR) clean
	@echo "I deleted everything, sir 🪖"

fclean:	clean
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean
	@echo "I deleted even the deletion, sir 🪖"

re: fclean all

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --track-fds=yes ./minishell

.PHONY: re, fclean, clean, all
