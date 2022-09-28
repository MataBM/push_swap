/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:30 by bantunes          #+#    #+#             */
/*   Updated: 2022/09/28 15:52:19 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	*chartoint(char	**arg_a, int size)
{
	int	i;
	int	j;
	int	*num;

	num = (int *)malloc((size) * sizeof(int));
	i = 0;
	while (arg_a[++i] != NULL)
	{
		j = -1;
		while (arg_a[i][++j] != '\0')
		{
			if (ft_isdigit(arg_a[i][j]) == 0 && (arg_a[i][j] != '-' && ft_isdigit(arg_a[i][j + 1]) == 0))
			{
				ft_printf("Error\nUm dos argumentos não é aceitavel\n");
				free(num);
				exit(0);
			}
		}
		num[i - 1] = ft_atoi(arg_a[i]);
	}
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
				ft_printf("Error\nArgumentos repetidos\n");
				free(a_stk);
				exit(0);
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
	int	h;
	int	j;
	int	*stk;

	i = -1;
	size = 0;
	while (arg_a[++i] != NULL)
		size++;
	a_stk = chartoint(arg_a, size);
	check_repeat(a_stk, size);
	stk = malloc((size) * sizeof(int));
	h = -1;
	j = -1;
	while (++h < size)
		stk[++j] = a_stk[h];
	return (stk);
}
