# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 17:36:15 by vbaron            #+#    #+#              #
#    Updated: 2020/10/05 15:45:35 by vincentbaro      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

CC = gcc 

SRC_DIR = srcs

SRC =  srcs/general_functions_1.c \
	   srcs/map_parsing.c \
	   srcs/program_main.c \
	   srcs/starting_info.c \
	   srcs/virtual_function.c \
	   srcs/get_next_line.c \
	   srcs/get_next_line_utils.c \

OBJ = $(SRC:%.c=%.o)

IFLAGS = ./includes/

CFLAGS = -Wall -Wextra -Werror -lm -lbsd -lX11 -lXext -g

DIRMLX = ./mlx-linux/

DIRLIB = ./libft/

NAMELIB = libft.a

NAMEMLX = libmlx.a

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -I$(IFLAGS) -I$(DIRMLX) -I$(DIRLIB) $< -o $(<:.c=.o) 

$(NAME): $(OBJ)
	cd ./libft/ && make
	cd $(DIRMLX)/ && make
	gcc -o $(NAME) -I$(IFLAGS) -I$(DIRMLX) $(OBJ) $(DIRMLX)$(NAMEMLX) $(DIRLIB)$(NAMELIB) $(DIRMLX)/libmlx_Linux.a $(CFLAGS)

clean:
	make clean -C libft
	make clean -C $(DIRMLX)
	rm -f $(SRC_DIR)/*.o

fclean: clean
	make fclean -C libft
	make clean -C $(DIRMLX)
	rm -f $(NAME)

show:
	@echo "CFLAGS :\n  $(CFLAGS)"
	@echo "IFLAGS :\n  $(IFLAGS)"

re: fclean all



.PHONY: all clean fclean re