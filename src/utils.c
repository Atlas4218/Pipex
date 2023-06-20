/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:35:45 by rastie            #+#    #+#             */
/*   Updated: 2023/06/20 16:34:46 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	clear_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	count_arg(char **av)
{
	int	result;

	result = 0;
	while (av[result])
		result++;
	return (result);
}

void	get_fd_heredoc(int *fd_io, int ac, char *limiter, char *out_name)
{
	if (ac < 6)
	{
		errno = 22;
		return (perror(HRDOC_PATTERN));
	}
	fd_io[1] = open(out_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd_io[1] < 0)
		return (perror(out_name));
	fd_io[0] = constr_doc(limiter);
	if (fd_io[0] < 0)
	{
		close(fd_io[1]);
		return (perror("Here_doc error"));
	}
}

void	get_fd_pipex(int *fd_io, int ac, char *in_name, char *out_name)
{
	if (ac < 5)
	{
		errno = 22;
		return (perror(PIPEX_PATTERN));
	}
	fd_io[1] = open(out_name, O_WRONLY | O_TRUNC | O_APPEND | O_CREAT, 0664);
	if (fd_io[1] < 0)
		return (perror(out_name));
	fd_io[0] = open(in_name, O_RDONLY);
	if (fd_io[0] < 0)
	{
		close(fd_io[1]);
		return (perror(in_name));
	}
}

void	cpy_file(int fdin, int fdout)
{
	int		rread;
	char	buff[81];

	rread = 1;
	while (rread)
	{
		rread = read(fdin, buff, 81);
		write(fdout, buff, rread);
	}
}
