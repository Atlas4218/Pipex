/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:42:49 by rastie            #+#    #+#             */
/*   Updated: 2023/06/17 21:06:38 by rastie           ###   ########.fr       */
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
		return (NULL);
	listpath = ft_split((*env) + 5, ':');
	temp = listpath;
	while (listpath && *listpath)
	{
		dpath = ft_strjoin(*listpath, "/");
		fpath = ft_strjoin(dpath, cmd);
		free(dpath);
		if (!access(fpath, F_OK))
			break ;
		free(fpath);
		free(*listpath++);
	}
	while (listpath && *listpath)
		free(*listpath++);
	return (free(temp), fpath);
}

char	**create_cmd(char *cmd, char **env)
{
	char **argcmd;
	char *exe;

	argcmd = ft_split(cmd, ' ');
	if (!argcmd)
		return (NULL);
	exe = get_path(env, argcmd[0]);
	free(argcmd[0]);
	argcmd[0] = exe;
	return (argcmd);
}

void	routine_child(int fdin, int fdout, char **av, char **env)
{
	dup2(fdin, STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	execve(av[0], av, env);
	perror(FAILURE_EXEC);
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
		return (tabclear(cmd), -1);
	if (!pid)
	{
		close(pip[1]);
		routine_child(infile, pip[0], cmd, env);
	}
	dup2(infile, STDIN_FILENO);
	close(pip[1]);
	if (pid > 0)
		waitpid(pid, NULL, 0);
	if (nb && *(++av))
		return (tabclear(cmd), funct(av, env, nb - 1, pip[0]));
	if (!nb)
		return (tabclear(cmd), pid[0]);
	close(pip[0]);
	return (tabclear(cmd), -1);
}

int	main(int ac, char **av, char **env)
{
	int		infilefd;
	int		outfilefd;
	int		returnpipe;
	char	buff[81];

	if (ac < 5)
	{
		errno = 22;
		return (perror(PIPEX_PATTERN), 22);
	}
	if (!ft_strncmp(*(++av), "here_doc", 9))
	{
		if (ac < 6)
		{
			errno = 22;
			return (perror(HRDOC_PATTERN), 22);
		}
		outfilefd = open(av[ac - 2], O_WRONLY | O_APPEND | O_CREAT);
		infilefd = constr_doc(*(++av));
	}
	else
	{
		outfilefd = open(av[ac - 2], O_WRONLY | O_APPEND | O_CREAT | O_TRUNC);
		infilefd = open(*av, O_RDONLY);
	}
	if (outfilefd < 0)
		return (perror("outfile error"), errno);
	if (infilefd < 0)
		return (perror("infile error"), errno);
	ac -= 4;
	returnpipe = funct(++av, env, ac - 1, infilefd);
	close(infilefd);
	while (write(outfilefd, buff, read(returnpipe, buff, 81)) > 0)
		void_do_nothing();
	close(outfilefd);
	return (0);
}
