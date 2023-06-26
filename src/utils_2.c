/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:12:34 by rastie            #+#    #+#             */
/*   Updated: 2023/06/26 14:20:00 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_print_error(char *msg, int return_value)
{
	if (return_value)
		errno = return_value;
	perror(msg);
}
