# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 17:36:15 by vbaron            #+#    #+#              #
#    Updated: 2020/09/28 10:41:03 by vincentbaro      ###   ########.fr        #
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

SRCS =	general_functions_1.c \
			map_parsing.c \
			program_main.c \
			starting_info.c \
			virtual_function.c \
			get_next_line.c \
			get_next_line_utils.c \

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I.
LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
MLX				= libmlx.dylib

NAME			= cub3D

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .

clean:
				@$(MAKE) -C mlx clean
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)

.PHONY:			all clean fclean re