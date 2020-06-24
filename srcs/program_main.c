/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:38:34 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/24 16:38:21 by vbaron           ###   ########.fr       */
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
    if ((mother.args.fd = open("test.txt", O_RDONLY)) == -1)
        error();
    map_parsing(&(mother.args));
    position_info(&mother);
    return (0);
}