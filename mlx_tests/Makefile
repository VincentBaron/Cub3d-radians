# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/02 22:35:50 by vincentbaro       #+#    #+#              #
#    Updated: 2020/07/02 22:36:45 by vincentbaro      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = clang
CFLAGS = -Wall -Wextra -Werror
MLX = mlxopengl
LXFLAGS = -lmlx -framework OpenGL -framework AppKit
SRC = main
FIL = $(addsuffix .c, $(addprefix files/, $(SRC)))
OBJ = $(FIL:.c=.o)
BIN = $(addsuffix .o, $(SRC))
.PHONY: all
all: $(NAME)
$(NAME): $(OBJ)
	@echo "\n\033[0;33mCompiling..."
	$(CC) -o $(NAME) -L $(MLX) $(LXFLAGS) $(OBJ)
	@echo "\033[0m"