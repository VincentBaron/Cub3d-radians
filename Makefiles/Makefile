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

SRC = 		srcs/general_functions_1.c \
			srcs/map_parsing.c \
			srcs/program_main.c \
			srcs/starting_info.c \
			srcs/virtual_function.c \
			srcs/get_next_line.c \
			srcs/get_next_line_utils.c \

OBJS = 		${SRC:.c=.o}

INCLUDES = 	includes

NAME = 		Cub3D

CC = 		gcc

FLAGS =  	-Wall -Werror -Wextra

all:		${NAME}

-c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCLUDES}

${NAME}: 	${OBJS}
			make -C Libft
			cp Libft/libft.a ./$(NAME)
			ar -rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}
			make clean -C Libft

fclean: 	clean
			rm -f ${NAME}
			make fclean -C Libft

re: 		fclean all

.PHONY: clean all fclean re