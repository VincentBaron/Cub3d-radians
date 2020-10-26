/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_calculations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:07:46 by vbaron            #+#    #+#             */
/*   Updated: 2020/10/26 15:56:48 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char check_collision(t_general *mother, t_float inter)
{
    if(mother->args.matrix[(int)inter.y][(int)inter.x] == 0)
        return(-1);
    return (mother->args.matrix[(int)inter.y][(int)inter.x]);
}

void    horizontal_intersection_calculation(t_general *mother)
{
    t_float inter;
    t_float offset;

    offset.x = 1.0 / tanf(mother->raycast.angle);
    offset.y = 64;

    if (mother->raycast.angle < PI && mother->raycast.angle > (0))
    {
        inter.y = ((int)(mother->gps.pos.y) - 0.01;
        inter.x = mother->gps.pos.x + (mother->gps.pos.y - inter.y) / tanf(mother->raycast.angle);
        while(check_collision(mother, inter) == -1)
        {
            inter.y -= offset.y;
            inter.x += offset.x;
        }

        mother->raycast.int_hor = sinf(mother->raycast.angle) / inter.y;
    }




}