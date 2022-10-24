/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:05:36 by bantunes          #+#    #+#             */
/*   Updated: 2022/10/24 11:36:20 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	*bubble_sort(int *stk_array, int size)
{
	int	i;
	int	tmp;

	i = -1;
	while (++i < size - 1)
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

int	check_if_complete(t_stack *stk, int *stk_array, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = stk;
	stk_array = bubble_sort(stk_array, size);
	i = 1;
	while (i <= size)
	{
		if (stk_array[i] != tmp->content)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	the_best_way_to_r(t_stack **stk, int place, int size, char c)
{
	int		half_size;

	half_size = (size / 2);
	if (place <= half_size)
	{
		while (place != 0)
		{
			if (c == 'a')
				editstk_r(stk, "RA");
			else
				editstk_r(stk, "RB");
			place--;
		}
	}
	else
	{
		while (place < size)
		{
			if (c == 'a')
				editstk_r(stk, "RRA");
			else
				editstk_r(stk, "RRB");
			place++;
		}
	}
}

int	find_big_num_reverse(t_stack **stk, int size)
{
	t_stack	*tmp;
	int		num;
	int		i;
	int		place;

	num = -2147483648;
	tmp = *stk;
	i = size;
	while (--i > 0)
	{
		if (get_last_num(tmp, i) > num)
		{
			num = get_last_num(tmp, i);
			place = i;
		}
	}
	return (place);
}

int	find_num(t_stack **stk, int num)
{
	t_stack	*tmp;
	int		i;
	int		place;

	tmp = *stk;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->content == num)
		{
			place = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (place);
}

int	find_big_num(t_stack **stk)
{
	t_stack	*tmp;
	int		num;
	int		i;
	int		place;

	num = -2147483648;
	tmp = *stk;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->content > num)
		{
			num = tmp->content;
			place = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (place);
}

int	find_small_num(t_stack **stk)
{
	t_stack	*tmp;
	int		num;
	int		i;
	int		place;

	num = 2147483647;
	tmp = *stk;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->content < num)
		{
			num = tmp->content;
			place = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (place);
}
