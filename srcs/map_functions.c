/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:31:48 by vbaron            #+#    #+#             */
/*   Updated: 2020/10/23 17:59:51 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
          R = 0;
          G = 0;
          B = 0;
     }
     if (ft_strncmp(type, "out", ft_strlen(type)) == 0)
     {
          R = 172;
          G = 93;
          B = 93;
     }
     if (ft_strncmp(type, "player", ft_strlen(type)) == 0)
     {
          R = 70;
          G = 70;
          B = 70;
     }
     if (ft_strncmp(type, "sprite", ft_strlen(type)) == 0)
     {
          R = 32;
          G = 178;
          B = 170;
     }
     mother->mlx.img_map.color = (R << 16) + (G << 8) + B;
}

void draw_square(t_general *mother, char *type)
{
     int x;
     int y;

     y = 0;
     while( y <= mother->map.size_y)
     {
          x = 0;
          while (x <= mother->map.size_x)
          {
                    
               (x < 1 || x > (mother->map.size_x - 1)) || (y < 1 || y > (mother->map.size_y - 1)) ? pixel_color(mother, "out") : pixel_color(mother, type);
               draw_pixel(mother, y + mother->map.size_y * mother->map.track_y, x + mother->map.size_x * mother->map.track_x);
               x++;
          }
          y++;
     }
}

void draw_player(t_general *mother)
{
     int x;
     int y;

     if (mother->gps.move.y == -1)


     pixel_color(mother, "player");
     y = mother->map.size_y / 4;
     while( y < (3 * mother->map.size_y / 4))
     {
          x = mother->map.size_x / 4;;
          while (x < (3 * mother->map.size_x / 4))
          {
                    pixel_color(mother, "player");
                    draw_pixel(mother, x + 1 + mother->map.size_x * (mother->gps.pos.x - 0.5), y + 1 + mother->map.size_y * (mother->gps.pos.y - 0.5));
                    x++;
          }
          y++;
     }
}

/*void    draw_player(mother)
{
    while (y < (mother))
}*/

void draw_map(t_general *mother)
{
     mother->map.track_x = 0;
     mother->map.size_x = 20;
     while(mother->args.matrix[mother->map.track_x])
     {
          mother->map.track_y = 0;
          mother->map.size_y = 20;
          while (mother->args.matrix[mother->map.track_x][mother->map.track_y])
          {
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == ' ')
                    draw_square(mother, "out");
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == '1')
                    draw_square(mother, "wall");
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == '0')
                    draw_square(mother, "floor");
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == 'N' || mother->args.matrix[mother->map.track_x][mother->map.track_y] == 'S' || mother->args.matrix[mother->map.track_x][mother->map.track_y] == 'E' ||mother->args.matrix[mother->map.track_x][mother->map.track_y] == 'W')
               {
                    draw_square(mother, "floor");
                    mother->args.matrix[mother->map.track_x][mother->map.track_y] = '0';
               }
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == '2')
                    draw_square(mother, "sprite");    
               mother->map.track_y++;
          }
          mother->map.track_x++;
     }
}

/*void redefine_map(t_general *mother)
{
     char temp;
     if (mother->gps.move.y == -1 && mother->args.matrix[mother->gps.pos.y - 1][mother->gps.pos.x] == '0')
     {
          temp = mother->args.matrix[mother->gps.pos.y][mother->gps.pos.x];
          mother->args.matrix[--mother->gps.pos.y][mother->gps.pos.x] = temp;
          mother->args.matrix[mother->gps.pos.y + 1][mother->gps.pos.x] = '0';          
     }
     else if (mother->gps.move.y == 1 && mother->args.matrix[mother->gps.pos.y + 1][mother->gps.pos.x] == '0')
     {
          temp = mother->args.matrix[mother->gps.pos.y][mother->gps.pos.x];
          mother->args.matrix[++mother->gps.pos.y][mother->gps.pos.x] = temp;
          mother->args.matrix[mother->gps.pos.y - 1][mother->gps.pos.x] = '0';          
     }
     else if (mother->gps.move.x == -1 && mother->args.matrix[mother->gps.pos.y][mother->gps.pos.x - 1] == '0')
     {
          temp = mother->args.matrix[mother->gps.pos.y][mother->gps.pos.x];
          mother->args.matrix[mother->gps.pos.y][--mother->gps.pos.x] = temp;
          mother->args.matrix[mother->gps.pos.y][mother->gps.pos.x + 1] = '0';          
     }
     else if (mother->gps.move.x == +1 && mother->args.matrix[mother->gps.pos.y][mother->gps.pos.x + 1] == '0')
     {
          temp = mother->args.matrix[mother->gps.pos.y][mother->gps.pos.x];
          mother->args.matrix[mother->gps.pos.y][++mother->gps.pos.x] = temp;
          mother->args.matrix[mother->gps.pos.y][mother->gps.pos.x - 1] = '0';          
     }
}*/

void    redefine_pos(t_general *mother)
{
    if (mother->gps.move.y == -1 && mother->args.matrix[(int)(mother->gps.pos.y - 0.51)][(int)mother->gps.pos.x] == '0')
        mother->gps.pos.y -= 0.1;        
     else if (mother->gps.move.y == 1 && mother->args.matrix[(int)(mother->gps.pos.y + 0.51)][(int)mother->gps.pos.x] == '0')
        mother->gps.pos.y += 0.1;
     else if (mother->gps.move.x == -1 && mother->args.matrix[(int)mother->gps.pos.y][(int)(mother->gps.pos.x - 0.51)] == '0')
        mother->gps.pos.x -= 0.1;
     else if (mother->gps.move.x == +1 && mother->args.matrix[(int)mother->gps.pos.y][(int)(mother->gps.pos.x + 0.51)] == '0')
        mother->gps.pos.x +=0.1;
}

int  new_map(t_general *mother)
{
     mlx_destroy_image(mother->mlx.ptr, mother->mlx.img_map.image);
     mother->mlx.img_map.image = mlx_new_image(mother->mlx.ptr, mother->args.R[0], mother->args.R[1]);
     mother->mlx.img_map.addr = mlx_get_data_addr(mother->mlx.img_map.image, &(mother->mlx.img_map.bpp), &(mother->mlx.img_map.size_line), &(mother->mlx.img_map.endian));
     redefine_pos(mother);
     draw_map(mother);
     draw_player(mother);
     mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win, mother->mlx.img_map.image, 0, 0);
     return (0);
}