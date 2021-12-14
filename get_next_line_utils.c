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

char	*output_check(int read_ret, char *saved)
{
	size_t	i;
	size_t	len_line;
	char	*line;
	char **temp;
	
	i = 0;
	len_line = ft_strchr(saved, '\n');
	line = malloc(sizeof(char) * len_line + 1);
	line[len_line + 1] = '\0';
	temp = NULL;
	
	// return for EOF or error
	if (read_ret < 0 || (read_ret == 0 && saved == NULL))
		return (0);
	else
	{
		//divide, before \n goes to line, after goes to saved
		line = ft_memcpy(line, saved, len_line);
		*temp = &saved[len_line];
		if (saved)
			free(saved);
		saved = *temp;
		if (temp)
			free(temp);	
	}
	return (line);
}

char	*ft_memcpy(char *dest, const void *src, size_t n)
{
	char	*modsrc;
	char	*moddest;

	if (!src && !dest)
		return (0);
	modsrc = (char *)src;
	moddest = (char *)dest;
	while (n--)
		*moddest++ = *modsrc++;
	//free(moddest);
	//free(modsrc);
	return (dest);
}

size_t	ft_strlen(char const *s1)
{
	size_t	i;
	
	i = 0;
	while(s1[i])
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

int	ft_strchr(const char *str, char c)
{
	int	i;
	if (!str || !c)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (i);
}
/*
int main(void)
{
	char *go = "ana";
	char *y = "krum";
	printf("%s", ft_strjoin(go, y));
}
*/
