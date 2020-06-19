/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:03:48 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/18 14:14:35 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_list
{
    int posX;
    int posY;
    int dirX;
    int dirY;
    int planeX;
    int planeY;
}   gps_list;

typedef struct s_list
{
    int **map;
    int resX;
    int resY;
    t_tex NO;
    t_tex SO;
    t_tex WE;
    t_tex EA;
    t_tex S;
    t_tex F;
    t_tex C;
} t_input;

typedef struct s_list
{
    int *RGB;
    char *path;
} t_text;