/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:53:46 by rastie            #+#    #+#             */
/*   Updated: 2023/06/14 16:21:56 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	constr_doc(char *limiter)
{
	int		file;
	char	*gnlresult;

	file = open(".hrdoc", O_RDWR | O_CREAT | O_TRUNC | O_APPEND);
	if (file < 0)
		return (-1);
	printf("pipex heredoc>");
	gnlresult = get_next_line(0);
	while (gnlresult
		&& ft_strncmp(gnlresult, limiter, ft_strlen(gnlresult) - 1))
	{
		write(file, gnlresult, ft_strlen(gnlresult));
		free(gnlresult);
		printf("pipex heredoc>");
		gnlresult = get_next_line(0);
	}
	if (*gnlresult)
		free(gnlresult);
	unlink(".hrdoc");
	return (file);
}
