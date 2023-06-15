/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:11:11 by rastie            #+#    #+#             */
/*   Updated: 2023/06/15 17:38:05 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp;

	temp = (char *)s;
	while (*temp)
	{
		if (*temp == (unsigned char)c)
			return (temp);
		temp++;
	}
	if (!c)
		return (temp);
	return (NULL);
}

char	*ft_strljoin(char const *s1, char const *s2, int size)
{
	char	*result;
	int		len_s1;
	int		len_s2;

	len_s1 = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2 || !size)
		return (ft_strdup(s1));
	while (s1[len_s1])
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2])
		len_s2++;
	result = malloc(len_s1 + min(size, len_s2) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len_s1 + 1);
	ft_strlcpy(result + len_s1, s2, min(size, len_s2) + 1);
	return (result);
}

char	*ft_strdup(const char *src)
{
	char	*cpy;
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	cpy = malloc(sizeof(*src) * (len + 1));
	if (!(cpy))
		return (NULL);
	ft_strlcpy(cpy, src, len + 1);
	cpy[len] = '\0';
	return (cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*str;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (start > i || !*s || !len)
		return (ft_strdup(""));
	str = (char *)s + start;
	i = 0;
	while (str[i])
		i++;
	if (len > i)
		result = malloc((i + 1) * sizeof (*result));
	else
		result = malloc((len + 1) * sizeof (*result));
	if (result)
		ft_strlcpy(result, str, len + 1);
	return (result);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (*(src + ret))
		ret++;
	if (size && dest)
	{
		while (i < size - 1 && src[i])
		{
			*(dest + i) = *(src + i);
			i++;
		}
		*(dest + i) = '\0';
	}
	return (ret);
}
