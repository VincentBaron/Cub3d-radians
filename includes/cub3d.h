/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:03:48 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/23 16:05:39 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "stdlib.h"
# include <unistd.h>
# include "../includes/get_next_line.h"
# include "../Libft/libft.h"

typedef struct s1_list
{
    int posX;
    int posY;
    int dirX;
    int dirY;
    int planeX;
    int planeY;
}   gps_list;

typedef struct s2_list
{
    int *RGB;
    char *path;
} t_text;

typedef struct s3_list
{
    int         fd;
    char        *line;
    int         **map;
    int         *R;
    t_text      NO;
    t_text      SO;
    t_text      WE;
    t_text      EA;
    t_text      S;
    t_text      F;
    t_text      C;
    char        *index;
} t_input;

typedef enum e1_list
{
    map,
    R,
    NO,
    SO,
    WE,
    EA,
    S,
    F,
    C,
} e_input;

void    error(void);
int     main(int argc, char **argv);
int     map_parsing(t_input *args);
int     check_charset(char c, char const *set);
void    args_definer(t_input *args, int x);
int     **ft_realloc(int **tab);

#endif