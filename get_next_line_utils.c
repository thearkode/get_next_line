/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-r <apaula-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:54:54 by apaula-r          #+#    #+#             */
/*   Updated: 2021/12/01 18:50:01 by apaula-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*output_check(int read_ret, char *saved, char *new_line_pointer, char *line)
{
	size_t	i;
	size_t len_line;
	
	i = -1;
	len_line = saved - new_line_pointer;
	line = malloc(sizeof(char) * len_line + 1);
	line[len_line + 1] = '\0';
	
	// return for EOF or error
	if (read_ret < 0 || (read_ret == 0 && saved == NULL))
		return (0);
	else
	{
		//divide, before \n goes to line, after goes to saved
		while (*saved != *new_line_pointer)
		{
			saved[i] = line[i];
			i++;
		}
	}
	return (line);
}

size_t	ft_strlen(char const *s1)
{
	size_t	i;
	
	i = 0;
	while(s1[i++])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*concat;
	size_t	i;
	if (!s1 || !s2)
		return (NULL);
	concat = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2));
	if (!concat)
		return (NULL);
	i = 0;
	while (*s1)
		concat[i++] = *s1++;
	while (*s2)
		concat[i++] = *s2++;
	concat[i] = '\0';
	return (concat);
	
	
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;	
	}
	return (0);
}
/*
int main(void)
{
	char *go = "ana";
	char *y = "krum";
	printf("%s", ft_strjoin(go, y));
}
*/
