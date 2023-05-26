/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:17:11 by rastie            #+#    #+#             */
/*   Updated: 2022/11/19 13:07:10 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*result;

	while (n-- && s)
	{
		if (*(unsigned char *)s == (unsigned char) c)
		{
			result = (void *)s;
			return (result);
		}
		s++;
	}
	return (NULL);
}
