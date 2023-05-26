/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:12:58 by rastie            #+#    #+#             */
/*   Updated: 2022/11/23 13:37:03 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*str;

	if (start > ft_strlen(s) || !*s || !len)
		return (ft_strdup(""));
	str = (char *)s + start;
	if (len > ft_strlen(str))
		result = malloc((ft_strlen(str) + 1) * sizeof (*result));
	else
		result = malloc((len + 1) * sizeof (*result));
	if (result)
		ft_strlcpy(result, str, len + 1);
	return (result);
}
