/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 11:51:06 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/23 15:56:06 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 30

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*ft_substr_bis(char *s, unsigned int start, size_t len);
char	*ft_strjoin_bis(char *s1, char *s2);
void	ft_free(char *s);
size_t	ft_strlen(const char *s);
int		check_line(char *s);
void	ft_parse(char **leftover, char *buf, int fd, int *ret);
int		get_next_line(int fd, char **line);

#endif
