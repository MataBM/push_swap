/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:26 by bantunes          #+#    #+#             */
/*   Updated: 2022/10/19 16:47:43 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_div
{
	int	size_b;
	int	size_a;
	int	div;
	int	rest;
	int	chuncks;
}	t_div;

int		*check_string(char **arg_a);

void	printlist(t_stack *stk);

void	editstk_s(t_stack **stk, char c, int limit);

void	editstk_p(t_stack **stk, t_stack **dst, char c);

void	editstk_r(t_stack **stk, char *type);

int		check_if_complete(t_stack *stk,
			int *stk_array, int size);

void	less_five(t_stack **stk, t_stack **stk_b, int size);

int		find_small_num(t_stack **stk);

int		find_big_num(t_stack **stk);

void	the_best_way_to_r(t_stack **stk, int place, int size, char c);

int		**get_chuncks(int *stk_array, int size);

int		*bubble_sort(int *stk_array, int size);

void	free_arrays(int *array, int num);

void	free_stk(t_stack *stk, void (*del)(void *));

void	ft_addstk_front(t_stack **lst, t_stack *new);

void	ft_addstk_back(t_stack **lst, t_stack *new);

void	do_sort(t_stack **stk, t_stack **stk_b, int **chunks, int size);

int		create_chuncks(int size);

int		get_last_num(t_stack *stk, int position);

int	find_big_num_reverse(t_stack **stk, int size);

#endif