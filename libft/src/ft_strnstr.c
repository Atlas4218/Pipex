/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:08:15 by rastie            #+#    #+#             */
/*   Updated: 2022/11/20 17:26:32 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*src;
	size_t	parcours;

	src = (char *)big;
	parcours = ft_strlen(little);
	if (!*little)
		return (src);
	if (len > parcours)
		len -= parcours - 1;
	while (*src && len--)
	{
		if (*src == *little)
			if (!ft_strncmp(src, little, parcours))
				return (src);
		src++;
	}
	return (NULL);
}
