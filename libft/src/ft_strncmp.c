/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:06 by rastie            #+#    #+#             */
/*   Updated: 2023/05/03 16:37:16 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!s1 && s2)
		return (1);
	if (s1 && !s2)
		return (-1);
	if (!n)
		return (0);
	n--;
	while (*str1 == *str2 && *str1 && *str2 && n > 0)
	{
		str1++;
		str2++;
		n--;
	}
	if (*str1 - *str2 > 0)
		return (1);
	if (*str1 - *str2 < 0)
		return (-1);
	return (0);
}
