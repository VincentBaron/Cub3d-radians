/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:49:29 by vbaron            #+#    #+#             */
/*   Updated: 2020/09/29 12:07:00 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_square(t_general *mother)
{
     int size_x;
     int size_y;

     (void)size_y;
     size_x = mother->args.R[0] / 2;
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
     printf("init_pointer: %p", mother->mlx.ptr);

     if (!(mother->mlx.win = mlx_new_window(mother->mlx.ptr, mother->args.R[0], mother->args.R[1], "J' aime les Moules Brite")))
          ft_putstr_fd("Error creating window", 1);
     draw_map(mother);
     mlx_clear_window(mother->mlx.ptr, mother->mlx.win);
     mlx_loop(mother->mlx.win);
}