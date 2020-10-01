/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:49:29 by vbaron            #+#    #+#             */
/*   Updated: 2020/10/01 15:44:19 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



void draw_square(t_general *mother)
{
     float size_x;
     float size_y;
     int x;
     int y;
     size_t width;
     size_t height;

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
     if (!((char *)mother->mlx.fill = (char *)(sizeof(char) * 4 * (width + height)))
     printf("size_x = %d\n", (int)size_x);
     printf("size_y = %d\n", (int)size_y);

     mother->mlx.img = mlx_new_image(mother->mlx.win, mother->args.R[0], mother->args.R[1]);
     mother->mlx.data = mlx_get_data_addr(mother->img, int *bits_per_pixel, int *size_line, int *endian);

     x = 0;
     while(mother->mlx.fill)

     mother->mlx.color = 
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