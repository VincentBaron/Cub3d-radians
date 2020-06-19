/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:35:31 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/19 15:19:16 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

int    map_parsing(int fd, t_input *args)
{
    char *line;
    int res;

    args->index = "1NSWESFC" 

    while (get_next_line(fd, &line) != 0)
    {
        if (res == -1)
            return (-1);
        i = -1;
        while (line[i++] == ' ')
        if (check_charset(line[i], args->index) == 0)
            map_creator();
        else if (check_charset(line[i], args->index) > 0)
            args_definer();
        
        
    }

}