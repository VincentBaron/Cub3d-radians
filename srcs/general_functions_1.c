/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:42:53 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/24 16:39:14 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strdup_map(char *s)
{
	char	*dup;
	int		size;
	int		i;

	size = 0;
	while (s[size])
		size++;
	if (!(dup = malloc(sizeof(char) * (size + 2))))
		return (0);
	i = 0;
	while (i < size)
	{
		dup[i] = s[i];
		i++;
	}
    dup[i] = 'x';
    i++;
	dup[i] = '\0';
    ft_free (s);
	return (dup);
}