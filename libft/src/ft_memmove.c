/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:15:18 by rastie            #+#    #+#             */
/*   Updated: 2022/11/19 13:07:27 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*finsrc;
	const char	*findest;

	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		finsrc = src + n - 1;
		findest = dest + n - 1;
		while (n--)
			*(unsigned char *)findest-- = *(unsigned char *)finsrc--;
	}
	return (dest);
}
