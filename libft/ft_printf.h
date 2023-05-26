/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:35:57 by rastie            #+#    #+#             */
/*   Updated: 2022/12/02 14:12:19 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define LOWER_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"
# define DEC "0123456789"
# include <stdarg.h>
# include<stddef.h>
# include<unistd.h>
# include<stdlib.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
size_t	print_uint(unsigned int arg);
size_t	print_lhex(unsigned int arg);
size_t	print_uhex(unsigned int arg);
size_t	print_addr(unsigned long int arg);
#endif
