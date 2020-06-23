/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:35:31 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/23 16:17:11 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void     args_definer(t_input *args, int x)
{
        char **splitter;
        int f;
        e_input input;

        while (args->line[f])
        {
            if (args->line[f] == '.' && x > 0)
                (input[x].path = ft_substr(args->line, f, ft_strlen(args->line));
            else if (args->line[f] >= '0' && args->line[f] <= '9')
            {
                splitter = ft_split(args->line, ", ");
                while (*splitter)
                {
                    (x == 0 ? input[x].RGB : *(input[x])) = ft_atoi(*splitter);
                    input[x])++;
                    splitter++;
                }
        }
    }
}

void    map_creator(t_input *args)
{
    int i;
    int f;
    
    i = 0;
    f = 0;
    while ((args->map)[i])
        i++;
    i--;
    (args->map)[i] = (int *)malloc(sizeof(int) * (ft_strlen(args->line) - 2));
    while (args->line[f] != '\n')
    {
        (args->map)[i][f] = *(args->line) - 48;
        f++;
        args->line++;
    }
}

int    map_parsing(t_input *args)
{
    int res;
    int i;
    int x;

    args->index = "1RNSWESFC"; 

    while ((res = get_next_line(args->fd, &(args->line))) != 0)
    {
        if (res == -1)
            return (-1);
        i = -1;
        while (args->line[i++] == ' ')
        if ((x = check_charset(args->line[i], args->index)) == 0)
        {
            args->map = ft_realloc(args->map);
            map_creator(args);
        }
        else if ((x = check_charset(args->line[i], args->index)) > 0)
            args_definer(args, x);
    }
}