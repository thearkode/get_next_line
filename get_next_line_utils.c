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

char	*output_check(int read_ret, char *saved[], int fd)
{
	//size_t	i;
	size_t	len;
	char	*line;
	char	*temp;
	
	// return for EOF or error
	if (read_ret < 0 || (read_ret == 0 && !saved[fd]))
		return (NULL);

	len = 0;
	while (saved[fd][len] != '\0' && saved[fd][len] != '\n')
		len++;

	if (saved[fd][len] == '\n')
	{
		line = ft_strndup(saved[fd], len);
		temp = ft_strdup(&saved[fd][len + 1]);
		free(saved[fd]);
		saved[fd] = temp;
	}
	else
	{
		line = ft_strdup(saved[fd]);
		free(saved[fd]);
		saved[fd] = NULL;
	}

	return (line);
}

char	*ft_strdup(char *src)
{
	char *new;
	int i;

	if (!src)
		return (NULL);
	new = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (src[i] != '\0') {
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strndup(char *src, size_t len)
{
	char *new;
	int i;

	if (!src)
		return (NULL);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (src[++i] && len--)
		new[i] = src[i];
	new[i] = '\0';
	return (new);
}

char	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!src && !dest)
		return (0);
	while (n--)
		*(char *)dest++ = *(char *)src++;
	return (dest);
}

size_t	ft_strlen(const char *s1)
{
	size_t	i;
	
	i = 0;
	while(s1[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*concat;
	size_t	i;
	if (!s1 || !s2)
		return (NULL);
	concat = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!concat)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		concat[i++] = *s1++;
	while (*s2 != '\0')
		concat[i++] = *s2++;
	return (concat);	
}

char *ft_strchr(const char *str, char c)
{
	int	i;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	char *go = "ana";
	char *y = "krum";
	printf("%s", ft_strjoin(go, y));
}
*/
