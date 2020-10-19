/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:49:29 by vbaron            #+#    #+#             */
/*   Updated: 2020/10/19 10:26:34 by vbaron           ###   ########.fr       */
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
                    draw_square(mother, "player");
               mother->map.track_y++;
          }
          mother->map.track_x++;
     }
}

void redefine_map(t_general *mother)
{
     char temp;
     ft_putstr_fd("Redefine1", 1);
     if (mother->gps.move.x == 1)
     {
          temp = mother->args.matrix[mother->gps.pos.x][mother->gps.pos.y];
          mother->args.matrix[mother->gps.pos.x--][mother->gps.pos.y] = temp;
          mother->args.matrix[mother->gps.pos.x + 1][mother->gps.pos.y] = '0';          
     }
     if (mother->gps.move.y == 1)
     {
          temp = mother->args.matrix[mother->gps.pos.x][mother->gps.pos.y];
          mother->args.matrix[mother->gps.pos.x++][mother->gps.pos.y] = temp;
          mother->args.matrix[mother->gps.pos.x - 1][mother->gps.pos.y] = '0';          
     }
     if (mother->gps.move.x == -1)
     {
          temp = mother->args.matrix[mother->gps.pos.x][mother->gps.pos.y];
          mother->args.matrix[mother->gps.pos.x][mother->gps.pos.y--] = temp;
          mother->args.matrix[mother->gps.pos.x][mother->gps.pos.y + 1] = '0';          
     }
     if (mother->gps.move.y == -1)
     {
          temp = mother->args.matrix[mother->gps.pos.x][mother->gps.pos.y];
          mother->args.matrix[mother->gps.pos.x][mother->gps.pos.y++] = temp;
          mother->args.matrix[mother->gps.pos.x][mother->gps.pos.y - 1] = '0';          
     }
          ft_putstr_fd("Redefine2", 1);
}

int  new_map(t_general *mother)
{
     
     ft_putstr_fd("NewMap1", 1);
     mother->mlx.img_map.addr = mlx_get_data_addr(mother->mlx.img_map.image, &(mother->mlx.img_map.bpp), &(mother->mlx.img_map.size_line), &(mother->mlx.img_map.endian));
     redefine_map(mother);
     draw_map(mother);
     mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win, mother->mlx.img_map.image, 0, 0);
     //mlx_destroy_image(mother->mlx.ptr, mother->mlx.img_map.image);
     ft_putstr_fd("NewMap2", 1);
     return (0);
}

int key_press(int keycode, t_general *mother)
{
     if (keycode == UP && mother->gps.move.x == 0)
          mother->gps.move.x = 1;
     if (keycode == DOWN && mother->gps.move.x == 0)
          mother->gps.move.x = -1;
     if (keycode == LEFT && mother->gps.move.y == 0)
          mother->gps.move.y = -1;
     if (keycode == RIGHT && mother->gps.move.y == 0)
          mother->gps.move.y = 1;
     mother->gps.event = 1;
     printf("keycode: %d\n", keycode);
     return (0);
}

int key_release(int keycode, t_general *mother)
{
    if (keycode == UP && mother->gps.move.x == 1)
          mother->gps.move.x = 0;
     if (keycode == DOWN && mother->gps.move.x == -1)
          mother->gps.move.x = 0;
     if (keycode == LEFT && mother->gps.move.y == -1)
          mother->gps.move.y = 0;
     if (keycode == RIGHT && mother->gps.move.y == 1)
          mother->gps.move.y = 0;
     mother->gps.event = 0;
     return (0);
}

int events_list(t_general *mother)
{
     new_map(mother);
     return (0);
}

void    game_start(t_general *mother)
{    
     mother->gps.move.x = 0;
     mother->gps.move.y = 0;
     
     if (!(mother->mlx.ptr = mlx_init()))
          ft_putstr_fd("Error initialising mlx", 2);
     if (!(mother->mlx.win = mlx_new_window(mother->mlx.ptr, mother->args.R[0], mother->args.R[1], "J' aime les Moules Brite")))
          ft_putstr_fd("Error creating window", 2);
     //mother->args.R[0] = (((mother->args.R[0] % width) == 0) ? mother->args.R[0] : mother->args.R[0] - 1);
     //mother->args.R[1] = (((mother->args.R[1] % height) == 0) ? mother->args.R[1] : mother->args.R[1] - 1);
     ft_putstr_fd("seg1", 1);
     mother->mlx.img_map.image = mlx_new_image(mother->mlx.ptr, mother->args.R[0], mother->args.R[1]);
     mlx_hook(mother->mlx.win, KEY_PRESS, 1L<<0, &key_press, mother);
          ft_putstr_fd("seg2", 1);
     mlx_hook(mother->mlx.win, KEY_RELEASE, 1L<<1, &key_release, mother);
          ft_putstr_fd("seg3", 1);
     mlx_loop_hook(mother->mlx.ptr, &events_list, mother);
          ft_putstr_fd("seg4", 1);
     mlx_destroy_image(mother->mlx.ptr, mother->mlx.img_map.image);
     mlx_loop(mother->mlx.ptr);
          ft_putstr_fd("seg5", 1);
}