/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:05:36 by bantunes          #+#    #+#             */
/*   Updated: 2022/09/20 15:52:29 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	*bubble_sort(int *stk_array)
{
	int	i;
	int	tmp;

	i = -1;
	while (stk_array[++i])
	{
		if (stk_array[i] > stk_array[i + 1])
		{
			tmp = stk_array[i];
			stk_array[i] = stk_array[i + 1];
			stk_array[i + 1] = tmp;
			i = -1;
		}
	}
	return (stk_array);
}

int	check_if_complete(t_list *stk, int *stk_array, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stk;
	stk_array = bubble_sort(stk_array);
	i = 1;
	while (i < size)
	{
		if (stk_array[i] != tmp->content)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	the_best_way_to_R(t_list **stk, int size, char type)
{
	int		place;
	int		half_size;
	int		i;

	i = -1;
	half_size = (size / 2 ) + 1;
	printf("metade do size: %d\n", half_size);
	if (type == 'B')
	{
		place = find_big_num(stk, size);
		if (place < half_size)
			while (--place != 0)
				editstk_r(stk, "RA", 0);
		else
			while (--place != 0)
				editstk_r(stk, "RRA", 0);
	}
	else
	{
		place = find_small_num(stk, size);
		if (place < half_size)
			while (--place != 0)
				editstk_r(stk, "RA", 0);
		else
			while (--place != 0)
				editstk_r(stk, "RRA", 0);
	}
}

int	find_big_num(t_list **stk, int size)
{
	t_list	*tmp;
	int		num;
	int		i;
	int		place;

	num = -2147483648;
	tmp = *stk;
	i = 0;
	
	while (tmp != NULL)
	{
		if ((int)tmp->content > num)
		{
			num = tmp->content;
			place = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (place);
}

int	find_small_num(t_list **stk, int size)
{
	t_list	*tmp;
	int		num;
	int		i;
	int		place;

	num = 2147483647;
	tmp = *stk;
	i = 0;
	while (tmp != NULL)
	{
		if ((int)tmp->content < num)
		{
			num = tmp->content;
			place = i;
		}
		tmp = tmp->next;
		i++;
	}
	printf("place: %d\n", place);
	return (place);
}
