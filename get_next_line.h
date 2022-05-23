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
# define FD_SIZE 4096

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd);

char	*output_check(int read_ret, char *saved[], int fd);

char	*ft_memcpy(void *dest, const void *src, size_t n);

char    *ft_strdup(char *src);

char	*ft_strndup(char *src, size_t len);

size_t	ft_strlen(const char *s1);

char	*ft_strjoin(const char *s1, const char *s2);

char    *ft_strchr(const char *str, char c);

#endif