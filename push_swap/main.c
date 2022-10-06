/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:33 by bantunes          #+#    #+#             */
/*   Updated: 2022/10/06 17:01:12 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	printlist(t_stack *stk)
{
	t_stack	*tmp;

	tmp = stk;
	while (tmp != NULL)
	{
		ft_printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	ft_addstk_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_addstk_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (lst && *lst)
	{
		tmp = *lst;
		while (tmp -> next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}

t_stack	*ft_newstk(int *content)
{
	t_stack	*elt;

	elt = (t_stack *)malloc(sizeof(*elt));
	if (!elt)
		return (NULL);
	elt->content = *content;
	elt->next = NULL;
	return (elt);
}

int	main(int arg_n, char **arg_a)
{
	int		**chunk;
	int		*stk_array;
	t_stack	*stk_a;
	t_stack	*stk_b;
	int		i;

	stk_array = NULL;
	stk_a = NULL;
	stk_b = NULL;
	i = -1;
	if (arg_n > 2)
	{
		stk_array = check_string(arg_a);
		while (stk_array[++i])
		{
			ft_addstk_back(&stk_a, ft_newstk(&stk_array[i]));
		}
	}
	else
		write(0, "ERRO\nNOT ENOUGH ARGUMENTS\n", 26);
	if (check_if_complete(stk_a, stk_array, i))
		return (0);
	if (arg_n <= 6)
		less_five(&stk_a, &stk_b, i);
	else
	{
		chunk = get_chuncks(stk_array, i);
	}
	printlist(stk_a);
	printlist(stk_b);
	free_arrays(stk_array, 0);
	free_stk(stk_a, NULL);
	return (0);
}
