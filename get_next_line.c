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
#include <fcntl.h>

char	*get_next_line(int fd)
{
	int		read_ret;
	//int		len_buff;
	static char	*saved[FD_SIZE]; //the remain of the returned line
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	
	// protections
	if (fd < 0)
		return (NULL);
	// while read_ret not EOF (0) or error (-1)
	read_ret = read(fd, buff, BUFFER_SIZE);
	while (read_ret > 0)
	{
		buff[read_ret + 1] = '\0';
		// verify if saved exist, if doesnt malloc
		if (!saved[fd])
			saved[fd] = ft_strdup(buff);
		else
		{
			// strjoin saved + buffer
			tmp = ft_strjoin(saved[fd], buff);
			free(saved[fd]);
			saved[fd] = tmp;
		}
		// verify if saved have \n, if have break
		if (ft_strchr(saved[fd], '\n') != NULL)
			break;
		read_ret = read(fd, buff, BUFFER_SIZE);
	}
	//return line or error according to output_check
	return (output_check(read_ret, saved, fd));
}

int main() {
	int fd = open("./gnlTester/files/alternate_line_nl_no_nl", O_RDONLY);
	char *line;

	while(1) {
		line = get_next_line(fd);
		if(line == NULL)
			break;
		printf("%s\n", line);
	}
}