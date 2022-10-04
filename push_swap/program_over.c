/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:37:12 by bantunes          #+#    #+#             */
/*   Updated: 2022/10/04 10:25:25 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	free_arrays(int *array, int num)
{
	free(array);
	if (num == 1)
		exit (0);
}

void	free_stk(t_stack *stk, void (*del)(void *))
{
	if (!stk)
		return ;
	free_stk(stk->next, NULL);
	if (del)
		del(stk->content);
	free(stk);

}
