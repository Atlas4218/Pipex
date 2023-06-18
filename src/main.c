/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:42:49 by rastie            #+#    #+#             */
/*   Updated: 2023/06/18 15:50:01 by rastie           ###   ########.fr       */
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

void	void_do_nothing()
{

}
int	count_arg(char **av)
{
	int	result;
	
	result = 0;
	while (av[result])
		result++;
	return (result);
}

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
	if (dup2(fdin, STDIN_FILENO))
		perror("error dup2 stdin");
	if (dup2(fdout, STDOUT_FILENO))
		perror("error dup2 stdout");
	if (!errno)
	{
		execve(av[0], av, env);
		perror(FAILURE_EXEC);
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
	dup2(infile, STDIN_FILENO);
	close(pip[0]);
	if (pid > 0)
		waitpid(pid, NULL, 0);
	if (nb && *(++av))
		return (clear_tab(cmd), funct(av, env, nb - 1, pip[1]));
	if (!nb)
		return (clear_tab(cmd), pip[1]);
	close(pip[1]);
	return (clear_tab(cmd), -1);
}

int	main(int ac, char **av, char **env)
{
	int		infilefd;
	int		outfilefd;
	int		returnpipe;
	char	buff[81];


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
		if (ac < 5)
		{
			errno = 22;
			return (perror(PIPEX_PATTERN), 22);
		}
		outfilefd = open(av[ac - 2], O_WRONLY | O_APPEND | O_CREAT | O_TRUNC);
		infilefd = open(*av, O_RDONLY);
	}
	if (outfilefd < 0)
		return (perror("outfile error"), errno);
	if (infilefd < 0)
		return (perror("infile error"), errno);
	ac = count_arg(++av);
	returnpipe = funct(av, env, ac - 2, infilefd);
	close(infilefd);
	if (returnpipe < 0)
	{
		close(outfilefd);
		return (perror("no last pipe"), -1);
	}
	while (write(outfilefd, buff, read(returnpipe, buff, 81)) > 0)
		void_do_nothing();
	close(returnpipe);
	close(outfilefd);
	return (0);
}
