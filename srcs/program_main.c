/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:38:34 by vbaron            #+#    #+#             */
/*   Updated: 2020/09/28 10:22:32 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    error(void)
{
    write (1, "Error\n", 6);
}

int main(int argc, char **argv)
{
    t_general mother;
    
    //if (argc != 2)
      //  error();
    (void)argc;
    (void)argv;
    if ((mother.args.fd = open("test.txt", O_RDONLY)) == -1)
        error();
    map_parsing(&(mother.args));
    position_info(&mother);
    virtual_world(&mother);
    return (0);
}