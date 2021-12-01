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
#include "get_next_line_utils.c"

char	*get_next_line(int fd)
{
	int		read_ret;
	char	*saved[OPEN_MAX]; //the remain of the returned line
	char	buff[BUFFER_SIZE + 1];
	char	*line;
	char	*new_line_pointer;
	char	*tmp;
	
	// protections
	if (fd < 0)
		return (NULL);
	// while read_ret not EOF (0) or error (-1)
	while (read_ret = read(fd, buff, BUFFER_SIZE) > 0)
	{
		// put \0 in buffer[read_ret + 1]
		buff[read_ret + 1] = '\0';
		// verify if saved exist, if doesnt malloc
		if (!saved[fd])
			saved[fd] = malloc(sizeof(char) * BUFFER_SIZE + 1);
		// strjoin saved + buffer
		else
		{
			tmp = ft_strjoin(saved, buff);
			free(saved[fd]);
			saved[fd] = tmp;
		}
		// verify if saved have \n, if have break
		if ((new_line_pointer = ft_strchr(saved[fd], '\n')) != NULL)
			break;
	}
	//divide, before \n goes to line, after goes to saved
	//return line or error according to output_check
	return (output_check(read_ret, fd,  saved, new_line_pointer, line));
	
	
	
	
}