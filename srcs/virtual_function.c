/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:49:29 by vbaron            #+#    #+#             */
/*   Updated: 2020/10/13 15:14:36 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_square(t_general *mother, char *type)
{
     int x;
     int y;
     int R;
     int G;
     int B;

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
     y = 0;
     while( y < mother->map.size_y)
     {
          x = 0;
          while (x < mother->map.size_x)
          {
                    mother->mlx.img.addr[x + y + mother->map.track_x * mother->map.size_x + mother->map.track_y * mother->map.size_y] = (int)((R << 16) + (G << 8) + B);
                    x++;
          }
          y++;
     }
}

void draw_map(t_general *mother)
{
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
     if (!(mother->mlx.img.addr = (int *)(sizeof(int) * (mother->args.R[0] * mother->args.R[1]))))
          return ;
     mother->mlx.img.image = mlx_new_image(mother->mlx.win, mother->args.R[0], mother->args.R[1]);
     mother->mlx.img.addr = (int *)mlx_get_data_addr(mother->mlx.img.image, &mother->mlx.img.bpp, &mother->mlx.img.size_line, &mother->mlx.img.endian);
     
     mother->args.R[0] = (((mother->args.R[0] % width) == 0) ? mother->args.R[0] : mother->args.R[0] - 1);
     mother->args.R[1] = (((mother->args.R[1] % height) == 0) ? mother->args.R[1] : mother->args.R[1] - 1);
     
     mother->map.track_x = 0;
     mother->map.size_x = mother->args.R[0] / width;
     while(mother->args.matrix[mother->map.track_x])
     {
          mother->map.track_y = 0;
          mother->map.size_x = mother->args.R[0] / width;
          while (mother->args.matrix[mother->map.track_x][mother->map.track_y])
          {
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == ' ')
                    draw_square(mother, "out");
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == '1')
                    draw_square(mother, "wall");
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == '0')
                    draw_square(mother, "floor");
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == 'N' || mother->args.matrix[mother->map.track_x][mother->map.track_y] == 'S' || mother->args.matrix[mother->map.track_x][mother->map.track_y] == 'E' ||mother->args.matrix[mother->map.track_x][mother->map.track_y] == 'W')
                    draw_square(mother, "player");
               mother->map.track_y++;
               mother->map.size_y += mother->map.size_y;
          }
          mother->map.track_x++;
          mother->map.size_x += mother->map.size_x;
     }

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