/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:42:49 by rastie            #+#    #+#             */
/*   Updated: 2023/06/20 19:23:32 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env, char *cmd)
{
	char	**listpath;
	char	*dpath;
	char	*fpath;
	char	**temp;

	while (*env && ft_strncmp(*env, "PATH=", 5))
		env++;
	if (!*env)
		return (ft_strdup(cmd));
	listpath = ft_split((*env) + 5, ':');
	temp = listpath;
	fpath = NULL;
	while (listpath && *listpath)
	{
		dpath = ft_strjoin(*listpath++, "/");
		if (fpath)
			free(fpath);
		fpath = ft_strjoin(dpath, cmd);
		if (free(dpath), !access(fpath, F_OK))
			break ;
	}
	return (clear_tab(temp), fpath);
}

char	**create_cmd(char *cmd, char **env)
{
	char	**argcmd;
	char	*exe;

	argcmd = ft_split(cmd, ' ');
	if (!*argcmd)
	{
		free(argcmd);
		argcmd = malloc(2 * sizeof (*argcmd));
		argcmd[0] = ft_strdup("cat");
		argcmd[1] = NULL;
	}
	if (ft_strchr(argcmd[0], '/'))
		return (argcmd);
	exe = get_path(env, argcmd[0]);
	if (access(exe, F_OK))
		return (free(exe), argcmd);
	errno = 0;
	free(argcmd[0]);
	argcmd[0] = exe;
	return (argcmd);
}

void	routine_child(int fdin, int fdout, char **av, char **env)
{
	if (dup2(fdin, STDIN_FILENO) < 0)
		perror("error dup2 stdin");
	if (dup2(fdout, STDOUT_FILENO) < 0)
		perror("error dup2 stdout");
	if (!errno)
	{
		execve(av[0], av, env);
		perror(FAILURE_EXEC);
		clear_tab(av);
	}
	exit(errno);
}

int	funct(char **av, char **env, int nb, int infile)
{
	int		pip[2];
	pid_t	pid;
	char	**cmd;

	if (pipe(pip))
		return (perror(PIPE_ERROR), -1);
	cmd = create_cmd(*av, env);
	pid = fork();
	if (pid == -1)
		return (clear_tab(cmd), -1);
	if (!pid)
	{
		close(pip[0]);
		routine_child(infile, pip[1], cmd, env);
	}
	close(pip[1]);
	close(infile);
	if (nb && *(++av))
		return (clear_tab(cmd), funct(av, env, nb - 1, pip[0]));
	if (!nb)
		return (clear_tab(cmd), pip[0]);
	close(pip[0]);
	return (clear_tab(cmd), -1);
}

int	main(int ac, char **av, char **env)
{
	int		fd_io[2];

	if (ac < 2)
		return (perror(PIPEX_PATTERN), 22);
	av++;
	if (!ft_strncmp(*(av), "here_doc", ft_strlen(*av)))
	{
		get_fd_heredoc(fd_io, ac, av[1], av[ac - 2]);
		av++;
	}
	else
		get_fd_pipex(fd_io, ac, *av, av[ac - 2]);
	if (errno)
		return (errno);
	ac = count_arg(++av);
	dup2(funct(av, env, ac - 2, fd_io[0]), fd_io[0]);
	if (fd_io[0] < 0)
	{
		close(fd_io[1]);
		return (perror("no last pipe"), errno);
	}
	cpy_file(fd_io[0], fd_io[1]);
	close(fd_io[0]);
	close(fd_io[1]);
	return (errno);
}
