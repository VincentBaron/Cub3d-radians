/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:42:53 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/22 17:47:24 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int *initialize_tab(t_input *args)
{
    t_args *args_tab[8];
    
    args_tab[0] = args->R;
    args_tab[1] = args->N;
    args_tab[2] = args->S;
    args_tab[3] = args->WE;
    args_tab[4] = args->EA;
    args_tab[5] = args->S;
    args_tab[6] = args->F;
    args_tab[7] = args->C;
    return(args_tab);
}