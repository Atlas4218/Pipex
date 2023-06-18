/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:10:25 by rastie            #+#    #+#             */
/*   Updated: 2023/06/18 14:29:13 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE] = "";
	char		*temp;
	char		*result;
	int			rread;

	result = NULL;
	if (fd <= 2 && fd)
		return (NULL);
	rread = read(fd, buff, BUFFER_SIZE);
	while (!ft_strchr(buff, '\n') && rread == BUFFER_SIZE)
	{
		temp = result;
		result = ft_strjoin(result, buff);
		if (temp)
			free(temp);
		rread = read(fd, buff, BUFFER_SIZE);
	}
	result = ft_strjoin(result, buff);
	temp = result;
	result = ft_substr(buff, 0, ft_strchr(buff, '\n') - buff + 1);
	ft_memmove(buff, ft_strchr(buff, '\n') + 1, ft_strlen(ft_strchr(buff,
				'\n') + 1));
	return (free(temp), result);
}
