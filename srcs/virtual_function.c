/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:49:29 by vbaron            #+#    #+#             */
/*   Updated: 2020/10/18 00:09:22 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_pixel(t_general *mother, int x, int y)
{
     char *dest;
     
     dest = (mother->mlx.img_map.addr +  x * (mother->mlx.img_map.bpp / 8) + y * mother->mlx.img_map.size_line);
     *(unsigned int *)dest = mother->mlx.img_map.color;
}

void   pixel_color(t_general *mother, char *type)
{
     unsigned int R;
     unsigned int G;
     unsigned int B;

     if (ft_strncmp(type, "floor", ft_strlen(type)) == 0)
     {
          R = 255;
          G = 255;
          B = 255;
     }
     if (ft_strncmp(type, "wall", ft_strlen(type)) == 0)
     {
          R = 211;
          G = 211;
          B = 211;
     }
     if (ft_strncmp(type, "out", ft_strlen(type)) == 0)
     {
          R = 0;
          G = 0;
          B = 0;
     }
     if (ft_strncmp(type, "player", ft_strlen(type)) == 0)
     {
          R = 70;
          G = 70;
          B = 70;
     }
     mother->mlx.img_map.color = (R << 16) + (G << 8) + B;
}

void draw_square(t_general *mother, char *type)
{
     int x;
     int y;

     pixel_color(mother, type);
     y = 0;
     while( y < mother->map.size_y)
     {
          x = 0;
          while (x < mother->map.size_x)
          {
                    draw_pixel(mother, y + mother->map.size_y * mother->map.track_y, x + mother->map.size_x * mother->map.track_x);
                    x++;
          }
          y++;
     }
}

void draw_map(t_general *mother)
{
     mother->map.track_x = 0;
     mother->map.size_x = 40;
     while(mother->args.matrix[mother->map.track_x])
     {
          mother->map.track_y = 0;
          mother->map.size_y = 40;
          while (mother->args.matrix[mother->map.track_x][mother->map.track_y])
          {
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == ' ')
                    draw_square(mother, "out");
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == '1')
                    draw_square(mother, "wall");
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == '0')
                    draw_square(mother, "floor");
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == 'N' || mother->args.matrix[mother->map.track_x][mother->map.track_y] == 'S' || mother->args.matrix[mother->map.track_x][mother->map.track_y] == 'E' ||mother->args.matrix[mother->map.track_x][mother->map.track_y] == 'W')
                    draw_square(mother, "floor");
               mother->map.track_y++;
          }
          mother->map.track_x++;
     }
}

int  new_map(t_general *mother)
{
     printf("waza");
     return(0);
}

void    game_start(t_general *mother)
{    
     if (!(mother->mlx.ptr = mlx_init()))
          ft_putstr_fd("Error initialising mlx", 1);
     if (!(mother->mlx.win = mlx_new_window(mother->mlx.ptr, mother->args.R[0], mother->args.R[1], "J' aime les Moules Brite")))
          ft_putstr_fd("Error creating window", 1);
     /*width = 0;
     height = 0;
     while (mother->args.matrix[height])
     {
          if ((int)ft_strlen(mother->args.matrix[height]) > width)
               width = (int)ft_strlen(mother->args.matrix[height]);
          height++;
     }*/
     //mother->args.R[0] = (((mother->args.R[0] % width) == 0) ? mother->args.R[0] : mother->args.R[0] - 1);
     //mother->args.R[1] = (((mother->args.R[1] % height) == 0) ? mother->args.R[1] : mother->args.R[1] - 1);
     mlx_key_hook(mother->mlx.ptr, 2, 0, &new_map, mother)
     mother->mlx.img_map.image = mlx_new_image(mother->mlx.ptr, mother->args.R[0], mother->args.R[1]);
     mother->mlx.img_perso.image = mlx_new_image(mother->mlx.ptr, mother->args.R[0], mother->args.R[1]);
     mother->mlx.img_map.addr = mlx_get_data_addr(mother->mlx.img_map.image, &(mother->mlx.img_map.bpp), &(mother->mlx.img_map.size_line), &(mother->mlx.img_map.endian));
     draw_map(mother);
     mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win, mother->mlx.img_map.image, 0, 0);
     mlx_destroy_image(mother->mlx.ptr, mother->mlx.img_map.image);
     mlx_loop(mother->mlx.ptr);
}