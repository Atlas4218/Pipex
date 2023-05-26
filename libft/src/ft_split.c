/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:10:02 by rastie            #+#    #+#             */
/*   Updated: 2022/11/23 13:19:57 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	**calcul_malloc(char const *s, char c)
{
	char	**result;
	int		nbelement;

	nbelement = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s == c && s[-1] != c)
			nbelement++;
		s++;
	}
	if (!*s && s[-1] && s[-1] != c)
		nbelement++;
	result = malloc((nbelement + 1) * sizeof (*result));
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	char		*element;
	static int	len = 0;
	int			i;

	i = 0;
	result = calcul_malloc(s, c);
	while (*s)
	{
		while (s[len] != c && s[len])
			len++;
		element = ft_substr(s, 0, len);
		if (*element)
		{
			s = s + len;
			result[i++] = element;
		}
		else
			free(element);
		len = 0;
		if (*s)
			s++;
	}
	result[i] = NULL;
	return (result);
}
