/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:53:46 by rastie            #+#    #+#             */
/*   Updated: 2023/06/28 16:30:29 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	constr_doc(char *limiter)
{
	int		file[2];
	char	*gnlresult;

	file[1] = open(".hrdoc", O_WRONLY | O_CREAT, 00777 | O_APPEND);
	if (file[1] < 0)
		return (-1);
	ft_printf("pipex heredoc>");
	gnlresult = get_next_line(0);
	while (gnlresult && ((!(ft_strlen(gnlresult) - 1) && *limiter)
			|| ft_strncmp(gnlresult, limiter, ft_strlen(gnlresult) - 1)))
	{
		write(file[1], gnlresult, ft_strlen(gnlresult));
		free(gnlresult);
		ft_printf("pipex heredoc>");
		gnlresult = get_next_line(0);
	}
	if (gnlresult && *gnlresult)
		free(gnlresult);
	write(file[1], "", 1);
	close(file[1]);
	file[0] = open(".hrdoc", O_RDONLY);
	if (file[0] < 0)
		return (-1);
	unlink(".hrdoc");
	return (file[0]);
}
