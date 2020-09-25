# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 17:36:15 by vbaron            #+#    #+#              #
#    Updated: 2020/06/24 17:44:20 by vbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SRC = 		srcs/general_functions_1.c \
			srcs/map_parsing.c \
			srcs/program_main.c \
			srcs/starting_info.c \
			srcs/virtual_function.c \
			srcs/get_next_line.c \
			srcs/get_next_line_utils.c \

#OBJS = 		${SRC:.c=.o}

#INCLUDES = 	includes

#NAME = 		Cub3D.a

#CC = 		gcc

#FLAGS =  	-Wall -Werror -Wextra -lmlx -lXext -lX11

#all:		${NAME}

#-c.o:
#			${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCLUDES}

#${NAME}: 	${OBJS}
#			make -C Libft
#			cp Libft/libft.a ./$(NAME)
#			ar -rcs ${NAME} ${OBJS}

#clean:
#			rm -f ${OBJS}
#			make clean -C Libft

#fclean: 	clean
#			rm -f ${NAME}
#			make fclean -C Libft

#re: 		fclean all

#.PHONY: clean all fclean re

DIR_S = srcs

DIR_O = objs

SOURCES =	general_functions_1.c \
			map_parsing.c \
			program_main.c \
			starting_info.c \
			virtual_function.c \
			get_next_line.c \
			get_next_line_utils.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

HEADERS = includes

LIBFT_DIR = Libft

MLX_DIR = Mlx

NAME = Cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror  

LIBS = -L -lmlx -lx11 -lxext -lm -framework OpenGL -framework Appkit

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

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	rm -rf $(DIR_O)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: re fclean all clean