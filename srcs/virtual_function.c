/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:49:29 by vbaron            #+#    #+#             */
/*   Updated: 2020/09/29 17:40:37 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



void draw_square(t_general *mother)
{
     float size_x;
     float size_y;
     size_t width;
     size_t height;
     int color_wall;

     width = 0;
     height = 0;
     while (mother->args.matrix[height])
     {
          if (ft_strlen(mother->args.matrix[height]) > width)
               width = ft_strlen(mother->args.matrix[height]);
          height++;
     }
     printf("width = %d\n", (int)width);
     printf("height = %d\n", (int)height);
     size_x = mother->args.R[0] / width;
     size_y = mother->args.R[1] / height;
     printf("size_x = %d\n", (int)size_x);
     printf("size_y = %d\n", (int)size_y);

     color_wall = mlx_get_color_value(mother->mlx.ptr, 191192192);
     printf("color_wall code: %d", color_wall);
}

void draw_map(t_general *mother)
{
     draw_square(mother);
}

void    game_start(t_general *mother)
{
     printf("Win_x = %d\n", mother->args.R[0]);
     printf("Win_x = %d\n", mother->args.R[1]);
     if (!(mother->mlx.ptr = mlx_init()))
          ft_putstr_fd("Error initialising mlx", 1);
     printf("init_pointer: %p\n", mother->mlx.ptr);

     if (!(mother->mlx.win = mlx_new_window(mother->mlx.ptr, mother->args.R[0], mother->args.R[1], "J' aime les Moules Brite")))
          ft_putstr_fd("Error creating window", 1);
     draw_map(mother);
     //mlx_clear_window(mother->mlx.ptr, mother->mlx.win);
     //mlx_loop(mother->mlx.win);
}