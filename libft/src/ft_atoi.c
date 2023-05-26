/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:07:30 by rastie            #+#    #+#             */
/*   Updated: 2023/05/08 21:31:21 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		sign;
	int		result;

	result = 0;
	sign = 1;
	str = (char *)nptr;
	while ((*str <= '\r' && *str >= '\t') || *str == ' ')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
	}
	return (result * sign);
}

long	ft_atol(const char *nptr)
{
	char	*str;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	str = (char *)nptr;
	while ((*str <= '\r' && *str >= '\t') || *str == ' ')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
	}
	return (result * sign);
}
