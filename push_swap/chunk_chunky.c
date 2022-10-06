/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_chunky.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:40:56 by bantunes          #+#    #+#             */
/*   Updated: 2022/10/06 16:44:18 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	create_chuncks(int size)
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

int	**get_chuncks2(int *stk_array, t_div div, int chuncks, int **chunk)
{
	int	i;
	int	j;
	int	h;

	i = -1;
	h = -1;
	while (++i < div.div)
	{
		j = -1;
		chunk[i] = malloc((chuncks + 1) * sizeof(int));
		while (++j < chuncks)
		{
			chunk[i][j] = stk_array[++h];
		}
		chunk[i][j] = 0;
	}
	if (div.rest > 0)
	{
		h++;
		j = -1;
		chunk[i] = malloc((div.rest) * sizeof(int));
		while (--div.rest > 0)
			chunk[i][++j] = stk_array[++h];
	}
	return (chunk);
}

int	**get_chuncks(int *stk_array, int size)
{
	int		**chunk;
	int		chuncks;
	t_div	div;

	chuncks = create_chuncks(size);
	div.div = size / chuncks;
	div.rest = size % chuncks;
	if (div.rest == 0)
		chunk = malloc((div.div + 1) * sizeof(int *));
	else
		chunk = malloc((div.div + 2) * sizeof(int *));
	chunk = get_chuncks2(stk_array, div, chuncks, chunk);
	return (chunk);
}
