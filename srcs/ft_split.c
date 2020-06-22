/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_retry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:05:33 by vbaron            #+#    #+#             */
/*   Updated: 2020/02/26 16:58:06 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			check_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

int			check_size(char *str, char *charset)
{
	int size;

	size = 0;
	while (*str)
	{
		while (*str && check_charset(*str, charset) == 0)
			str++;
		if (*str && check_charset(*str, charset) == 1)
		{
			size++;
			while (*str && check_charset(*str, charset) == 1)
				str++;
		}
	}
	return (size);
}

char		*create_string(char *str, char *charset)
{
	int		z;
	char	*split;
	int		x;

	x = 0;
	z = 0;
	while (str[x] && check_charset(str[x], charset) == 1)
		x++;
	if (!(split = (char *)malloc(sizeof(char) * (x + 1))))
		return (NULL);
	x = 0;
	while (str[x] && check_charset(str[x], charset) == 0)
		x++;
	while (str[x] && check_charset(str[x], charset) == 1)
	{
		split[z] = str[x];
		z++;
		x++;
	}
	split[z] = '\0';
	return (split);
}

char		**ft_split(char *str, char *charset)
{
	int		i;
	char	**split_tab;

	if (!(split_tab = (char **)
				malloc(sizeof(char *) * (check_size(str, charset) + 1))))
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && check_charset(*str, charset) == 0)
			str++;
		if (*str && check_charset(*str, charset) == 1)
		{
			split_tab[i] = create_string(str, charset);
			i++;
			while (*str && check_charset(*str, charset) == 1)
				str++;
		}
	}
	split_tab[i] = NULL;
	return (split_tab);
}
