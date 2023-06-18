/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:10:25 by rastie            #+#    #+#             */
/*   Updated: 2023/06/18 17:12:05 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_read_trunc(int fd, char *buff, int size)
{
	ft_bzero(buff, size);
	return (read(fd, buff, size));
}

char	*get_next_line(int fd)
{
	static char	buff[1024][BUFFER_SIZE + 1] = {""};
	char		*temp;
	char		*result;
	int		rread;
	
	result = NULL;
	rread = BUFFER_SIZE;
	if (fd <= 2 && fd)
		return (NULL);
	result = ft_strljoin(result, buff[fd], ft_strlen(buff[fd]));
	while (((!ft_strchr(result, '\n') && rread > 0)))
	{
		temp = result;
		rread = ft_read_trunc(fd, buff[fd], BUFFER_SIZE);
		result = ft_strljoin(result, buff[fd], ft_strlen(buff[fd]));
		free(temp);
	}
	temp = result;
	result = ft_substr(result, 0, ft_strchr(result, '\n') - result + 1);
	if (ft_strchr(result, '\n'))
		ft_memmove(buff[fd], ft_strchr(result, '\n') + 1,
				ft_strlen(ft_strchr(result, '\n')));
	if (free(temp), !(*result))
		return (free(result), NULL);
	return (result);
}

