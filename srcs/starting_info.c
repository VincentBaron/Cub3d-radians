/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:51:16 by vbaron            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/10/23 12:17:25 by vbaron           ###   ########.fr       */
=======
/*   Updated: 2020/10/23 14:49:25 by vbaron           ###   ########.fr       */
>>>>>>> coordinates_changed
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    find_direction(t_general *mother)
{
    if (mother->args.matrix[mother->gps.pos.y][mother->gps.pos.x] == 'N')
    {
        mother->gps.dir.x = -1;
        mother->gps.dir.y = 0;
    }
    if (mother->args.matrix[mother->gps.pos.y][mother->gps.pos.x] == 'S')
    {
        mother->gps.dir.x = 1;
        mother->gps.dir.y = 0;
    }
    if (mother->args.matrix[mother->gps.pos.y][mother->gps.pos.x] == 'E')
    {
        mother->gps.dir.x = 0;
        mother->gps.dir.y = 1;
    }
    if (mother->args.matrix[mother->gps.pos.y][mother->gps.pos.x] == 'W')
    {
        mother->gps.dir.x = 0;
        mother->gps.dir.y = -1;
    }
    
}

void    position_info(t_general *mother)
{
    int i;
    int f;
    
    mother->gps.pos.y = -1;
<<<<<<< HEAD
    mother->gps.width = 0;
    mother->gps.height = 0;
=======
    mother->gps.pos.x = -1;
>>>>>>> coordinates_changed
    i = 0;
    while (mother->args.matrix[i])
    {
        f = 0;
        while (mother->args.matrix[i][f])
        {
            if (mother->args.matrix[i][f] == 'N' || mother->args.matrix[i][f] == 'S' || mother->args.matrix[i][f] == 'E' || mother->args.matrix[i][f] == 'W')
            {
<<<<<<< HEAD
                mother->gps.pos.y = i;
                mother->gps.pos.x = f;
=======
                mother->gps.pos.x = f;
                mother->gps.pos.y = i;
>>>>>>> coordinates_changed
                break;
            }
            f++;
        }
        if (f > mother->gps.width)
            mother->gps.width = f;
        i++;
    }
    mother->gps.height = i;
    find_direction(mother);
    mother->gps.square = sqrtf((float)(mother->args.R[0] * mother->args.R[1]) / (float)(mother->gps.height * mother->gps.width));
    ft_putnbr_fd(mother->gps.square, 1);
    mother->gps.pix.y = ((float)mother->gps.pos.y + 0.5) * mother->gps.square; 
    mother->gps.pix.x = ((float)mother->gps.pos.x + 0.5) * mother->gps.square;
    mother->gps.plane.x = 0;
    mother->gps.plane.y = 0.66;
    mother->gps.time.x = 0;
    mother->gps.time.y = 0;
}