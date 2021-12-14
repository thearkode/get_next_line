/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-r <apaula-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:55:00 by apaula-r          #+#    #+#             */
/*   Updated: 2021/12/01 18:52:38 by apaula-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		read_ret;
	int		len_buff;
	char	*saved[OPEN_MAX]; //the remain of the returned line
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	
	// protections
	if (fd < 0)
		return (NULL);
	read_ret = read(fd, buff, BUFFER_SIZE);
	// while read_ret not EOF (0) or error (-1)
	while (read_ret > 0)
	{
		// put \0 in buffer[read_ret + 1]
		buff[read_ret + 1] = '\0';
		// verify if saved exist, if doesnt malloc
		if (!saved[fd])
		{
			len_buff = ft_strlen(buff) + 1;
			saved[fd] = malloc(sizeof(char) * len_buff);
			saved[fd][len_buff] = '\0';
		}
		// strjoin saved + buffer
		else
		{
			tmp = ft_strjoin(saved[fd], buff);
			free(saved[fd]);
			saved[fd] = tmp;
		}
		// verify if saved have \n, if have break
		if (ft_strchr(saved[fd], '\n') == 1)
			break;
		read_ret = read(fd, buff, BUFFER_SIZE);
	}
	//divide, before \n goes to line, after goes to saved
	//return line or error according to output_check
	return (output_check(read_ret, saved[fd]));
	
	
	
	
}