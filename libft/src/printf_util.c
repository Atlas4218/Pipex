/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:04:24 by rastie            #+#    #+#             */
/*   Updated: 2022/12/09 18:05:46 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	print_uint(unsigned int arg)
{
	char	*print;
	size_t	result;

	print = ft_lutoa_base(arg, DEC);
	result = ft_putstr_fd(print, 1);
	free(print);
	return (result);
}

size_t	print_lhex(unsigned int arg)
{
	char	*print;
	size_t	result;

	print = ft_lutoa_base(arg, LOWER_HEX);
	result = ft_putstr_fd(print, 1);
	free(print);
	return (result);
}

size_t	print_uhex(unsigned int arg)
{
	char	*print;
	size_t	result;

	print = ft_lutoa_base(arg, UPPER_HEX);
	result = ft_putstr_fd(print, 1);
	free(print);
	return (result);
}

size_t	print_addr(unsigned long int arg)
{
	size_t	result;
	char	*itoa;

	result = 0;
	if (!arg)
		return (ft_putstr_fd("(nil)", 1));
	itoa = ft_lutoa_base(arg, LOWER_HEX);
	if (!itoa)
		return (0);
	result += ft_putstr_fd("0x", 1);
	result += ft_putstr_fd(itoa, 1);
	free(itoa);
	return (result);
}
