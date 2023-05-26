/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:01:24 by rastie            #+#    #+#             */
/*   Updated: 2022/11/20 17:27:07 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = (char *)s;
	while (*temp != 0)
		temp++;
	if (!c)
		return (temp);
	while (temp != s)
	{
		if (*temp == (unsigned char)c)
			return (temp);
		temp--;
	}
	if (*temp == (unsigned char)c)
		return (temp);
	return (NULL);
}
