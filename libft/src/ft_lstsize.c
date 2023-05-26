/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:52:25 by rastie            #+#    #+#             */
/*   Updated: 2022/11/21 13:54:33 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		result;
	t_list	*parcours;

	result = 0;
	parcours = lst;
	while (parcours != NULL)
	{
		result++;
		parcours = parcours->next;
	}
	return (result);
}
