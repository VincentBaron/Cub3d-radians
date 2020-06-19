/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:35:31 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/19 17:11:02 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

int     args_definer(t_input *args, int i)
{
        t_args *args_tab[8];
        int f;

        args_tab[0] = args->R;
        args_tab[1] = args->N;
        args_tab[2] = args->S;
        args_tab[3] = args->WE;
        args_tab[4] = args->EA;
        args_tab[5] = args->S;
        args_tab[6] = args->F;
        args_tab[6] = args->C;
        
        if (i > 0)
        {
            while (args->line[f])
        }
            
        

}

int    map_parsing(t_input *args)
{
    int res;

    args->index = "1RNSWESFC" 

    while (get_next_line(args->fd, &(args->line) != 0)
    {
        if (res == -1)
            return (-1);
        i = -1;
        while (args->line[i++] == ' ')
        if (check_charset(args->line[i], args->index) == 0)
            map_creator();
        else if (check_charset(args->line[i], args->index) > 0)
            args_definer(args, i);
    }
}