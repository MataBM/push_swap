/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:02:20 by bantunes          #+#    #+#             */
/*   Updated: 2022/10/19 17:19:29 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	five_it_is(t_stack **stk, t_stack **stk_b, int size)
{
	if (size <= 5)
	{
		the_best_way_to_r(stk, find_small_num(stk), size, 'a');
		editstk_p(stk, stk_b, 'b');
		size--;
		the_best_way_to_r(stk, find_small_num(stk), size, 'a');
		editstk_p(stk, stk_b, 'b');
		less_five(stk, stk_b, 3);
		editstk_p(stk_b, stk, 'a');
		editstk_p(stk_b, stk, 'a');
	}
}

void	less_five(t_stack **stk, t_stack **stk_b, int size)
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

int	scan_top(t_stack *stk, int **chuncks, int size, int num_chk)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		hold_first;
	int		chk;

	i = -1;
	chk = create_chuncks(size);
	tmp = stk;
	hold_first = (size / 2) + 1;
	while (++i <= (size / 2))
	{
		j = -1;
		while (++j < chk)
		{
			if (chuncks[num_chk][j] == tmp->content)
			{
				hold_first = i;
				return (hold_first);
			}
		}
			tmp = tmp->next;
	}
	return (hold_first);
}

int	get_last_num(t_stack *stk, int position)
{
	t_stack	*tmp;
	int		i;

	i = -1;
	tmp = stk;
	while (++i < position)
		tmp = tmp->next;
	return (tmp->content);
}

int	scan_bot(t_stack *stk, int **chuncks, int size, int num_chk)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		hold_second;
	int		chk;

	i = size;
	chk = create_chuncks(size);
	tmp = stk;
	hold_second = (size / 2) + 1;
	while (size-- > (i / 2))
	{
		j = -1;
		while (++j < chk)
		{
			if (chuncks[num_chk][j] == get_last_num(tmp, size))
			{
				hold_second = i - size;
				return (hold_second);
			}
		}
		// size--;
	}
	return (hold_second - 1);
}

void	do_sort(t_stack **stk, t_stack **stk_b, int **chunks, int size)
{
	t_div	div;
	int		hold_first;
	int		hold_second;
	int		i;
	int		j;
	int		b;

	div.chuncks = create_chuncks(size);
	div.div = size / div.chuncks;
	div.rest = size % div.chuncks;
	div.size_a = size;
	div.size_b = 0;
	i = -1;
	while (div.div > ++i)
	{
		j = -1;
		b = -1;
			while (++b < div.chuncks)
				// ft_printf("chunck[%d]: %d\n", i + 1, chunks[i][b]);
			while (++j < div.chuncks)
			{
				hold_first = scan_top(*stk, chunks, div.size_a, i);
				hold_second = scan_bot(*stk, chunks, div.size_a, i);
				// ft_printf("hold first: %d\nhold second: %d\n", hold_first, hold_second);
				if (hold_first <= hold_second)
					the_best_way_to_r(stk, hold_first, div.size_a, 'a');
				else
					the_best_way_to_r(stk, size - hold_second, div.size_a, 'a');
				editstk_p(stk, stk_b, 'b');
				div.size_a--;
				div.size_b++;
				// printlist(*stk);
				// printlist(*stk_b);
			}
	}
	if (div.rest > 0)
	{
		j = -1;
		while (++j < div.rest)
		{
			hold_first = scan_top(*stk, chunks, div.size_a, i);
			hold_second = scan_bot(*stk, chunks, div.size_a, i);
			if (hold_first <= hold_second)
				the_best_way_to_r(stk, hold_first, div.size_a, 'a');
			else
				the_best_way_to_r(stk, size - hold_second, div.size_a, 'a');
			editstk_p(stk, stk_b, 'b');
			div.size_a--;
			div.size_b++;
			// printlist(*stk);
			// printlist(*stk_b);
		}
	}
	// j = (div.div * div.chuncks) + div.rest;
	// while (--j > -1)
	// {
	// 	hold_first = find_big_num(stk_b);
	// 	hold_second = find_big_num_reverse(stk_b, div.size_b);
	// 	if (hold_first <= hold_second)
	// 		the_best_way_to_r(stk_b, hold_first, div.size_b, 'b');
	// 	else
	// 		the_best_way_to_r(stk_b, size - hold_second, div.size_b, 'b');
	// 	// the_best_way_to_r(stk_b, find_big_num(stk_b), div.size_b, 'b');
	// 	editstk_p(stk_b, stk, 'a');
	// 	div.size_a++;
	// 	div.size_b--;
	// 	// printlist(*stk);
	// 	// printlist(*stk_b);
	// }
}