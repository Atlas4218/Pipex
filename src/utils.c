/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:35:45 by rastie            #+#    #+#             */
/*   Updated: 2023/06/24 19:29:19 by rastie           ###   ########.fr       */
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

int	get_fd_in(int ac, char **av)
{
	if (!ft_strncmp(*(av), "here_doc", ft_strlen(*av)))
	{
		if (ac < 6)
		{
			errno = 22;
			return (perror(HRDOC_PATTERN), -1);
		}
		return (constr_doc(*(++av)));
	}
	if (ac < 5)
	{
		errno = 22;
		return (perror(PIPEX_PATTERN), -1);
	}
	return (open(*av, O_RDONLY));
}

int	get_fd_out(int ac, char **av)
{
	if (!ft_strncmp(*av, "here_doc", ft_strlen(*av)))
		return (open(av[ac - 1], O_WRONLY | O_APPEND | O_CREAT, 0644));
	return (open(av[ac -1], O_WRONLY | O_TRUNC | O_APPEND | O_CREAT, 0644));
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
