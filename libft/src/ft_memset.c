/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:10:42 by rastie            #+#    #+#             */
/*   Updated: 2022/11/19 13:07:52 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*result;

	result = s;
	while (n > 0)
	{
		*(unsigned char *)s = (unsigned char)c;
		s++;
		n--;
	}
	return (result);
}
