/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:35:31 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/22 17:36:37 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

int     args_definer(t_input *args, int x)
{
        t_args *args_tab[8];
        char *splitter;
        int f;

        args_tab[0] = args->R;
        args_tab[1] = args->N;
        args_tab[2] = args->S;
        args_tab[3] = args->WE;
        args_tab[4] = args->EA;
        args_tab[5] = args->S;
        args_tab[6] = args->F;
        args_tab[7] = args->C;

        while (args->line[f])
        {
            if (args->line[f] == '.' && x > 0)
                (args_tab[x])->path = ft_substr(args->line, f, ft_strlen(args->line))
                return (1);
            }
            else if (args->line[f] >= '0' && args->line[f] <= '9')
            {
                splitter = ft_split(args_line, ", ");
                while (*splitter)
                {
                    *(args->RGB) = ft_atoi(*splitter);
                    args->RGB++;
                    splitter++;
                }
        }
    }
}

int    map_parsing(t_input *args)
{
    int res;

    args->index = "1RNSWESFC" 

    while ((res = get_next_line(args->fd, &(args->line)) != 0)
    {
        if (res == -1)
            return (-1);
        i = -1;
        while (args->line[i++] == ' ')
        if ((x = check_charset(args->line[i], args->index)) == 0)
            map_creator();
        else if ((x = check_charset(args->line[i], args->index)) > 0)
            args_definer(args, x);
    }
}