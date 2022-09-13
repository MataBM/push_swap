/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:33 by bantunes          #+#    #+#             */
/*   Updated: 2022/09/08 15:41:14 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int main(int arg_n, char **arg_a)
{
	int	*a_stk;
	t_list *stk;
	int i;

	if (arg_n > 1)
		a_stk = check_string(arg_a);
	else
	{
		ft_putstr_fd("argumentos insuficientes\n", 1);
		return (0);
	}
	i = -1;
	stk = NULL;
	while (a_stk[++i] != NULL)
		ft_lstadd_back(&stk, ft_lstnew(a_stk[i]));
	return (0);
}