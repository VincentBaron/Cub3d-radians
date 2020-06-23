/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 18:37:26 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/22 19:14:00 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int **ft_realloc(int **tab)
{
    int **new_tab;
    int size;

    size = 0;
    while (tab[size])
        size++;
    new_tab = (int **)malloc(sizeof(int) * (size + 1));
    size = 0;
    while (tab[size])
    {
        new_tab[size] = tab[size];
        size++;
    }
    free(tab);
    return (new_tab);
}