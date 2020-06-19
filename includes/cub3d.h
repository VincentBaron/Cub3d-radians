/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:03:48 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/19 14:57:03 by vbaron           ###   ########.fr       */
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
    t_vector res;
    t_tex NO;
    t_tex SO;
    t_tex WE;
    t_tex EA;
    t_tex S;
    t_tex F;
    t_tex C;
    char *index;
} t_input;

typedef struct s_list
{
    int *RGB;
    char *path;
} t_text;

typedef struct s_list
{
    int x;
    int y;
}   t_vector;

void    error(void);
int     main(int argc, char **argv);
int     map_parsing(int fd, t_input args);
int     check_charset(char c, char const *set);