/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:06:25 by rastie            #+#    #+#             */
/*   Updated: 2022/11/19 12:06:41 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	taille;

	taille = nmemb * size;
	if (taille != 0 && nmemb * size / size != nmemb)
		return (NULL);
	result = malloc(taille);
	if (result)
		ft_bzero(result, taille);
	return (result);
}
