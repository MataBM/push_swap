/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_chunky.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:40:56 by bantunes          #+#    #+#             */
/*   Updated: 2022/09/28 12:55:24 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int create_chuncks(int size)
{
	int	chunks;

	if (size <= 50)
		chunks = 10;
	else if (size <= 100)
		chunks = 20;
	else if (size <= 150)
		chunks = 30;
	else if (size <= 200)
		chunks = 40;
	else if (size <= 250)
		chunks = 50;
	else if (size <= 300)
		chunks = 60;
	else if (size <= 350)
		chunks = 70;
	else if (size <= 400)
		chunks = 80;
	else if (size <= 450)
		chunks = 90;
	else
		chunks = 100;
	return (chunks);
}

int	**get_chuncks(int *stk_array, int size)
{
	int	**chunk;
	int	chuncks;
	int	div;
	int	rest;
	int	i;
	int	j;
	int	h;

	chunk = NULL;
	chuncks = create_chuncks(size);
	div = size/chuncks;
	ft_printf("div: %d\n", div);
	rest = size%chuncks;
	ft_printf("rest: %d\n", rest);
	h = -1;
	while (++h < 20)
		ft_printf("numero: %d\n", stk_array[h]);
	i = -1;
	h = -1;
	while (++i < div)
	{
		j = -1;
		chunk[i] = malloc((chuncks * sizeof(int*)) + 1);
		while (++j < chuncks)
		{
			// ft_printf("array: %d\n", stk_array[++h]);
			chunk[i][j] = stk_array[h];
			ft_printf("h: %d\n", h);
			ft_printf("numero da chunk %d -> %d\n", i, chunk[i][j]);
		}
		chunk[i][j + 1] = '\0';
	}
	if (rest > 0)
	{
		chunk[i] = malloc((rest * sizeof(int*)) + 1);
		while (rest > 0)
			chunk[i][++j] = *stk_array++;
		chunk[i][j + 1] = '\0';
	}
	return (chunk);
}
