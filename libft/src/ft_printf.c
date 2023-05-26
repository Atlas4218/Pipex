/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:39:51 by rastie            #+#    #+#             */
/*   Updated: 2022/12/13 17:50:33 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdarg.h>
#include "ft_printf.h"

static size_t	printarg(char *c, va_list args, int debug)
{
	void	*argptr;

	if (*c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (*c == 'd' || *c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (*c == 'u')
		return (print_uint(va_arg(args, unsigned int)));
	if (*c == 'x')
		return (print_lhex(va_arg(args, unsigned int)));
	if (*c == 'X')
		return (print_uhex(va_arg(args, unsigned int)));
	if (*c == 'p')
		return (print_addr(va_arg(args, unsigned long int)));
	if (*c == 's')
	{
		argptr = va_arg(args, void *);
		if (!argptr)
			return (ft_putstr_fd("(null)", 1));
		return (ft_putstr_fd(argptr, 1));
	}
	if (*c || debug)
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;
	int		debug;

	if (!str)
		return (-1);
	len = 0;
	debug = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			len += printarg((char *)++str, ptr, debug);
			if (!*str && !debug)
				return (-1);
			if (*str && ft_strchr("cdiuxXps%", *str))
				str++;
			else
				debug = 1;
		}
		else
			len += ft_putchar_fd(*str++, 1);
	}
	return (va_end(ptr), len);
}
