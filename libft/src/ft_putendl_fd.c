/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:25:09 by rastie            #+#    #+#             */
/*   Updated: 2022/12/01 19:52:50 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	len += ft_putstr_fd(s, fd);
	len += ft_putchar_fd('\n', fd);
	return (len);
}
