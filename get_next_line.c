/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:10:25 by rastie            #+#    #+#             */
/*   Updated: 2023/06/13 22:03:11 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_read_trunc(int fd, char *buff, int size)
{
	bzero(buff, size);
	return (read(fd, buff, size));
}

char	*get_next_line(int fd)
{
	static char	buff[1024][BUFFER_SIZE + 1] = {0};
	char		*temp;
	char		*result;
	int		rread[1024] = {BUFFER_SIZE};
	
	result = NULL;
	if (fd <= 2 && fd)
		return (NULL);
	if (!buff[fd])
		buff[fd] = "";
	result = ft_strljoin(result, buff[fd], strlen(buff[fd]));
	while (((!strchr(result, '\n') && rread > 0)))
	{
		temp = result;
		rread[fd] = ft_read_trunc(fd, buff[fd], BUFFER_SIZE);
		result = ft_strljoin(result, buff[fd], strlen(buff));
		free(temp);
	}
	temp = result;
	result = ft_substr(result, 0, strchr(result, '\n') - result + 1);
	if (strchr(result, '\n'))
		memmove(buff[fd], strchr(result, '\n') + 1, strlen(strchr(result,
					'\n')));
	if (free(temp), !(*result))
		return (free(result), NULL);
	return (result);
}

int	main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *line = get_next_line(fd);

	ac++;
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
