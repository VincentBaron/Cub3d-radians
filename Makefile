# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 17:36:15 by vbaron            #+#    #+#              #
#    Updated: 2020/10/12 11:11:13 by vbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_S = srcs
DIR_O = objs

SOURCES = general_functions_1.c \
		map_parsing.c \
		program_main.c \
		starting_info.c \
		virtual_function.c \
		get_next_line.c \
		get_next_line_utils.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
HEADERS = headers
LIBFT_DIR = Libft
MLX_DIR = mlx-macos
NAME = Cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIBS = -framework OpenGL -framework Appkit

MLX = $(addprefix $(MLX_DIR)/,libmlx.a)

LIBFT = $(addprefix $(LIBFT_DIR)/,libft.a)

all: $(LIBFT) $(MLX) $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p $(DIR_O)	
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT) $(MLX)
		$(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(LIBFT):
		 make -C $(LIBFT_DIR)

clean:
		rm -f $(OBJS)		
	rm -f $(OBJS)/*.o
	rm -rf $(DIR_O)	
	make clean -C $(LIBFT_DIR)	
	make clean -C $(MLX_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: re fclean all clean