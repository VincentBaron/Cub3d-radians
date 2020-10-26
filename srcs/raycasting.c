/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:27:55 by vbaron            #+#    #+#             */
/*   Updated: 2020/10/26 19:38:39 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void    set_texture(t_general *mother)
{
    char orientation;

    if (horizont)
}

void    draw_slice(t_general *mother, float slice)
{
    float slice_height;
    int y;

    slice_height = (1 / mother->raycast.dist_inter) * mother->raycast.dist_projection;

    y = (mother->args.R[1] - slice_height) / 2;
    set_texture(mother);
    while (y < slice_height)
    {
        draw_pixel(mother, slice, y);
        y++;
    }
}

void    draw_rays(t_general *mother)
{
    int slice;
    float angle_offset;

    mother->raycast.dist_projection = ((float)mother->args.R[0] / 2) / tanf(0.523599);
    angle_offset = 1.0472 / mother->args.R[0];
    slice = mother->args.R[0];
    mother->raycast.angle += 0.523599;
    while (slice > 0)
    {
        draw_slice(mother, slice);
        slice--;
        mother->raycast.angle -= angle_offset;
    }
}