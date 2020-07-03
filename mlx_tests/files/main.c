/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:00:53 by vincentbaro       #+#    #+#             */
/*   Updated: 2020/07/03 16:09:04 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../mlxopengl/mlx.h"

typedef struct s9_list
{
    void *ptr_mlx;
    void *win_mlx;
    void *img;
    int *matrix;
    int bpp;
    int size_line;
    int endian;
}   t_mlx;

int main()
{
   t_mlx mlx;

   int x;
   int y;
   int sizex;
   int sizey;

    x = 498;
    y = 498;
    sizex = 0;
    sizey = sizex;
    mlx.ptr_mlx = mlx_init();
    mlx.win_mlx = mlx_new_window(mlx.ptr_mlx, 1000, 1000, "pixel");
    mlx.img = mlx_new_image(mlx.ptr_mlx, 1000, 1000);
    mlx.matrix = (int *)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_line, &mlx.endian);
    
    while (sizex < 4)
    {
        mlx.matrix[x * 1000 + y] = 0xFFFFFF;
        while(sizey < 4)
        {
            mlx.matrix[x * 1000 + y] = 0xFFFFFF;
            y++;
            sizey++;
        }
        y = y - 4;
        sizey = 0;
        sizex++;
        x++;
    }
    mlx_put_image_to_window(mlx.ptr_mlx, mlx.win_mlx, mlx.img, 0, 0);
    mlx_loop(mlx.ptr_mlx);
}