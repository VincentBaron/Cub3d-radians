# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 17:36:15 by vbaron            #+#    #+#              #
#    Updated: 2020/10/02 15:34:18 by vincentbaro      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

CC = gcc

FLAGS = -Wall -Wextra -Werror

PATH_SRCS = srcs

MINILIBX = mlx-linux

LIBFT = Libft

SOURCES =   general_functions_1.c \
			map_parsing.c \
			program_main.c \
			starting_info.c \
			virtual_function.c \
			get_next_line.c \
			get_next_line_utils.c \

SRCS = $(addprefix ${PATH_SRCS}/, ${SRCS_LIST})

OBJS = $(SRCS:.c=.o)

INCLUDES = -I./includes

SGFLAGS = -g -fsanitize=address

all : $(NAME)

$(NAME) :	$(OBJS)
	@make -C $(MINILIBX) all
	@make -C $(LIBFT) all
	@$(CC) $(FLAGS) $(SGFLAGS) $(INCLUDES) $(OBJS) minilibx/*.a -L -lmlx -lX11 -lXext -lm libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@

clean:
	@rm -f $(OBJS)
	@make clean -s -C $(MINILIBX)
	@make clean -s -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus 