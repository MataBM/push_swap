/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:33 by bantunes          #+#    #+#             */
/*   Updated: 2022/09/28 15:33:05 by bantunes         ###   ########.fr       */
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
	int				**chunk;
	int				*stk_array;
	t_list			*stk_a;
	t_list			*stk_b;
	int				i;

	if (arg_n > 1)
		stk_array = check_string(arg_a);
	else
	{
		ft_putstr_fd("Error\nArgumentos insuficientes\n", 1);
		return (0);
	}
	i = -1;
	stk_a = NULL;
	stk_b = NULL;
	while (stk_array[++i] != '\0')
		ft_lstadd_back(&stk_a, ft_lstnew((void *)&stk_array[i]));
	// if (check_if_complete(stk_a, stk_array, i))
	// 	return (0);
	// //linked list quando toda negativa limpa sem motivo ainda ?
	chunk = get_chuncks(stk_array, i);
	// less_five(&stk_a, &stk_b, i);
	return (0);
}
