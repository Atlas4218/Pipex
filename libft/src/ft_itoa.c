/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:31:24 by rastie            #+#    #+#             */
/*   Updated: 2022/12/05 16:34:39 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	nbdigitnb(long unsigned int n)
{
	int	result;

	result = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		result++;
	}
	return (result);
}

static unsigned long long int	power(int b, int p)
{
	if (p == 0)
		return (1);
	return (b * power(b, p - 1));
}

static void	ft_strrev(char *str)
{
	char	temp;
	int		i;
	int		len;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
}

char	*ft_itoa(int nb)
{
	int			nbdigit;
	int			negatif;
	int			index;
	char		*result;

	index = 0;
	negatif = (nb < 0);
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (negatif)
		nb *= -1;
	nbdigit = nbdigitnb(nb);
	result = malloc((nbdigit + negatif + 1) * sizeof (*result));
	if (negatif)
		result[index++] = '-';
	while (nb >= 10 || nbdigit - 1)
	{
		result[index++] = (nb / power(10, nbdigit - 1)) + '0';
		nb = nb % power(10, nbdigit-- - 1);
	}
	result[index++] = nb + '0';
	result[index] = '\0';
	return (result);
}

char	*ft_lutoa_base(long unsigned int nb, char *base)
{
	int			nbdigit;
	int			index;
	size_t		lenbase;
	char		*itoa;

	index = 0;
	nbdigit = nbdigitnb(nb);
	lenbase = ft_strlen(base);
	itoa = malloc((nbdigit + 1) * sizeof (*itoa));
	while (nb >= lenbase)
	{
		itoa[index++] = base[nb % lenbase];
		nb /= lenbase;
	}
	itoa[index++] = base[nb];
	itoa[index] = '\0';
	ft_strrev(itoa);
	return (itoa);
}
