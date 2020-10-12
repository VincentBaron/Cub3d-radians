/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:49:29 by vbaron            #+#    #+#             */
/*   Updated: 2020/10/12 15:41:09 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

fill

void draw_square(t_general *mother; char *type)
{
     int x;
     int y;

     x = 0;
     while( x < mother->)
}

void draw_map(t_general *mother)
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
     mother->map.size_x = mother->args.R[0] / width;
     mother->map.size_y = mother->args.R[1] / height;
     if (!(mother->mlx.img.addr = (char *)(sizeof(char) * 4 * (width + height))))
     printf("size_x = %d\n", (int)size_x);
     printf("size_y = %d\n", (int)size_y);

     mother->mlx.img.image = mlx_new_image(mother->mlx.win, mother->args.R[0], mother->args.R[1]);
     mother->mlx.img.addr = mlx_get_data_addr(mother->mlx.img.image, &mother->mlx.img.bpp, &mother->mlx.img.size_line, &mother->mlx.img.endian);
     
     x = 0;
     while(x < width)
     {
          y = 0;
          while (y < height)
          {
               if (mother->args.matrix[x][y] == ' ')
                    draw_square(mother, "out");
               if (mother->args.matrix[x][y] == '1')
                    draw_square(mother, "wall");
               if (mother->args.matrix[x][y] == '0')
                    draw_square(mother, "floor");
               if (mother->args.matrix[x][y] == 'N' || mother->args.matrix[x][y] == 'S' || mother->args.matrix[x][y] == 'E' ||mother->args.matrix[x][y] == 'W')
                    draw_square(mother, "player");
               y++;
          }
          x++;
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