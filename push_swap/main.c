/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:33 by bantunes          #+#    #+#             */
/*   Updated: 2022/09/13 20:41:28 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	printlist(t_list *stk)
{
	t_list	*tmp;

	tmp = stk;
	while (tmp != NULL)
	{
		ft_printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int	main(int arg_n, char **arg_a)
{
	int	*stk;
	t_list	*stk_a;
	t_list	*stk_b;
	int i;

	if (arg_n > 1)
		stk = check_string(arg_a);
	else
	{
		ft_putstr_fd("Error\nArgumentos insuficientes\n", 1);
		return (0);
	}
	i = -1;
	stk_a = NULL;
	stk_b = NULL;
	while (stk[++i] != NULL)
		ft_lstadd_back(&stk_a, ft_lstnew(stk[i]));
	printlist(stk_a);
	editstk_S(&stk_a, 'a', 0);
	printlist(stk_a);
	editstk_P(&stk_a, &stk_b, 'b');
	printlist(stk_a);
	printlist(stk_b);
	editstk_P(&stk_a, &stk_b, 'b');
	printlist(stk_a);
	printlist(stk_b);
	editstk_P(&stk_a, &stk_b, 'b');
	editstk_P(&stk_a, &stk_b, 'b');
	editstk_P(&stk_a, &stk_b, 'b');
	editstk_R(&stk_b, "RRB", 0);
	printlist(stk_a);
	printlist(stk_b);
	return (0);
}