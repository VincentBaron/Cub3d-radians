/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:38:34 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/19 14:43:09 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    error(void)
{
    write (1, "Error\n", 6);
    return (0);
}

int main(int argc, char **argv)
{
    int fd;
    t_input args;
    
    if (argc != 2)
        error();
    if ((fd = open(argv[1])) == -1)
        error();
    map_parsing(fd, &args);
    
    return (0);
}