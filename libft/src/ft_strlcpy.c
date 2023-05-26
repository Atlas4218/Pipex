/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:43:15 by rastie            #+#    #+#             */
/*   Updated: 2022/11/19 15:15:31 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	lensrc;

	lensrc = ft_strlen(src);
	if (!size)
		return (lensrc);
	if (size <= lensrc)
	{
		ft_memmove(dst, src, size);
		dst[size - 1] = '\0';
	}
	else
	{
		ft_memmove(dst, src, lensrc);
		dst[lensrc] = '\0';
	}
	return (lensrc);
}
