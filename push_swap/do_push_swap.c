/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:02:20 by bantunes          #+#    #+#             */
/*   Updated: 2022/09/28 12:47:07 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	five_it_is(t_list **stk, t_list **stk_b, int size)
{
	if (size <= 5)
	{
		the_best_way_to_R(stk, find_small_num(stk), size);
		editstk_p(stk, stk_b, 'b');
		size--;
		the_best_way_to_R(stk, find_small_num(stk), size);
		editstk_p(stk, stk_b, 'b');
		less_five(stk, stk_b, 3);
		editstk_p(stk_b, stk, 'a');
		editstk_p(stk_b, stk, 'a');
	}
}

void	less_five(t_list **stk, t_list **stk_b, int size)
{
	if (size == 2)
		editstk_s(stk, 'a', 0);
	else if (size == 3)
	{
		if (find_big_num(stk) == 2 && find_small_num(stk) == 1)
			editstk_s(stk, 'a', 0);
		else if (find_big_num(stk) == 0 && find_small_num(stk) == 2)
		{
			editstk_s(stk, 'a', 0);
			editstk_r(stk, "RRA");
		}
		else if (find_big_num(stk) == 0 && find_small_num(stk) == 1)
			editstk_r(stk, "RA");
		else if (find_big_num(stk) == 1 && find_small_num(stk) == 0)
		{
			editstk_s(stk, 'a', 0);
			editstk_r(stk, "RA");
		}
		else if (find_big_num(stk) == 1 && find_small_num(stk) == 2)
			editstk_r(stk, "RRA");
	}
	else
		five_it_is(stk, stk_b, size);
}
