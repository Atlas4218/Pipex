/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:26:17 by rastie            #+#    #+#             */
/*   Updated: 2023/06/05 09:27:41 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!s1 && s2)
		return (1);
	if (s1 && !s2)
		return (-1);
	while (*str1 == *str2 && *str1 && *str2)
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
