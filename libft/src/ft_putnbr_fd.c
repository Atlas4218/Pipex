/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:23:29 by rastie            #+#    #+#             */
/*   Updated: 2022/12/01 12:48:05 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_putnbr_fd(int n, int fd)
{
	char	*print;
	size_t	result;

	print = ft_itoa(n);
	result = ft_putstr_fd(print, fd);
	free(print);
	return (result);
}
