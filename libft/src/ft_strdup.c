/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:05:39 by rastie            #+#    #+#             */
/*   Updated: 2022/11/19 12:05:52 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*cpy;
	size_t	len;

	len = ft_strlen(src);
	cpy = malloc(sizeof(*src) * (len + 1));
	if (!(cpy))
		return (NULL);
	ft_strlcpy(cpy, src, len + 1);
	cpy[len] = '\0';
	return (cpy);
}
