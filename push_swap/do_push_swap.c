/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:02:20 by bantunes          #+#    #+#             */
/*   Updated: 2022/09/15 17:20:56 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	less_ten(t_list **stk, int stk_array, int size)
{
	if (size < 2)
		editstk_s(stk, 'a', 0);
	else if (size < 3)
	{
		size++;
	}
}
