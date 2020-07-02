/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:00:53 by vincentbaro       #+#    #+#             */
/*   Updated: 2020/07/02 22:31:22 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../mlx/mlx.h"

typedef struct s9_list
{
    void *ptr_mlx;
    void *win_mlx;
}   t_mlx;

int main()
{
   t_mlx mlx;

   mlx.ptr_mlx = mlx_init();
   mlx.win_mlx = mlx_new_window(mlx.ptr_mlx, 500, 500, "pixel");
   mlx_loop(mlx.ptr_mlx);
}