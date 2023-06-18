/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:36:15 by rastie            #+#    #+#             */
/*   Updated: 2023/06/17 19:46:54 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_X
# define HRDOC_PATTERN "./pipex here_doc <LIMITER> <cmd1> <cmd2> ... <outfile>"
# define PIPEX_PATTERN "./pipex <infile> <cmd1> <cmd2> ...  <outfile>"
# define FAILURE_EXEC "Error while parsing/executing cmd"
# define PIPE_ERROR "Error creating pipe"

# include "libft.h"
# include "get_next_line.h"
# include <errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

int	constr_doc(char *limiter);

#endif
