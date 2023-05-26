/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:11:24 by rastie            #+#    #+#             */
/*   Updated: 2022/11/19 12:11:36 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		len_s1;

	if (!*set)
		return (ft_strdup(s1));
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	len_s1 = ft_strlen(s1);
	while (ft_strchr(set, s1[len_s1 - 1]) && len_s1)
		len_s1--;
	result = malloc(len_s1 + 1);
	ft_strlcpy(result, s1, len_s1 + 1);
	return (result);
}
