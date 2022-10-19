/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:30 by bantunes          #+#    #+#             */
/*   Updated: 2022/10/19 12:50:56 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	*chartoint(char	**arg_a, int size)
{
	int	i;
	int	j;
	int	*num;
	int	h;

	h = 0;
	num = malloc((size + 1) * sizeof(int));
	if (!num)
	{
		ft_printf("Error\nUm dos argumentos não é aceitavel\n");
		exit(0);
	}
	else
	{
		i = 0;
		while (arg_a[++i])
		{
			j = -1;
			while (arg_a[i][++j])
			{
				if (ft_isdigit(arg_a[i][j]) == 0 &&
						(arg_a[i][j] != '-' &&
						ft_isdigit(arg_a[i][j + 1]) == 0))
				{
					write(2, "Error\nUm dos argumentos não é aceitavel\n", 40);
					free_arrays(num, 1);
				}
			}
			num[h++] = ft_atoi(arg_a[i]);
		}
	}
	num[h] = 0;
	return (num);
}

void	check_repeat(int *a_stk, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (a_stk[i] == a_stk[j])
			{
				write(2, "Error\nArgumentos repetidos\n", 27);
				free_arrays(a_stk, 1);
			}
			j++;
		}
	}
}

int	*check_string(char	**arg_a)
{
	int	size;
	int	*a_stk;
	int	i;

	i = -1;
	size = 0;
	while (arg_a[++i + 1])
		size++;
	a_stk = chartoint(arg_a, size);
	check_repeat(a_stk, size);
	return (a_stk);
}
