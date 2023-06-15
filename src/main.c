/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:42:49 by rastie            #+#    #+#             */
/*   Updated: 2023/06/14 16:19:34 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define HRDOC_PATTERN "./pipex here_doc <LIMITER> <cmd1> <cmd2> ... <outfile>"
#define PIPEX_PATTERN "./pipex <infile> <cmd1> <cmd2> ...  <outfile>"

int	funct(char **av, char **env, int nb, int infile)
{
	int		pip[2];
	t_pid	pid;
	char	**cmd;

	if (pipe(pip))
		return (perror(pipe), -1);
	cmd = create_cmd(*av, env);
	pid = fork;
	if (pid == -1)
		return (tabclear(cmd), -1);
	if (!pid)
	{
		close(pip[1]);
		routine_child(infile, pip[0], cmd, env);
	}
	dup2(infile, stdin);
	close(pip[1]);
	if (pid > 0)
		waitpid(pid);
	if (nb && *(++av))
		return (tabclear(cmd), funct(av, env, nb - 1, pip[0]));
	if (!nb)
		return (tabclear(cmd), pid[0]);
	close(pip[0]);
	return (tabclear(cmd), -1);
}

int	main(int ac char **av, char **env)
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
		infilefd = constructfile(*(++av));
	}
	else
	{
		outfilefd = open(av[ac - 2], O_WRONLY | O_APPEND | O_CREAT | O_TRUNC);
		infilefd = open(*av, O_RDONLY);
	}
	if (IOfd[1] < 0)
		return (perror("outfile error"), errno);
	if (IOfd[0] < 0)
		return (perror("infile error"), errno);
	if (get_descriptor(&infilefd, &outfilefd))
		return (errno);
	ac = numarg(av);
	returnpipe = funct(++av, env, ac - 1, infilefd);
	close(infilefd);
	while (write(outfilefd, buff, read(returnpipe, buff, 81)) > 0)
		void_do_nothing();
	close(outfilefd);
	return (0);
}
