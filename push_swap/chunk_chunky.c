/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_chunky.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:40:56 by bantunes          #+#    #+#             */
/*   Updated: 2022/09/22 12:05:59 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int **fill_chunk(int **chunk, int *stk_array, int size)
{
	int	i;
	int	j;
	int	h;

	h = 0;
	i = 0;
	while (stk_array[i])
	{
		j = -1;
		while (chunk[h][++j] != NULL)
			chunk[h][j] = stk_array[i++];
		h++;
	}
	return (chunk);
}

int **create_chuncks(int *stk_array, int size)
{
	int	**chunk;
	int	i;

	i = -1;
	if (size <= 100)
		while (++i <= 5)
			chunk[i] = malloc(((5%size) + (5/size)) * sizeof(int));
	else
		while (++i <= 11)
			chunk[i] = malloc(((11%size) + (11/size)) * sizeof(int));
	fill_chunk(chunk, stk_array, size);
	return (chunk);
}