/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:35:31 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/23 18:37:04 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    splitter_alloc(t_input *args)
{
    char **splitter
    int x;

    splitter = ft_split(&(args->line[args->tracker]), ", ");
    if (args->index_i == 1)
    {
        args->R[0] = ft_atoi(splitter[0]);
        args->R[1] = ft_atoi(splitter[1]);
    }
    x = 0;
    else
    {
        while (*splitter && x < 3)
        {
            if (args->index_i == 2)
                args->NO->RGB[x] = ft_atoi(*splitter);
            if (args->index_i == 3)
                args->SO->RGB[x] = ft_atoi(*splitter);
            if (args->index_i == 4)
                args->WE->RGB[x] = ft_atoi(*splitter);
            if (args->index_i == 5)
                args->EA->RGB[x] = ft_atoi(*splitter);
            if (args->index_i == 6)
                args->S->RGB[x] = ft_atoi(*splitter);
            if (args->index_i == 7)
                args->F->RGB[x] = ft_atoi(*splitter);
            if (args->index_i == 8)
                args->C->RGB[x] = ft_atoi(*splitter);
            x++;
            splitter++;
        }
    }
     
}

void     args_definer(t_input *args)
{
        char **splitter;
        
        while (args->line[args->tracker])
        {
            if (args->line[args->tracker] == '.' && args->index_i == 2)
                (args->NO->path = ft_substr(args->line, f, ft_strlen(args->line));
            if (args->line[args->tracker] == '.' && args->index_i == 3)
                (args->S0->path = ft_substr(args->line, f, ft_strlen(args->line));
            if (args->line[args->tracker] == '.' && args->index_i == 4)
                (args->WE->path = ft_substr(args->line, f, ft_strlen(args->line));
            if (args->line[args->tracker] == '.' && args->index_i == 5)
                (args->EA->path = ft_substr(args->line, f, ft_strlen(args->line));
            if (args->line[args->tracker] == '.' && args->index_i == 6)
                (args->S->path = ft_substr(args->line, f, ft_strlen(args->line));
            if (args->line[args->tracker] == '.' && args->index_i == 7)
                (args->F->path = ft_substr(args->line, f, ft_strlen(args->line));
            if (args->line[args->tracker] == '.' && args->index_i == 8)
                (args->C->path = ft_substr(args->line, f, ft_strlen(args->line));
            
            else if (args->line[args->tracker] >= '0' && args->line[args->tracker] <= '9')
            {
                splitter_alloc(t_input args);
        }
    }
}

void    map_creator(t_input *args)
{
    int i;
    int args->tracker;
    
    i = 0;
    args->tracker = 0;
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

    args->index = "1RNSWESFC"; 

    while ((res = get_next_line(args->fd, &(args->line))) != 0)
    {
        if (res == -1)
            return (-1);
        i = -1;
        while (args->line[args->tracker++] == ' ')
        if ((args->index_i = check_charset(args->line[args->tracker], args->index)) == 0)
        {
            args->map = ft_realloc(args->map);
            map_creator(args);
        }
        else if ((args->index_i = check_charset(args->line[args->tracker], args->index)) > 0)
            args_definer(args, args->index_i);
    }
}