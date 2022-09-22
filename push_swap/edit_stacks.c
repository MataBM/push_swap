/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:25:35 by bantunes          #+#    #+#             */
/*   Updated: 2022/09/22 16:27:33 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	editstk_s(t_list **stk, char c, int limit)
{
	t_list	*tmp;

	tmp = *stk;
	*stk = (*stk)->next;
	tmp->next = (*stk)->next;
	(*stk)->next = tmp;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 's' && limit != 1)
		ft_printf("ss\n");
	else
		ft_printf("sb\n");
}

void	editstk_p(t_list **stk, t_list **dst, char c)
{
	t_list	*tmp;

	tmp = *stk;
	*stk = (*stk)->next;
	ft_lstadd_front(dst, tmp);
	if (c == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	check_rotate_type(char *type, int limit)
{
	if (type[1] == 'R')
	{
		if (type[2] == 'A')
			ft_printf("rra\n");
		else if (type[2] == 'B')
			ft_printf("rrb\n");
		else
			ft_printf("rrr\n");
	}
	else
	{
		if (type[1] == 'A')
			ft_printf("ra\n");
		else if (type[1] == 'B')
			ft_printf("rb\n");
		else
			ft_printf("rr\n");
	}
}

void	editstk_r(t_list **stk, char *type, int limit)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (type[1] == 'R')
	{
		tmp = *stk;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp2 = *stk;
		while (tmp2->next->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		ft_lstadd_front(stk, tmp);
	}
	else
	{
		tmp = *stk;
		*stk = (*stk)->next;
		tmp->next = NULL;
		ft_lstadd_back(stk, tmp);
	}
	check_rotate_type(type, limit);
}
