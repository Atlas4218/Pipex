/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:17:19 by rastie            #+#    #+#             */
/*   Updated: 2023/06/17 15:54:27 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stddef.h>

int	main()
{
	char tab[10][16] = {""};
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		printf("%p", tab[i]);
		while (j < 16)
			printf("%d,\t", (int)tab[i][j++]);
		printf("\n");
		i++;
	}
	return (0);
}