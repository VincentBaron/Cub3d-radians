/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:00:53 by vincentbaro       #+#    #+#             */
/*   Updated: 2020/07/03 22:02:31 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../mlxopengl/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s9_list
{
    void *ptr_mlx;
    void *win_mlx;
    void *img;
    int *matrix;
    int bpp;
    int size_line;
    int endian;
    int x;
    int y;
}   t_mlx;

void    write_square(t_mlx *mlx)
{
    int x;
    int y;
    
    x = mlx->x;
    y = mlx->y;
    while (x < mlx->x + 15)
    {
        y = mlx->y;
        mlx->matrix[x * 1000 + y] = 0x00FF0000;
        while(y < mlx->y + 15)
        {
            mlx->matrix[x * 1000 + y] = 0x00FF0000;
            y++;
        }
        x++;
    }
}

int keypress(int keycode, t_mlx *mlx)
{
    if (keycode == 13)
        mlx->y -= 5;
    else if (keycode == 1)
        mlx->y += 5;
    else if (keycode == 2)
        mlx->x -= 5;
    else if (keycode == 0)
        mlx->x += 5;
    mlx_destroy_image(mlx->ptr_mlx, mlx->img);
    mlx->img = mlx_new_image(mlx->ptr_mlx, 1000, 1000);
    write_square(mlx);
    mlx_put_image_to_window(mlx->ptr_mlx, mlx->win_mlx, mlx->img, 0, 0);
    return 0;
}

int main(void)
{
   t_mlx mlx;

    mlx.x = 500;
    mlx.y = 500;
    mlx.ptr_mlx = mlx_init();
    mlx.win_mlx = mlx_new_window(mlx.ptr_mlx, 1000, 1000, "pixel");
    mlx.img = mlx_new_image(mlx.ptr_mlx, 1000, 1000);
    mlx.matrix = (int *)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_line, &mlx.endian);
    mlx_key_hook(mlx.win_mlx, keypress, &mlx);
    mlx_loop(mlx.ptr_mlx);
    return 0;
}
