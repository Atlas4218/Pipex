/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:42:49 by rastie            #+#    #+#             */
/*   Updated: 2023/06/04 22:35:31 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
typedef int[2] t_pipe;

# define HRDOC_PATTERN "./pipex here_doc <LIMITER> <cmd1> <cmd2> ... <outfile>"
# define PIPEX_PATTERN "./pipex <infile> <cmd1> <cmd2> ...  <outfile>"
int	main(int ac char **av, char **env)
{
	int	infilefd;
	int	outfilefd;
	char	*remove[3];
	
	remove = {"rm", "-f", ".hrdoc"};
	if (ac < 5)
	{
		errno = 22;
		return (perror(PIPEX_PATTERN), 22);
	}
	infilefd = open(av[1], O_RDONLY);
	if (!ft_strncmp(av[1], "here_doc", 9) && infilefd < 0)
		infilefd = constructfile;
	outfilefd = open(av[ac - 1], O_WRONLY|O_APPEND);
	if (outfile < 0)
		return (perror("outfile error"), errno);
	if (infile < 0)
		return (perror("infile error"), errno);
	print_outile(funct());
	close(infile);
	if (!acces(".hrdoc"))
		excev("rm", remove,  env);
	return (0);
}
