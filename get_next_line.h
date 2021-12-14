/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-r <apaula-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:52:57 by apaula-r          #+#    #+#             */
/*   Updated: 2021/12/01 18:32:29 by apaula-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd);

char	*output_check(int read_ret, char *saved);

char	*ft_memcpy(char *dest, const void *src, size_t n);

size_t	ft_strlen(char const *s1);

char	*ft_strjoin(char *s1, char const *s2);

int     ft_strchr(const char *str, char c);

#endif